
import xmltodict
from mathML_to_string import mathMLToString
# parser("./TestModel.MyModel.xml")

testing = False

#_Ordered Variables______________________________________________________________________________________________________________________________________________________________


def setOrdVar(var):
    mathMLString = xmltodict.unparse(var["attributesValues"]["unit"]["MathML"])
    
        
# funzione per cercare la parte MathML dopo aver trovato i tipi delle variabili
def setOrderedVariables(orderedVariables): 
    if testing: print("ordVars")
    
    # itera sulle variabili contenute nella lista orderedVariables["variablesList"]["variable"], con le specifiche della variabile come elementi di una lista
    for var in orderedVariables["variablesList"]["variable"]: 
        setOrdVar(var)
    

#__Alias Variables_____________________________________________________________________________________________________________________________________________________________


def setAliasVar(var):
    # print(var)
    print()

# funzione per cercare la parte MathML dopo aver trovato i tipi delle variabili
def setAliasVariables(aliasVariables): 
    if testing: print("aliasVars")

    for var in aliasVariables["variablesList"]["variable"]: # 
        setAliasVar(var)


#_Variables - Equations - Functions______________________________________________________________________________________________________________________________________________________________


# funzione per recuperare i tipi delle variabili
def setVariables(variables): 
    if testing: print("a")
    if testing: 
        print(variables.keys())
    if('orderedVariables' in variables):
        setOrderedVariables(variables["orderedVariables"])
    if('aliasVariables' in variables):
        setAliasVariables(variables["aliasVariables"])

# funzione per recuperare le equazioni
def setEquations(equations): 
    if testing: print("b.1")
    # for eq in equations["equation"]:
    #     mathMLString = xmltodict.unparse(eq["MathML"])
    #     print(mathMLString)
    #     print(mathMLToString(mathMLString))
    #     print('\n')

# funzione per recuperare le equazioni iniziali
def setInitialEquations(initialEquations): 
    if testing: print("b.2")
    for eq in initialEquations["equation"]:
        mathMLString = xmltodict.unparse(eq["MathML"]).replace('<?xml version="1.0" encoding="utf-8"?>', "")
        # mathMLString = mathMLString.replace("Params.", "")
        # mathMLString = mathMLString.replace("myclass.", "")
        print(mathMLString)
        print(mathMLToString(mathMLString))
        print('\n')
    
# funzione per recuperare le funzioni
def setFunctions(functions): 
    if testing: print("c")


#_Parser_____________________________________________________________________________________________________________________________________________________________


def parser(filePath):
    with open(filePath) as fd:
        xmlDict = xmltodict.parse(fd.read()) # mettiamo tutti i valori dell'xml a mo' di dizionario
        # print(xmlDict)
        # print('\n')
    for key in xmlDict["dae"]: # controllo i figli del dae e li ciclo con le funzioni
        if(key == "variables"): 
            setVariables(xmlDict["dae"][key])
        elif(key == "equations"): 
            setEquations(xmlDict["dae"][key])
        elif(key == "initialEquations"): 
            setInitialEquations(xmlDict["dae"][key])
        elif(key == "functions"): 
            setFunctions(xmlDict["dae"][key])
