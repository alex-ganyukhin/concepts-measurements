from collections import Counter
import subprocess, time, uuid, os, re, json, logging
from typing import Any, Dict, Iterable, List


class Compiler(object):
    __name          : str
    __command       : str

    def __init__(self, json_cfg : Dict[str, Any]) -> None:
        """ Initializes compiler from the given configuration

        Args:
            json_cfg (Dict[str, Any]): Compiler configuration
        """
        self.__name          = json_cfg['name']
        self.__command       = json_cfg['run-command']

    def compile_and_measure(self, file : str, flags : str) -> Dict[str, Any]:
        """ Compiles and returns the elapsed time

        Args:
            flags (str): Compiler flags
            file (str): File to compile

        Returns:
            Dict[str, Any]: Measurement results { elapsed-time, obj-size, meaning-chars }
        """
        # prepare the command
        obj_file_name = './{}.obj-temp'.format(uuid.uuid4())
        cmd = self.__command.format(compiler_flags = flags, file_to_compile = file, obj_file = obj_file_name)

        print('Running \'{}\''.format(cmd))

        # compile + measure compilation time
        start_time = time.time()
        code = subprocess.call(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell = True, close_fds = True)
        end_time   = time.time()

        # raise if compilation is not successful
        if code != 0:
            raise RuntimeError('Compilation of \'{}\' is not successful, code: {}. Command \'{}\''.format(file, code, cmd))

        # measure source file characters
        with open(file) as fin:
            chars = sum(len(re.findall('\S', x)) for x in fin.read().splitlines(keepends = False))

        # prepare the returned data
        measurements = {
            'elapsed-time' : end_time - start_time,
            'obj-size'     : os.path.getsize(obj_file_name),
            'meaning-chars': chars
        }

        # remove the compiled temporary
        os.remove(obj_file_name)

        return measurements

    @property
    def name(self) -> str:
        """ Gets the compiler name

        Returns:
            str: Associated compiler name
        """
        return self.__name

class Build(object):
    __name     : str
    __compiler : Compiler
    __flags    : str

    def __init__(self, json_cfg : Dict[str, Any], compiler : Compiler) -> None:
        if json_cfg['compiler'] != compiler.name:
            raise RuntimeError ('Invalid compiler passed. Expected {}, got {}'.format(json_cfg['compiler'], compiler.name))
        self.__compiler = compiler

        self.__name  = json_cfg['name']
        self.__flags = json_cfg['flags']

    def compile_and_measure(self, file : str, flags : str = '') -> Dict[str, Any]:
        """ Compiles and returns the elapsed time

        Args:
            flags (str): Compiler flags (extra)
            file (str): File to compile

        Returns:
            Dict[str, Any]: Measurement results { elapsed-time, obj-size, meaning-chars }
        """
        flags_to_pass = self.__flags if not flags else '{} {}'.format(self.__flags, flags)
        return self.__compiler.compile_and_measure(file, flags_to_pass)

    @property
    def name(self) -> str:
        """ Gets the build name

        Returns:
            str: Associated build name
        """
        return self.__name

class TestDriver(object):
    __compilers     : Dict[str, Compiler]
    __builds        : Dict[str, Build]
    __sources       : List[Dict[str, Any]]
    __config        : List[Dict[str, Any]]

    def __init__(self, config_path : os.PathLike = './config.json') -> None:
        # read json config
        with open(config_path) as file:
            config_json = json.loads(file.read())

        # load compilers
        self.__compilers = {}
        for compiler_cfg in config_json['compilers']:
            compiler = Compiler(compiler_cfg)
            self.__compilers[compiler.name] = compiler

        # load builds
        self.__builds = {}
        for build_cfg in config_json['builds']:
            build = Build(build_cfg, self.__compilers[build_cfg['compiler']])
            self.__builds[build.name] = build

        # load sources
        self.__sources = config_json['sources']

        #load other config
        self.__config = config_json['config']
        if self.__config['builds_per_test'] < 1:
            raise RuntimeError('builds_per_test must be >= 1, got {}'.format(self.__config['builds_per_test']))

    def run(self) -> Iterable[Dict[str, Any]]:
        results = []

        # for every source files
        for source in self.__sources:
            # for every build
            for build_name in source['builds']:
                test_result = {
                    'source'       : source['file'],
                    'build'        : build_name,
                    'build_results': []
                }

                build = self.__builds[build_name]

                # run multiple times, sum - to calculate average values
                sum = Counter()
                for dummy in range(self.__config['builds_per_test']):
                    res = build.compile_and_measure(source['file'])
                    test_result['build_results'].append(res)
                    sum += Counter(res)

                # introduce average values
                test_result['average'] = {
                    k : v / len(test_result['build_results']) for k, v in sum.items()
                }

                # add current sub-results
                results.append(test_result)

        return {
            'results': results,
            'config': self.__config
        }

if __name__ == "__main__":
    driver = TestDriver()
    res = driver.run()
    with open('results.json', 'w+') as file:
        file.write(json.dumps(res, indent = 4))
        file.truncate()

    # also print into cout
    for result in res['results']:
        file  = result['source'][-60:]
        build = result['build']
        elaps = result['average']['elapsed-time']
        obj_s = int(result['average']['obj-size'])
        chars = int(result['average']['meaning-chars'])


        line = '{:60} {:20} {:<10.5} {:<10} {:<10}'.format(file, build, elaps, obj_s, chars)
        print(line)
