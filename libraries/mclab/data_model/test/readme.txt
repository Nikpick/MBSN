1. Eseguire lo script "generate_modelica.py" passando come input la cartella contente i modelli PHML da tradurre, e l'eseguibile di ModelsTranslator:
	'python generate_modelica.py traduzioni/ ModelsTranslator/src/cmake-build-default/src'

2. Eseguire lo script "generate_csv_from_modelica.py" per ottenere il file csv dalla simulazione del file modelica
	'python generate_csv_from_modelica.py traduzioni/'

3. Eseguire lo script "generate_csv_from_phml.py" per ottenere il file csv dalla simulazione del file phml (operazione da effettuare manualmente in quanto flint non ha un'api che consente di fare ciò; una volta eseguito il compando di seguito l'interfaccia di flint si aprirà ed andrà esportato il file csv)
	'python generate_csv_from_phml.py traduzioni/'

4. Eseguire lo script "clean_all_csv.py" per rendere compatibili i due csv ottenuti (in termini di nome delle variabili)
	'python clean_all_csv.py traduzioni/'

5. Eseguire lo script "plot_all_errors.py" per calcolare l'errore relativo di ciascun modello e stampare il plot che li raffigura
	'python plot_all_errors.py traduzioni/'