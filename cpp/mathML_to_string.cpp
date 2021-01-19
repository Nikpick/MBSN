#include "mathML_to_string.h"
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
        const char* c = mathMLExpr.c_str();
        ASTNode* ast    = readMathMLFromString(c);
        char*    result = SBML_formulaToL3String(ast);

        cout << result << endl;
        // Dove mettere result???
        }

    cout << "\n#END MathML to String#\n" << endl;
    }