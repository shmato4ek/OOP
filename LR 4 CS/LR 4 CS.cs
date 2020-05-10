using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LR_4_CS
{
    class Trapeze
    {
        private double[,] Point = new double [4,2];
        public Trapeze ()
        {

        }
        public Trapeze(double _p11, double _p12, double _p21, double _p22, double _p31, double _p32, double _p41, double _p42)
        {
            Point[0,0] = _p11;
            Point[0,1] = _p12;
            Point[1,0] = _p21;
            Point[1,1] = _p22;
            Point[2,0] = _p31;
            Point[2,1] = _p32;
            Point[3,0] = _p41;
            Point[3,1] = _p42;
        }
        public Trapeze(Trapeze obj)
        {
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 2; j++)
                    this.Point[i,j] = obj.Point[i,j];
        }
        public double[] GetPoint(int _point)
        {
            double[] _P = new double[2];
            if (_point >= 1 && _point <= 4)
            {
                _P[0] = this.Point[_point - 1, 0];
                _P[1] = this.Point[_point - 1, 1];
            }
            else
            {
                _P[0] = 0;
                _P[1] = 0;
            }
            return _P;
        }
        public double Sqr (Trapeze obj)
        {
            double sqr;
            double A = Math.Sqrt(Math.Pow(obj.Point[3, 0] - obj.Point[0, 0], 2.0) + Math.Pow(obj.Point[3, 1] - obj.Point[0, 1], 2.0));
            double B = Math.Sqrt(Math.Pow(obj.Point[2, 0] - obj.Point[1, 0], 2.0) + Math.Pow(obj.Point[2, 1] - obj.Point[1, 1], 2.0));
            double h = obj.Point[1, 1] - obj.Point[0, 1];
            sqr = ((A + B) / 2) * h;
            return sqr;
        }
        public double Per(Trapeze obj)
        {
            double per;
            double A = Math.Sqrt(Math.Pow(obj.Point[3, 0] - obj.Point[0, 0], 2.0) + Math.Pow(obj.Point[3, 1] - obj.Point[0, 1], 2.0));
            double B = Math.Sqrt(Math.Pow(obj.Point[2, 0] - obj.Point[1, 0], 2.0) + Math.Pow(obj.Point[2, 1] - obj.Point[1, 1], 2.0));
            double C = Math.Sqrt(Math.Pow(obj.Point[1, 0] - obj.Point[0, 0], 2.0) + Math.Pow(obj.Point[1, 1] - obj.Point[0, 1], 2.0));
            double D = Math.Sqrt(Math.Pow(obj.Point[2, 0] - obj.Point[3, 0], 2.0) + Math.Pow(obj.Point[2, 1] - obj.Point[3, 1], 2.0));
            per = A + B + C + D;
            return per;
        }
        public static Trapeze operator -(Trapeze obj, double num)
        {
            Trapeze obj1 = new Trapeze();
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 2; j++)
                    obj1.Point[i, j] = obj.Point[i,j] - num;
            return obj1;
        }
        public static Trapeze operator *(Trapeze obj1, Trapeze obj2)
        {
            Trapeze obj = new Trapeze();
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 2; j++)
                    obj.Point[i, j] = obj1.Point[i, j] * obj2.Point[i, j];
            return obj;
        }
        public void Print ()
        {
            for (int i = 0; i < 4; i++)
            {
                Console.WriteLine("P" + i + ": ");
                for (int j = 0; j < 2; j++)
                {
                    if (j == 0)
                        Console.WriteLine("(" + this.Point[i, j] + "; ");
                    else
                        Console.WriteLine(this.Point[i,j] + ")\n");
                }
            }
        }
    }

    
    class Program
    {
        static void Main(string[] args)
        {
            Trapeze TR1 = new Trapeze();
            Trapeze TR2 = new Trapeze(1,1,2,3,3,3,5,1);
            Trapeze TR3 = new Trapeze(TR2);
            TR3.Print();
            TR3 = TR3 - 3;
            TR3.Print();
            TR1 = TR2 * TR3;
            TR1.Print();
            double sqr = TR1.Sqr(TR1);
            double per = TR1.Per(TR1);
            double[] A = TR1.GetPoint(1);
            double[] B = TR1.GetPoint(2);
            double[] C = TR1.GetPoint(3);
            double[] D = TR1.GetPoint(4);
        }
    }
}
