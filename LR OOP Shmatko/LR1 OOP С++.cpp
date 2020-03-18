    #include <iostream>
    #include <ctime>
    using namespace std;
    void f(int, int&, int&);
    string g(int, int);
    int bit(int);
    int main()
    {
        srand(time(NULL));
         int number = 5;
        int number2 = 7;
        bool flag = true;
        int number1 = number;
        int count1 = 0;
        int num1 = bit(number);
        f(count1, number, num1);
        string max = g(number, number2);
        return 0;
    }
    int bit(int number)
    {
        int num = number;
        int t = 0;
        int d = 1;
        while (num)
        {
            t += (num % 2) * d;
            num = num / 2;
            d = d * 10;
        }
        return t;
    }
    void f(int count1, int& number, int& num1)
    {
        bool flag = true;
        int number1 = number;
        if (number <= 0)
            number = ~number;
        for (int i = 0; flag; i++)
        {
            int count = (1 << i);
            count1++;
            if ((number1 & count) != 0)
                flag = false;
        }
        for (int i = 0; i < count1; i++) {
            int count = (1 << i);
            number = number ^ count;
            num1 = bit(number);
        }
    }
    string g(int number, int number2)
    {
        for (int i = 31; i >= 0; i--)
        {
            int count = (1 << i);
            int arg1 = number & count;
            int arg2 = number2 & count;
            if ((number & (1 << 31)) != 0)
                return "Second";
            else if (arg1 != 0 && arg2 == 0)
            {
                return "First";
            }
            else if (arg1 == 0 && arg2 != 0)
            {
                return "Second";
            }
        }
        return "Any";
    }