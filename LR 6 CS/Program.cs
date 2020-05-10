using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class Equation
{
    private double a;
    private double b;
    private double c;
    private double d;
    public Equation ()
    {

    }
    public Equation(double  _a, double _b, double _c, double _d)
    {
        a = _a;
        b = _b;
        c = _c;
        d = _d;
    }
    public void Result ()
    {
        try
        {
            double res;
            res = (4 * Math.Log(a / b) + 1) / (c + b - d + a);
            Console.WriteLine("X = " + res);
        }
        catch (DivideByZeroException)
        {
            Console.WriteLine("It was DivideByZeroException");
        }
        catch (ArithmeticException)
        {
            Console.WriteLine("It was ArithmeticException");
        }
    }
    public void Change (string s, double _p)
    {
        if (s == "a")
            this.a = _p;
        if (s == "b")
            this.b = _p;
        if (s == "c")
            this.c = _p;
        if (s == "d")
            this.d = _p;
    }
    public double Info (string s)
    {
        if (s == "a")
            return this.a;
        if (s == "b")
            return this.b;
        if (s == "c")
            return this.c;
        if (s == "d")
            return this.d;
        else
            return 0;
    }
}

namespace LR_6_CS
{
    class Program
    {
        static void Main(string[] args)
        {
            Equation[] E = new Equation[3];
            E[0] = new Equation(2, 0, 5, 1);
            E[1] = new Equation(1, 2, 3, 6);
            E[2] = new Equation(5, 4, 4, 2);
            E[0].Change("d", 2);
            double a = E[1].Info("a");
            E[0].Result();
            E[1].Result();
            E[2].Result();
        }
    }
}
