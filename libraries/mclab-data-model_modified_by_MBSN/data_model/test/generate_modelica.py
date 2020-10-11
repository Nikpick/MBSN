import os
import sys
from eliminate_all_except_phml import eliminate

def generate(folder, app):
    eliminate(folder)
    for model in os.listdir(folder):
        if not model.startswith('.'):
            path = folder + "/" + model
            os.chdir(path)
            phml = path + "/" + model + ".phml"
            bashCommand = app + phml
            os.system(bashCommand)

if __name__ == '__main__':
	generate(sys.argv[1])