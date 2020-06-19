#!/usr/bin/env python3

import os
import sys
#runnato il comando python3 -m pip install -U https://github.com/OpenModelica/OMPython/archive/master.zip

import OMPython
from OMPython import OMCSessionZMQ

#carica un file dato un path preso dagli argomenti della chiamata
omc = OMCSessionZMQ()
path = sys.argv[1]
omc.execute('loadFile("'+path+'")') # caricamento del file modelica

# className = os.path.basename(path)[:-3]
classes = omc.execute('getClassNames()')
className = classes["SET1"]["Set1"][0] # estazione del nome della classe appena caricata
print("\n#", className, "loaded.")

# Parametri e costanti:
params = {} # dizionario dei parametri e delle costanti
try:
    # print(omc.execute("getInstantiatedParametersAndValues(" + className + ")")) 
    instantiatedParams = omc.execute("getInstantiatedParametersAndValues(" + className + ")")["SET2"]["Values"][0].replace('"', '').replace(' ', '').split(",") # estrazione dei/delle parametri/costanti
    for i in range(len(instantiatedParams)): # inserimento nel dizionario di ogni valore ottenuto
        instantiatedParams[i] = instantiatedParams[i].split("=")
        params[instantiatedParams[i][0]] = instantiatedParams[i][1]
    print("- Parameters and Constants: ["+str(len(params))+"]")
    i = 0
    for key in params.keys(): # stampa del contenuto del dizionario
        print(str(i) + ")", key, "\t=", params[key])
        i+=1
except KeyError:
    pass

# Equazioni iniziali:

initialEquations = [] # lista dei parametri iniziali
initEqCount = omc.execute("getInitialEquationItemsCount("+ className +")") # estrazione del numero di equazioni iniziali
for i in range(initEqCount): # estrazione delle equazioni iniziali aggiungendole alla lista
    initialEquations.append( omc.execute("getNthInitialEquationItem(" + className + ", " + str(i+1) + ")").replace('"', '') )
print("- Initial Equations: ["+str(len(initialEquations))+"]")
for i in range(len(initialEquations)): # stampa delle equazioni iniziali
    print(str(i) + ")", initialEquations[i])

# Equazioni:
equations = [] # lista dei parametri
eqCount = omc.execute("getEquationItemsCount("+ className +")") # estrazione del numero di equazioni
for i in range(eqCount): # estrazione delle equazioni aggiungendole alla lista
    equations.append(omc.execute("getNthEquationItem(" + className + ", " + str(i+1) + ")").replace('"', '') )
print("- Equations: ["+str(len(equations))+"]")
for i in range(len(equations)): # stampa delle equazioni
    print(str(i) + ")", equations[i])