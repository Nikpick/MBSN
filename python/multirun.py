#!/usr/bin/env python3

import os

os.system('chmod u+x' + ' ./singlerun.py') #concedo i permessi al file
for file in os.listdir('.'): #elenco elementi in directory
    if os.path.isfile(file): #controllo se elemento e' file
        if file.endswith('.mo'): #prendo solo i .mo
            os.system(os.getcwd() + "/" + "singlerun.py" + " ./" + file) #run singlerun con argomento l'elemento del for