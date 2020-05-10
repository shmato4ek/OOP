#include <iostream>
#include <math.h>

using namespace std;

class Figure
{
public:
    double** Point = new double* [4];
    Figure()
    {
        for (int i = 0; i < 4; i++)
            Point[i] = new double[2];
    }
    Figure (double _p11, double _p12, double _p21, double _p22, double _p31, double _p32, double _p41, double _p42)
    {
        for (int i = 0; i < 4; i++)
            Point[i] = new double[2];
        Point[0][0] = _p11;
        Point[0][1] = _p12;
        Point[1][0] = _p21;
        Point[1][1] = _p22;
        Point[2][0] = _p31;
        Point[2][1] = _p32;
        Point[3][0] = _p41;
        Point[3][1] = _p42;
    }
    virtual double Len(int s, int e)
    {
        double len = sqrt(pow(Point[e - 1, 0] - Point[s - 1, 0], 2) + pow(Point[e - 1, 1] - Point[s - 1, 1], 2));
        return len;
    }
    virtual double* Cords(int _pos)
    {
        double* cords = new double[2];
        cords[0] = Point[_pos - 1][ 0];
        cords[1] = Point[_pos - 1][ 1];
        return cords;
    }
};

class Romb : Figure
{
public:
    Romb()
    {

    }

    Romb(double _p11, double _p12, double _p21, double _p22, double _p31, double _p32, double _p41, double _p42)
    {
        Point[0][0] = _p11;
        Point[0][1] = _p12;
        Point[1][0] = _p21;
        Point[1][1] = _p22;
        Point[2][0] = _p31;
        Point[2][1] = _p32;
        Point[3][0] = _p41;
        Point[3][1] = _p42;
    }
    double Sqr(Romb obj)
    {
        double sqr;
        double A = sqrt(pow(obj.Point[3][0] - obj.Point[0][0], 2) + pow(obj.Point[3][1] - obj.Point[0][1], 2));
        double B = sqrt(pow(obj.Point[2][0] - obj.Point[1][0], 2) + pow(obj.Point[2][1] - obj.Point[1][1], 2));
        double h = obj.Point[1][1] - obj.Point[0][1];
        sqr = ((A + B) / 2) * h;
        return sqr;
    }
    double Per(Romb obj)
    {
        double per;
        double A = sqrt(pow(obj.Point[3][0] - obj.Point[0][0], 2) + pow(obj.Point[3][1] - obj.Point[0][1], 2));
        double B = sqrt(pow(obj.Point[2][0] - obj.Point[1][0], 2) + pow(obj.Point[2][1] - obj.Point[1][1], 2));
        double C = sqrt(pow(obj.Point[1][0] - obj.Point[0][0], 2) + pow(obj.Point[1][1] - obj.Point[0][1], 2));
        double D = sqrt(pow(obj.Point[2][0] - obj.Point[3][0], 2) + pow(obj.Point[2][1] - obj.Point[3][1], 2));
        per = A + B + C + D;
        return per;
    }
    double Len(int s, int e)
    {
        double len = sqrt(pow(Point[e - 1, 0] - Point[s - 1, 0], 2) + pow(Point[e - 1, 1] - Point[s - 1, 1], 2));
        return len;
    }
    double* Cords(int _pos)
    {
        double* cords = new double[2];
        cords[0] = Point[_pos - 1][0];
        cords[1] = Point[_pos - 1][1];
        return cords;
    }
};

void main()
{
    Romb R(-1, -3, 1, 2, 3, -3, 1, -8);
    double* P1 = R.Cords(1);
    double* P2 = R.Cords(2);
    double* P3 = R.Cords(3);
    double* P4 = R.Cords(4);
    double A = R.Len(1, 2);
    double per = R.Per(R);
    double sqr = R.Sqr(R);
}