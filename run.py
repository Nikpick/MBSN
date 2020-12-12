#!/usr/bin/env python3

# argv[1]: Directory
# argv[2]: Class Name
# argv[3]: Package Name

import os
import sys

# Parsing: modelica -> xml -> json
command = 'python3 python/modelica_to_xml.py'
for arg in sys.argv[1:]:
    command += ' ' + arg
os.system("echo " + command)
os.system(command)

if(len(sys.argv) > 3): # se viene passato anche il nome del package, xmlFilename = PackageName.ClassName.xml
    xmlFilename = sys.argv[3] + '.' + sys.argv[2] + '.xml'
else: # altrimenti xmlFilename = ClassName.xml
    xmlFilename = sys.argv[2] + '.xml'
# Popolazione del mclab-data-model
os.system('./build/MBSN ' + xmlFilename)

# Su Windows usare "os.system('build\MBSN ' + xmlFilename)"