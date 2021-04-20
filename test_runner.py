import subprocess
from typing import Any, Dict


class Compiler(object):
    __name    : str
    __command : str

    def __init__(self, json_cfg : Dict[str, Any]) -> None:
        """ Initializes compiler from the given configuration

        Args:
            json_cfg (Dict[str, Any]): Compiler configuration
        """
        self.__name    = json_cfg['name']
        self.__command = 'time ' + json_cfg['run-command']

    def compile(self, flags : str, file : str) -> Dict[str, Any]:
        """ Compiles and returns the elapsed time

        Args:
            flags (str): [description]
            file (str): [description]

        Returns:
            str: [description]
        """
        cmd = self.__command.format(compiler_flags = flags, file_to_compile = file)
        sub = subprocess.Popen([cmd], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        stdout, stderr =  sub.communicate()
        return {
            'real':   0,
            'user':   0,
            'system': 0
        }
