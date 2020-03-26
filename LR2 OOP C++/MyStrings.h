#pragma once
#include <iostream>

class MyStrings {
public:
    char* str;
    int lenth;
    int myStrlen(const char*);
    MyStrings();
    MyStrings(const char*);
    MyStrings(const MyStrings&);
    ~MyStrings();

    MyStrings& operator =(const MyStrings&);
    char& operator [](int);
    friend std::ostream& operator <<(std::ostream&, const MyStrings&);
};

class MyContStrings : public MyStrings {

public:
    MyStrings* text;
    int clv = 0;

    MyContStrings();
    MyContStrings(const MyStrings*);
    MyContStrings(const MyContStrings&);
    ~MyContStrings();
    void Print();

    MyContStrings& addStr(MyStrings, int);
    MyContStrings& delStr(int pos);
    MyContStrings& cleanStr();
    MyContStrings& swap(MyStrings, MyStrings);
    MyContStrings& check();
    float freq(char);
};

std::ostream& operator <<(std::ostream& out, const MyStrings& other);