#pragma once
#include <iostream>
#include <string>
using namespace std;
class Text
{
public:
    char* str;
    int length;
    Text()
    {

    }
    Text(const char* _str)
    {
        length = strlen(_str);
        this->str = new char[length + 1];
        for (int i = 0; i < length; i++)
            this->str[i] = _str[i];
        this->str[length] = '\0';
    }
    void Search()
    {
        int count = 0;
        for (int i = 0; i < strlen(str); i++)
            if (isupper(str[i]))
                count++;
        cout << "Count is " << count << endl;
    }
};