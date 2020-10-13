within TestModel;
class MyClass
    extends Modelica.Icons.VariantsPackage;


    input Real a;
    input Real b;

    Real x(unit = "") ;
 
    Real y(unit = "");

    Real z(unit="");
    
 

    initial equation
        x = 1.0;
        y = 2.0;
        


    equation
        der(x) = Functions.pow(Constants.E, x) * a*y;
        der(y) = b*x;


    algorithm
        z := x / y;
        
end MyClass;
