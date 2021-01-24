#include "mathML_to_string.h"
#include <sbml/SBMLTypes.h> 


using namespace Modeling;
using namespace std;

void mathML_to_string(shared_ptr<Module> module) {
	cout << "\n#MathML to String#\n" << endl;

	auto& mathMLExprs = module->getMathMLExpression();
	int i = 1;

	for (auto mathMLExpr : mathMLExprs) {
		cout << i << ") " << mathMLExpr << "\n" << endl;
		i++;
		//const char* c = mathMLExpr.c_str();

		/*const char* c = "<?xml version='1.0' encoding='UTF-8'?>"  //Lo stesso contenuto che proviene da mathMLExpr.c_str()
			"<math xmlns='http://www.w3.org/1998/Math/MathML'>"
			"<apply>"
			"<apply>"
			"<ci> Params </ci>"
			"</apply>"
			"<cn type = 'real'> 0.0 </cn>"
			"</apply>"
			"</math>";*/

		const char* expected = "1 + f(x)";  //Risultato del MathML che segue per confronto risultati

		const char* s = "<?xml version='1.0' encoding='UTF-8'?>"  //Contenuto di prova funzionante
			"<math xmlns='http://www.w3.org/1998/Math/MathML'>"
			"  <apply> <plus/> <cn> 1 </cn>"
			"                  <apply> <ci> f </ci> <ci> x </ci> </apply>"
			"  </apply>"
			"</math>";

		ASTNode* ast = readMathMLFromString(s);
		char* result = SBML_formulaToL3String(ast);

		cout << result << endl;

		if (strcmp(result, expected) == 0)
			std::cout << "Got expected result\n\n" << std::endl;
		else
			std::cout << "Mismatch after readMathMLFromString()\n\n" << std::endl;

		ASTNode* new_mathml = SBML_parseL3Formula(result);
		char* new_s = writeMathMLToString(new_mathml);

		cout << new_s << "\n" << endl;
		//cout << c << endl;
		// Dove mettere result???
	}

	cout << "\n#END MathML to String#\n" << endl;
}