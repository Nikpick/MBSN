
import libsbml

expected = "1 + f(x)"
 
xml = "<?xml version='1.0' encoding='UTF-8'?>"\
       "<math xmlns='http://www.w3.org/1998/Math/MathML'>"\
       "  <apply> <plus/> <cn> 1 </cn>"\
       "                  <apply> <ci> f </ci> <ci> x </ci> </apply>"\
       "  </apply>"\
       "</math>"


xml1 = "<?xml version='1.0' encoding='UTF-8'?>"\
      "<math xmlns=\"http://www.w3.org/1998/Math/MathML\">"\
      "  <apply>"\
      "    <equivalent/>"\
            "    <apply>"\
            "      <diff/>"\
            "      <ci> myclass.x "\
            "      </ci>"\
            "    </apply>"\
                                    "    <apply>"\
                                    "      <times/>"\
                                    "      <ci> $cse1 "\
                                    "      </ci>"\
                                    "      <apply>"\
                                    "        <times/>"\
                                    "        <ci> Params.a "\
                                    "        </ci>"\
                                    "        <ci> myclass.y "\
                                    "        </ci>"\
                                    "      </apply>"\
                                    "    </apply>"\
      "  </apply>"\
      "</math>"
      

 
ast    = libsbml.readMathMLFromString(xml1)
result = libsbml.formulaToL3String(ast)

print(result)
# if (result == expected):
#     print(result)
# else:
#     print("Mismatch after readMathMLFromString()")

new_mathml = libsbml.parseL3Formula(result)
new_string = libsbml.writeMathMLToString(new_mathml)

print(new_string)
# print("Result of writing AST to string: ")
# print(new_string)