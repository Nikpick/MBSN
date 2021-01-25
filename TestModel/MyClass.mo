within TestModel;
class MyClass
    extends Modelica.Icons.VariantsPackage;


    input Real a;
    input Real b;

    Real x(unit = "") ;
 
    Real y(unit = "");
    
 

    initial equation
        x = 1.0;
        y = 2.0;
        


    equation
        der(x) = a*y;
        der(y) = b*x;

        
end MyClass;
