//
// Created by Simone on 18/09/2019.
//

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "parser/Parser.h"
#include "toModelica/model2Modelica.h"
#include <iostream>
#include "NoPHMLInputException.cpp"

int main(int argc, char* argv[]) {
    std::unordered_map<std::string, std::shared_ptr<Modeling::Module>> modules;
    modules.insert(std::pair("system", std::make_shared<Modeling::Module>("system")));

    int argi = 2;
    std::string filepath;
    if(argc == argi)
        filepath = argv[1];
    else if (argc < argi)
		throw NoPHMLInputException();
    else {
		std::cout << "Usage: " << argv[0] << " filename" << std::endl;
		return EXIT_FAILURE;
	}

    if (filepath.find('/'))
    	filepath = "./" + filepath;

	try {
        Parser parser(filepath);
        parser.visit_tree(parser.get_document()->get_root_node(), modules);

		std::string method;
		if (parser.method == "4th-rungekutta")
			method = "rungekutta";
		else
			method = parser.method;
		model2Modelica modelica_models(filepath, modules, parser.stopTime, method);
    } catch(const std::exception& ex) {
        std::cerr << "Exception caught: " << ex.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
