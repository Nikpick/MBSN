#!/usr/bin/env python3

# argv[1]: Directory
# argv[2]: Class Name
# argv[3]: Package Name

import os
import sys

# Parsing: modelica -> xml -> json
command = 'python3 python/modelica_to_json.py'
for arg in sys.argv[1:]:
    command += ' ' + arg
# os.system("echo " + command)
os.system(command)

# Popolazione del mclab-data-model
os.system('./build/MBSN')

