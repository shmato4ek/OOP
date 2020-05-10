#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

ofstream fout("logs.txt");

class Equation
{
private: 
        double a;
        double b;
        double c;
        double d;
public:
    Equation()
    {

    }
    Equation(double _a, double _b, double _c, double _d)
    {
        this->a = _a;
        this->b = _b;
        this->c = _c;
        this->d = _d;
    }
    double Result()
    {
        double res;
        if (this->b == 0 || this->a + this->b + this->c - this->d == 0)
        {
            throw logic_error ("You can`t divide by null!!!");
        }
        else if (this->a / this->b <= 0)
        {
            throw underflow_error ("Logariphm must be > 0!!!");
        }
        return (4 * log(a / b) + 1) / (c + b - d + a);
    }
    void Change(string s, double _p)
    {
        if (s == "a")
            this->a = _p;
        if (s == "b")
            this->b = _p;
        if (s == "c")
            this->c = _p;
        if (s == "d")
            this->d = _p;
    }
    double Info(string s)
    {
        if (s == "a")
            return this->a;
        if (s == "b")
            return this->b;
        if (s == "c")
            return this->c;
        if (s == "d")
            return this->d;
        else
            return 0;
    }
};

void main()
{
    Equation* E = new Equation[4];
    E[0] = Equation(2, 0, 5, 1);
    E[1] = Equation(1, 2, 3, 6);
    E[2] = Equation(-1, 2, 3, 6);
    E[3] = Equation(5, 4, 4, 2);
    E[0].Change("d", 2);
    double a = E[1].Info("a");
    for (int i = 0; i < 4; i++)
    {
        try
        {
            cout << E[i].Result() << endl;
        }
        catch (logic_error except)
        {
            fout << except.what() << endl;
        }
        catch (underflow_error except)
        {
            fout << except.what() << endl;
        }
        catch (exception)
        {
            fout << "Something was going wrong!!!" << endl;
        }
    }
}