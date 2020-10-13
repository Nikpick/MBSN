import pandas as pd
import sys
import warnings
warnings.simplefilter("ignore")

def compute_error(modelica_csv, flint_csv):
    modelica_df = pd.read_csv(modelica_csv, index_col = 'time')
    flint_df = pd.read_csv(flint_csv, index_col = 'time')
    error = ((abs(modelica_df - flint_df) / abs(flint_df).max()).median()).mean() # avg_{i in [1,n]} { avg_{j in [1,T]}  [ abs( modelica[i,j] - flint[i,j] ) ] / max_{j in [1,T]} abs(flint[i,j])  }
    # error = ((abs(modelica_df - flint_df)).sum() / flint_df.sum()).mean() # avg_{i in [1,n]}  [ sum_{j in [1,T]}   abs( modelica[i,j] - flint[i,j] ) ] / (sum_{j in [1,T]} flint[i,j])
    # error = (((abs(modelica_df - flint_df)) / ((abs(modelica_df) + abs(flint_df)) / 2)).sum()).mean()
    # print(error)
    # error = (((abs(modelica_df - flint_df)).sum() / ((abs(modelica_df) + abs(flint_df)) / 2)).sum()).mean()
    # error = (abs((flint_df - modelica_df) / flint_df)).sum().median()
    return error

if __name__ == '__main__':
    compute_error(sys.argv[1], sys.argv[2])