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

omc.execute('dumpXMLDAE(TestModel.MyModel, translationLevel="backEnd")')

with open('TestModel.MyModel.xml') as fd:
    doc = xmltodict.parse(fd.read())
print(doc)