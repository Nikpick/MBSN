import os
import sys

def csv(folder):
    for model in os.listdir(folder):
        if not model.startswith('.'):
            path = folder + "/" + model
            os.chdir(path)
            bashCommand = "make"
            os.system(bashCommand)
            bashCommand = "make clean"
            os.system(bashCommand)

if __name__ == '__main__':
	csv(sys.argv[1])