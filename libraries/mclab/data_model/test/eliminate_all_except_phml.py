import os
import sys

def eliminate(folder):
    for model in os.listdir(folder):
        if not model.startswith('.'):
            path = folder + "/" + model
            os.chdir(path)
            bashCommand = "find . ! -name \"*.phml\" -delete"
            os.system(bashCommand)

if __name__ == '__main__':
	eliminate(sys.argv[1])