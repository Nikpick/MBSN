import libsbml
import os
from xml.dom import minidom
import xml.etree.ElementTree as ET


listXml = [] # lista degli xml presenti nella directory

for files in os.listdir(os.getcwd()): # elenco elementi in dir corrente
      if os.path.isfile(os.getcwd() + "/" + files): # controllo se elemento e' file
            if files.endswith('.xml'): # prendo solo gli .xml
                  listXml = listXml + [files] # mi salvo il nome del xml nella lista


for nameXml in listXml:
      fullPath = os.getcwd() + '/' + nameXml #path del file xml
      tree = ET.parse(fullPath) #albero con i primi figli del file xml
      root = tree.getroot() #radice del albero
      print(root)
      # find all "item" objects and print their "name" attribute







#expected = "1 + f(x)"
# 
#xml = "<math xmlns='http://www.w3.org/1998/Math/MathML'>"\
#      "  <apply> <plus/> <cn> 1 </cn>"\
#      "                  <apply> <ci> f </ci> <ci> x </ci> </apply>"\
#      "  </apply>"\
#      "</math>"
#
# 
#ast    = libsbml.readMathMLFromString(xml)
#result = libsbml.formulaToL3String(ast)
#
#print(result)
## if (result == expected):
##     print(result)
## else:
##     print("Mismatch after readMathMLFromString()")
#
#new_mathml = libsbml.parseL3Formula(result)
#new_string = libsbml.writeMathMLToString(new_mathml)
#
#print(new_string)
## print("Result of writing AST to string: ")
## print(new_string)