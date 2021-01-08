#include <iostream>
#include <Model/Module.h>
#include <sbml/SBMLTypes.h> 

using namespace Modeling;
using namespace std;

void mathML_to_string(shared_ptr<Module> module) {
    cout << "\n#MathML to String#\n" << endl;

    auto& mathMLExprs = module->getMathMLExpression();
    int i = 1;
    for (auto mathMLExpr : mathMLExprs) {
        cout << i << ") " << mathMLExpr << "\n" <<endl;
        i++;
        // ASTNode* ast    = readMathMLFromString((mathMLExpr));
        // char*    result = SBML_formulaToL3String(ast);

        // cout << result << endl;
        // Dove mettere result???
    }

    cout << "\n#END MathML to String#\n" << endl;
}