#!/usr/bin/env python3

# argv[1]: Directory
# argv[2]: Class Name
# argv[3]: Package Name

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
            omc.execute('loadFile("' + sys.argv[1] + "/" + file + '")') 

if(len(sys.argv) > 3): # se viene passato anche il nome del package, classname = PackageName.ClassName
    className = sys.argv[3] + '.' + sys.argv[2] 
else: # altrimenti classname = ClassName
    className = sys.argv[2]

# viene creato nella directory corrente il file xml corrispondente
omc.execute('dumpXMLDAE(' + className + ', translationLevel="backEnd", addMathMLCode=true)')


# dato il file xml lo si converte prima in dizionaio e poi in json 
# il json viene infine salvato nella dir corrente
# with open(className + '.xml') as fd:
#     myDict = xmltodict.parse(fd.read())
#     json.dump(myDict, open("out.json","w"), indent = "\t")

# rimozione del file .xml
# os.remove(className + '.xml')

# print("Modelica to json conversion:\tDone!")
print("Modelica to xml conversion:\tDone!")