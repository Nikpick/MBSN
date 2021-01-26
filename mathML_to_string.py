import libsbml

def mathMLToString(mathml):
      ast    = libsbml.readMathMLFromString(mathml)
      result = libsbml.formulaToL3String(ast)

      return result


      
      #mathmlStr = """
      #           <math xmlns="http://www.w3.org/1998/Math/MathML"><piecewise><piece><cn type="integer"> 8 </cn><apply><lt/><ci> x </ci><cn type="integer"> 4 </cn></apply></piece><piece><cn> 0.1 </cn><apply><and/><apply><leq/><cn type="integer"> 4 </cn><ci> x </ci></apply><apply><lt/><ci> x </ci><cn type="integer"> 6 </cn></apply></apply></piece><otherwise><cn type="integer"> 8 </cn></otherwise></piecewise></math>
      #    """
#
      #    # evaluate the function with the values
      #print(mathmlStr)
      #print(mathml)
      #astnode = libsbml.readMathMLFromString(mathmlStr)
      #result = libsbml.formulaToL3String(astnode)
#
      #print(result)


#listXml = [] # lista degli xml presenti nella directory
#
#
#for files in os.listdir(os.getcwd()): # elenco elementi in dir corrente
#      if os.path.isfile(os.getcwd() + "/" + files): # controllo se elemento e' file
#            if files.endswith('.xml'): # prendo solo gli .xml
#                  listXml = listXml + [files] # mi salvo il nome del xml nella lista
#
#listXml2 = []

# for nameXml in listXml:
#       fullPath = os.getcwd() + '/' + nameXml #path del file xml
#       xmlDict = xmltodict(fullPath)
#       listXml2 = listXml2 + [xmlDict]


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