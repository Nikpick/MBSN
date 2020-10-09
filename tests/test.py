import xmltodict

with open('TestModel.MyModel.xml') as fd:
    doc = xmltodict.parse(fd.read())
    print(doc["dae"]["variables"]["aliasVariables"])