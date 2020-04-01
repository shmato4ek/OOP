#include <iostream>
#include <math.h>

using namespace std;

class Trapeze
{
public:
    double** Point = new double* [4];
    Trapeze()
    {
        for (int i = 0; i < 4; i++)
            Point[i] = new double[2];
    }
    Trapeze(double _p11, double _p12, double _p21, double _p22, double _p31, double _p32, double _p41, double _p42)
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
    Trapeze(Trapeze& obj)
    {
        for (int i = 0; i < 4; i++)
            Point[i] = new double[2];
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 2; j++)
                this->Point[i][j] = obj.Point[i][j];
    }
    double* GetPoint(int _point)
    {
        double* _P = new double[2];
        if (_point >= 1 && _point <= 4)
        {
            _P[0] = this->Point[_point - 1][0];
            _P[1] = this->Point[_point - 1][1];
        }
        else
        {
            _P[0] = 0;
            _P[1] = 0;
        }
        return _P;
    }
    double Sqr(Trapeze obj)
    {
        double sqr;
        double A = sqrt(pow(obj.Point[3][0] - obj.Point[0][0], 2) + pow(obj.Point[3][1] - obj.Point[0][1], 2));
        double B = sqrt(pow(obj.Point[2][0] - obj.Point[1][0], 2) + pow(obj.Point[2][1] - obj.Point[1][1], 2));
        double h = obj.Point[1][1] - obj.Point[0][1];
        sqr = ((A + B) / 2) * h;
        return sqr;
    }
    double Per(Trapeze obj)
    {
        double per;
        double A = sqrt(pow(obj.Point[3][0] - obj.Point[0][0], 2) + pow(obj.Point[3][1] - obj.Point[0][1], 2));
        double B = sqrt(pow(obj.Point[2][0] - obj.Point[1][0], 2) + pow(obj.Point[2][1] - obj.Point[1][1], 2));
        double C = sqrt(pow(obj.Point[1][0] - obj.Point[0][0], 2) + pow(obj.Point[1][1] - obj.Point[0][1], 2));
        double D = sqrt(pow(obj.Point[2][0] - obj.Point[3][0], 2) + pow(obj.Point[2][1] - obj.Point[3][1], 2));
        per = A + B + C + D;
        return per;
    }
    Trapeze operator -(double num)
    {
        Trapeze obj1;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 2; j++)
                obj1.Point[i][j] = this->Point[i][j] - num;
        return obj1;
    }
    Trapeze operator *(Trapeze obj2)
    {
        Trapeze obj;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 2; j++)
                obj.Point[i][j] = this->Point[i][j] * obj2.Point[i][j];
        return obj;
    }
    void Print()
    {
        for (int i = 0; i < 4; i++)
        {
            cout << "P" << i << ": ";
            for (int j = 0; j < 2; j++)
            {
                if (j == 0)
                    cout << "(" << this->Point[i][j] << "; ";
                else
                    cout << this->Point[i][j] << ")\n";
            }
        }
        cout << endl;
    }
};

void main()
{
    Trapeze TR1;
    Trapeze TR2(1, 1, 2, 3, 3, 3, 5, 1);
    Trapeze TR3(TR2);
    TR3.Print();
    TR3 = TR3 - 3;
    TR3.Print();
    TR1 = TR2 * TR3;
    TR1.Print();
    double sqr = TR1.Sqr(TR1);
    double per = TR1.Per(TR1);
    double* A = TR1.GetPoint(1);
    double* B = TR1.GetPoint(2);
    double* C = TR1.GetPoint(3);
    double* D = TR1.GetPoint(4);
    cout << "Sqr = " << sqr << endl;
    cout << "Per = " << per << endl;
}