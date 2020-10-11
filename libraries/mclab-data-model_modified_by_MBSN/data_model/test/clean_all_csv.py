from clean_csv import clean_csv
import os
import sys
import glob
import warnings
warnings.simplefilter("ignore")

def clean_all_csv(folder):
    for model in os.listdir(folder):
        if not model.startswith('.'):
            path = folder + "/" + model
            extension = 'csv'
            os.chdir(path)
            flint_csv = path + "/out_flint.csv"
            result = glob.glob('*.{}'.format(extension))
            modelica_csv = path + "/" + [csv_file for csv_file in result if csv_file != "out_flint.csv"][0]
            print(model)
            clean_csv(modelica_csv, flint_csv)

if __name__ == '__main__':
	clean_all_csv(sys.argv[1])