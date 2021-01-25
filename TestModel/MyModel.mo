within TestModel;
model MyModel
    extends Modelica.Icons.ExamplesPackage;

    Parameters Params;
    MyClass myclass;

    equation
        myclass.a = Params.a;
        myclass.b = Params.b;
        
end MyModel;
