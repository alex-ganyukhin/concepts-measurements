# About
Small script, which allows to benchmark c++ code in order to measure:
* Compilation time
* Size of the resulting object file
* Size of the code (number of non-whitespace characters)

# How to run
1. Basing on config_example.json create your own configuration, name it config.json
2. Put config.json at the same level with test_runner.py
3. `python test_runner.py`
4. See the summary results in the STDOUT and check results.json for the detailed results
