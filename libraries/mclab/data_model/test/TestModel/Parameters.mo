within TestModel;
class Parameters
    extends Modelica.Icons.RecordsPackage;


    Real a(unit = "");
 
    Real b(unit = "");
 
    


    initial equation
        a = 0.0246;
        b = 0.785;
        

    equation
        der(a) = 0;
        der(b) = 0;
        

end Parameters;
