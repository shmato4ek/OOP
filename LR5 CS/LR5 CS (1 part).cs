using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LR5_CS
{
    class Figure
    {
        protected double[,] Point = new double[4, 2];
        public Figure ()
        {

        }
        public Figure (double _p11, double _p12, double _p21, double _p22, double _p31, double _p32, double _p41, double _p42)
        {
            Point[0, 0] = _p11;
            Point[0, 1] = _p12;
            Point[1, 0] = _p21;
            Point[1, 1] = _p22;
            Point[2, 0] = _p31;
            Point[2, 1] = _p32;
            Point[3, 0] = _p41;
            Point[3, 1] = _p42;
        }
        public double Len (int s, int e)
        {
            double len = Math.Sqrt(Math.Pow(Point[e - 1, 0] - Point[s - 1, 0], 2) + Math.Pow(Point[e - 1, 1] - Point[s - 1, 1], 2));
            return len;
        }
        public double[] Cords (int _pos)
        {
            double[] cords = new double[2];
            cords[0] = Point[_pos - 1, 0];
            cords[1] = Point[_pos - 1, 1];
            return cords;
        }
    }

    class Romb : Figure
    {
        public Romb()
        {

        }

        public Romb(double _p11, double _p12, double _p21, double _p22, double _p31, double _p32, double _p41, double _p42)
        {
            Point[0, 0] = _p11;
            Point[0, 1] = _p12;
            Point[1, 0] = _p21;
            Point[1, 1] = _p22;
            Point[2, 0] = _p31;
            Point[2, 1] = _p32;
            Point[3, 0] = _p41;
            Point[3, 1] = _p42;
        }
        public double Sqr(Romb obj)
        {
            double sqr;
            double A = Math.Sqrt(Math.Pow(obj.Point[3, 0] - obj.Point[0, 0], 2.0) + Math.Pow(obj.Point[3, 1] - obj.Point[0, 1], 2.0));
            double B = Math.Sqrt(Math.Pow(obj.Point[2, 0] - obj.Point[1, 0], 2.0) + Math.Pow(obj.Point[2, 1] - obj.Point[1, 1], 2.0));
            double h = obj.Point[1, 1] - obj.Point[0, 1];
            sqr = ((A + B) / 2) * h;
            return sqr;
        }
        public double Per(Romb obj)
        {
            double per;
            double A = Math.Sqrt(Math.Pow(obj.Point[3, 0] - obj.Point[0, 0], 2.0) + Math.Pow(obj.Point[3, 1] - obj.Point[0, 1], 2.0));
            double B = Math.Sqrt(Math.Pow(obj.Point[2, 0] - obj.Point[1, 0], 2.0) + Math.Pow(obj.Point[2, 1] - obj.Point[1, 1], 2.0));
            double C = Math.Sqrt(Math.Pow(obj.Point[1, 0] - obj.Point[0, 0], 2.0) + Math.Pow(obj.Point[1, 1] - obj.Point[0, 1], 2.0));
            double D = Math.Sqrt(Math.Pow(obj.Point[2, 0] - obj.Point[3, 0], 2.0) + Math.Pow(obj.Point[2, 1] - obj.Point[3, 1], 2.0));
            per = A + B + C + D;
            return per;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Romb obj = new Romb(-1, -3, 1, 2, 3, -3, 1, -8);
            double[] P1 = obj.Cords(1);
            double[] P2 = obj.Cords(2);
            double[] P3 = obj.Cords(3);
            double[] P4 = obj.Cords(4);
            double per = obj.Per(obj);
            double sqr = obj.Sqr(obj);
            double lenth = obj.Len(1, 2);
        }
    }
}
