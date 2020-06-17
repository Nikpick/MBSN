import os
import sys
import OMPython
from OMPython import OMCSessionZMQ

#carica un file dato un path preso dagli argomenti della chiamata
omc = OMCSessionZMQ()
path = sys.argv[1]
omc.execute('loadFile("'+path+'")')

# className = os.path.basename(path)[:-3]
classes = omc.execute('getClassNames()')
className = classes["SET1"]["Set1"][0]
print("\n-", className, "loaded.")

# Parametri
params = {}
instantiatedParams = omc.execute("getInstantiatedParametersAndValues(" + className + ")")["SET2"]["Values"][0].replace('"', '').replace(' ', '').split(",")
for i in range(len(instantiatedParams)):
    instantiatedParams[i] = instantiatedParams[i].split("=")
    params[instantiatedParams[i][0]] = instantiatedParams[i][1]
print("- Parameters: ["+str(len(params))+"]")
i = 0
for key in params.keys():
    print("\t" + str(i) + ")", key, "\t=", params[key])
    i+=1

# Variabili
variables = {}

print("- Variables: ["+str(len(variables))+"]")

# Equazioni iniziali
initialEquations = []
initEqCount = omc.execute("getInitialEquationItemsCount("+ className +")")
for i in range(initEqCount):
    initialEquations.append( omc.execute("getNthInitialEquationItem(" + className + ", " + str(i+1) + ")") )
print("- Initial Equations: ["+str(len(initialEquations))+"]")
for i in range(len(initialEquations)):
    print("\t" + str(i) + ")", initialEquations[i])

#Equazioni
equations = []
eqCount = omc.execute("getEquationItemsCount("+ className +")")
for i in range(eqCount):
    equations.append( omc.execute("getNthEquationItem(" + className + ", " + str(i+1) + ")") )
print("- Equations: ["+str(len(equations))+"]")
for i in range(len(equations)):
    print("\t" + str(i) + ")", equations[i])
