#!/usr/bin/env python3

# argv[1]: Directory
# argv[2]: Class Name
# argv[3]: Package Name

import sys
import xmltodict
from modelica_to_xml import modelica_to_xml
import os
from xmlParser import parser

def main():
    dir = sys.argv[1] #nome directory
    className = sys.argv[2] #nome classe
    if(len(sys.argv) > 3): #se si ha un terzo argomento allora = nome package
        package = sys.argv[3] 
    else: package = ""
    
    # modelica_to_xml(dir, className, package)
    
    if(package != ""): 
        xmlPath = "./" + package + "." + className + ".xml" #salviamo il path del file xml
    else: xmlPath = "./" + className + ".xml"    

    parser(xmlPath) #passiamo a parser il path salvato

    # rimozione del file .xml
    # os.remove(xmlPath)


main()