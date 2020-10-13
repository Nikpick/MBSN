import os
import sys

def csv(folder):
    for model in os.listdir(folder):
        if not model.startswith('.'):
            path = folder + "/" + model
            os.chdir(path)
            phml = path + "/" + model + ".phml"
            bashCommand = "/Applications/Flint.app/Contents/MacOS/flint \"" + phml + "\""
            os.system(bashCommand)

if __name__ == '__main__':
	csv(sys.argv[1])