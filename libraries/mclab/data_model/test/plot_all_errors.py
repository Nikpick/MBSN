from compute_error import compute_error
import matplotlib.pyplot as plt
import numpy as np
import os
import sys
import glob
import warnings
warnings.simplefilter("ignore")

def plot_all_errors(folder):
    errors = []
    labels = []
    for i, model in enumerate(os.listdir(folder)):
        if not model.startswith('.'):
            path = folder + "/" + model
            extension = 'csv'
            os.chdir(path)
            flint_csv = path + "/out_flint.csv"
            result = glob.glob('*.{}'.format(extension))
            modelica_csv = path + "/" + [csv_file for csv_file in result if csv_file != "out_flint.csv"][0]
            labels.append(modelica_csv.split("/")[-2])
            errors.append(compute_error(modelica_csv, flint_csv))
    fig, axis = plt.subplots(figsize=(10,8))
    axis.scatter(labels, errors)
    axis.grid(True)
    plt.xticks(rotation='vertical')
    plt.tight_layout()
    plt.show()

if __name__ == '__main__':
    plot_all_errors(sys.argv[1])