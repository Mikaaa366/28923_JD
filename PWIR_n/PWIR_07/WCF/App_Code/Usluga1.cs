using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.Text;

// NOTE: You can use the "Rename" command on the "Refactor" menu to change the class name "Usluga1" in code, svc and config file together.
public class Usluga1 : IUsluga1
{
    public int Dodawanie(int a, int b)
    {
        return a + b;
    }

    public int Mnozenie(int a, int b)
    {
        return a * b;
    }
}
