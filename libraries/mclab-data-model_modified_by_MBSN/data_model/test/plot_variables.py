import pandas as pd
import matplotlib.pyplot as plt
import sys

def plot_variables(modelica_csv, flint_csv):
    modelica_df = pd.read_csv(modelica_csv, index_col = 'time')
    flint_df = pd.read_csv(flint_csv, index_col = 'time')
    fig = plt.figure(figsize=(16,12))
    for i, variable in enumerate(flint_df.columns):
        axis = fig.add_subplot(4,4,i+1)
        axis.plot(flint_df.index.values, flint_df[variable], 'r')
        axis.plot(modelica_df.index.values, modelica_df[variable], 'g')
        axis.set_title(variable)
        axis.grid(True)
        ylabel = 'value of ' + variable
        axis.set_xlabel('time')
        axis.set_ylabel(ylabel)
    plt.gca().legend(('flint','modelica'), loc='upper left', bbox_to_anchor=(0.5, -0.2))
    plt.tight_layout()
    plt.subplots_adjust(hspace=.5)
    plt.show()

if __name__ == '__main__':
    plot_variables(sys.argv[1], sys.argv[2])