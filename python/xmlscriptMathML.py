#!/usr/bin/env python3

import os
import sys
import xmltodict

from OMPython import OMCSessionZMQ
omc = OMCSessionZMQ()
omc.execute('loadModel(Modelica)')

for file in os.listdir('.'): #elenco elementi in directory
    if os.path.isfile(file): #controllo se elemento e' file
        if file.endswith('.mo'): #prendo solo i .mo
            omc.execute('loadFile("' + file + '")')   

if(len(sys.argv) > 2):
    className = sys.argv[2] + '.' + sys.argv[1]
else: 
    className = sys.argv[1]

omc.execute('dumpXMLDAE(' + className + ', translationLevel="backEnd", addMathMLCode=true)')

with open(className + '.xml') as fd:
    doc = xmltodict.parse(fd.read())
print(doc)