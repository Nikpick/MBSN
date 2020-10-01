#!/usr/bin/env python3

import json
import os
import sys
import xmltodict

from OMPython import OMCSessionZMQ
omc = OMCSessionZMQ()
omc.execute('loadModel(Modelica)')


for file in os.listdir(sys.argv[1]): #elenco elementi in directory
    if os.path.isfile(sys.argv[1] + "/" + file): #controllo se elemento e' file
        if file.endswith('.mo'): #prendo solo i .mo
            omc.execute('loadFile("' + file + '")') 
            print(file)  

if(len(sys.argv) > 3):
    className = sys.argv[3] + '.' + sys.argv[2]
else: 
    className = sys.argv[2]
print(className)

# omc.execute('dumpXMLDAE(' + className + ', translationLevel="backEnd", addMathMLCode=true)')
omc.execute('dumpXMLDAE("TestModel", translationLevel="backEnd", addMathMLCode=true)')

# with open(className + '.xml') as fd:
with open('TestModel' + '.xml') as fd:
    doc = json.dumps(xmltodict.parse(fd.read()))
    json.dump(doc, open("out.json","w"))
print(doc)