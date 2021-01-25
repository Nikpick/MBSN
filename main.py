#!/usr/bin/env python3

# argv[1]: Directory
# argv[2]: Class Name
# argv[3]: Package Name

import sys
import xmltodict
from modelica_to_xml import modelica_to_xml
import os

def main():
    dir = sys.argv[1] #nome directory
    className = sys.argv[2] #nome classe
    if(len(sys.argv) > 3): #se si ha un terzo argomento allora = nome package
        package = sys.argv[3] 
    else: package = ""
    modelica_to_xml(dir, className, package)



    # dato il file xml lo si converte prima in dizionaio e poi in json 
    # il json viene infine salvato nella dir corrente
    # with open(className + '.xml') as fd:
    #     myDict = xmltodict.parse(fd.read())
    #     json.dump(myDict, open("out.json","w"), indent = "\t")

    # rimozione del file .xml
    # os.remove(className + '.xml')

    # print("Modelica to json conversion:\tDone!")


main()