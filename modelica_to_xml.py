#!/usr/bin/env python3

import os

from OMPython import OMCSessionZMQ

def modelica_to_xml(dir, className, package):
    omc = OMCSessionZMQ()
    omc.execute('loadModel(Modelica)')

    for file in os.listdir(dir): #elenco elementi in directory
        if os.path.isfile(dir + "/" + file): #controllo se elemento e' file
            if file.endswith('.mo'): #prendo solo i .mo
                omc.execute('loadFile("' + dir + "/" + file + '")') 

    if(package != ""): # se viene passato anche il nome del package, classname = PackageName.ClassName
        className = package + '.' + className 

    # viene creato nella directory corrente il file xml corrispondente
    omc.execute('dumpXMLDAE(' + className + ', translationLevel="optimiser", addMathMLCode=true)')

    print("Modelica to xml conversion:\tDone!")