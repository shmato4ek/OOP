#include <iostream>
#include <math.h>
#include <string>

using namespace std;

class STR
{
public:
    char *str;
    int length = 0;
    STR()
    {

    }
    STR(const char* _str)
    {
        length = strlen(_str);
        this->str = new char[length + 1];
        for (int i = 0; i < length; i++)
            this->str[i] = _str[i];
        this->str[length] = '\0';
    }
    virtual int Len()
    {
        return this->length;
    }
    virtual void Decrease(int _n)
    {
        int len = this->length - _n;
        char *s = new char[len+1];
        for (int i = 0; i < len; i++)
            s[i] = this->str[i];
        s[len] = '\0';
        this->str = s;
    }
};

class Symbols : STR
{
private:
    STR* str1;
public:
    Symbols()
    {

    }
    Symbols(const char* _str)
    {
        this->length = strlen(_str);
        this->str = new char[this->length + 1];
        for (int i = 0; i < this->length; i++)
            this->str[i] = _str[i];
        this->str[this->length] = '\0';
    }
    int Len()
    {
        return this->length;
    }
    void Decrease(int _n)
    {
        if (_n % 2 == 1)
        {
            char* s = new char[this->length];
            int i = 0;
            for (; i < _n - 1; i++)
                s[i] = this->str[i];
            for (; i < length - 1; i++)
                s[i] = this->str[i + 1];
            s[length-1] = '\0';
            this->str = s;
            this->length--;
        }
    }
};

class Numbers : STR
{
private:
    STR* str2;
public:
    Numbers()
    {

    }
    Numbers(const char* _str)
    {
            this->length = strlen(_str);
            this->str = new char[this->length + 1];
            for (int i = 0; i < this->length; i++)
                this->str[i] = _str[i];
            this->str[this->length] = '\0';
    }
    int Len()
    {
        return this->length;
    }
    void Decrease(int _n)
    {
        if (_n % 2 == 0)
        {
            char* s = new char[this->length];
            int i = 0;
            for (; i < _n - 1; i++)
                s[i] = this->str[i];
            for (; i < length - 1; i++)
                s[i] = this->str[i + 1];
            s[length-1] = '\0';
            this->str = s;
            this->length--;
        }
    }
};
 void main()
{
    Symbols symbols("HelloWorld");
    int length1 = symbols.Len();
    symbols.Decrease(3);
    length1 = symbols.Len();
    Numbers numbers("3228");
    int length2 = numbers.Len();
    numbers.Decrease(4);
    length2 = numbers.Len();
}
