import csv
import pandas as pd
import numpy as np
import os
import re
import sys
import warnings
warnings.simplefilter("ignore")

def clean_csv(modelica_csv, flint_csv):
    tmp_flint_csv = flint_csv.split("/")
    tmp_flint_csv[-1] = "tmp_" + tmp_flint_csv[-1]
    tmp_flint_csv = "/".join(tmp_flint_csv)
    with open(flint_csv, 'r') as data_file:
        lines = data_file.readlines()
        lines[0] = lines[0].split(",")
        lines[0] = [re.sub(r' (.*)','', word) for word in lines[0]]
        lines[0] = [re.sub(r'(.*:)','', word) for word in lines[0]]
        lines[0] = ",".join(lines[0])
        with open(tmp_flint_csv, 'w') as out_data:
            for line in lines:
                out_data.write(line)
            os.rename(tmp_flint_csv, flint_csv)

    tmp_modelica_csv = modelica_csv.split("/")
    tmp_modelica_csv[-1] = "tmp_" + tmp_modelica_csv[-1]
    tmp_modelica_csv = "/".join(tmp_modelica_csv)
    modelica = pd.read_csv(modelica_csv)
    modelica.time = modelica.time.round(3)
    drop_columns = [col for col in modelica.columns if re.search(r'der\(.*\)', col)]
    keep_col = [col for col in modelica.columns if col not in drop_columns]
    csv_cleaned = modelica[keep_col]
    csv_cleaned.to_csv(modelica_csv, index=False)

    with open(modelica_csv, 'r') as data_file:
        lines = data_file.readlines()
        lines[0] = lines[0].split(",")
        lines[0] = [re.sub(r'.*\.','', word) for word in lines[0]]
        lines[0] = ",".join(lines[0])
        with open(tmp_modelica_csv, 'w') as out_data:
            for line in lines: # write updated lines
                out_data.write(line)
            os.rename(tmp_modelica_csv, modelica_csv)
    
    modelica = pd.read_csv(modelica_csv, index_col = 'time')
    flint = pd.read_csv(flint_csv, index_col = 'time')
    keep_col = flint.columns
    modelica_csv_cleaned = modelica[keep_col]
    indexes = flint.index
    modelica_csv_cleaned = modelica_csv_cleaned[~modelica_csv_cleaned.index.duplicated(keep='last')]
    modelica_csv_cleaned = modelica_csv_cleaned.loc[indexes,:]
    modelica_csv_cleaned.to_csv(modelica_csv)

if __name__ == "__main__":
	clean_csv(sys.argv[1], sys.argv[2])   