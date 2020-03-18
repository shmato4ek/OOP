#include "MyStrings.h"
using namespace std;

int MyStrings::myStrlen(const char* str) {
    int lenth = 0;
    while (*str) {
        lenth++;
        str++;
    }
    return lenth;
}

MyStrings::MyStrings() {
    str = nullptr;
    lenth = 0;  
}
MyStrings::MyStrings(const char* string) {
    lenth = myStrlen(string);
    this->str = new char[lenth + 1];
    for (int i = 0; i < lenth; i++)
        this->str[i] = string[i];
    this->str[lenth] = '\0';
}
MyStrings::MyStrings(const MyStrings& value) {
    lenth = myStrlen(value.str);    
    this->str = new char[lenth + 1];
    for (int i = 0; i < lenth; i++)
        this->str[i] = value.str[i];
    this->str[lenth] = '\0';
}
MyStrings::MyStrings(MyStrings&& value) {
    this->lenth = value.lenth;
    this->str = value.str;
    value.str = nullptr;
}

MyStrings::~MyStrings() {
    delete[] this->str;
}



MyStrings& MyStrings::operator =(const MyStrings& other) {
    if (this != nullptr) delete[] str;
    lenth = myStrlen(other.str);
    this->str = new char[lenth + 1];
    for (int i = 0; i < lenth; i++)
        this->str[i] = other.str[i];
    this->str[lenth] = '\0';
    return *this;
}

MyStrings MyStrings::operator+(const MyStrings& other) {
    MyStrings newString;
    newString.lenth = myStrlen(this->str) + myStrlen(other.str);
    newString.str = new char[myStrlen(this->str) + myStrlen(other.str) + 1];
    int i;
    for (i = 0; i < myStrlen(this->str); i++)
        newString.str[i] = this->str[i];
    for (int j = 0; j < myStrlen(other.str); j++, i++)
        newString.str[i] = other.str[j];
    newString.str[myStrlen(this->str) + myStrlen(other.str)] = '\0';
    return newString;
}

bool MyStrings::operator ==(const MyStrings& other) 
{
    if (this->lenth == other.lenth) {
        for (int i = 0; i < this->lenth; i++) {
            if (this->str[i] != other.str[i]) return false;
        }
        return true;
    }
    return false;
}

bool MyStrings::operator !=(const MyStrings& other) {
    return !(this->operator==(other));
}

char& MyStrings::operator [](int num) {
    return this->str[num];
}

std::ostream& operator <<(std::ostream& out, const MyStrings& other)
{
    return out << other.str;
}



MyContStrings::MyContStrings() {
    this->clv++;
    this->text = new MyStrings[this->clv];
}
MyContStrings::MyContStrings(const MyStrings* string) {
    this->text = new MyStrings[this->clv];
    for (int i = 0; i < this->clv; i++)
        this->text[i] = string[i];
}
MyContStrings::MyContStrings(const MyContStrings& value) {
    this->text = new MyStrings[this->clv];
    for (int i = 0; i < this->clv; i++)
        this->text[i] = value.text[i];
}
MyContStrings::MyContStrings(MyContStrings&& value) {
    this->text = value.text;
    this->clv = value.clv;
    value.text = nullptr;
}
MyContStrings::~MyContStrings() {
    delete[] this->text;
}
void MyContStrings::Print() {
    for (int i = 0; i < this->clv; i++)
        cout << this->text[i] << endl;
}


MyContStrings& MyContStrings::addStr(MyStrings str1, int position) {
    MyContStrings newContainer;
    this->clv++;
    newContainer.text = new MyStrings[this->clv];
    for (int i = 0; i < this->clv; i++) {
        if (i == position) newContainer.text[position] = str1;
        else if (i < position) newContainer.text[i] = this->text[i];
        else if (i > position) newContainer.text[i] = this->text[i - 1];
    }
    this->text = new MyStrings[this->clv];
    for (int i = 0; i < this->clv; i++) {
        this->text[i] = newContainer.text[i];
    }
    return *this;
}

MyContStrings& MyContStrings::delStr(int position) {
    MyContStrings newContainer;
    if (clv != 1) {
        newContainer.text = new MyStrings[this->clv - 1];
        for (int i = 0; i < this->clv - 1; i++) {
            if (i < position-1) newContainer.text[i] = this->text[i];
            else newContainer.text[i] = this->text[i + 1];
        }
        this->clv--;
        *(this->text) = *(newContainer.text);
        return *this;
    }
    else this->cleanStr();
}

MyContStrings& MyContStrings::cleanStr() {
    MyContStrings newContainer;
    newContainer.text = new MyStrings[1];
    newContainer.text[0] = "";
    this->clv = 0;
    *(this->text) = *(newContainer.text);
    return *this;
}

float MyContStrings::freq(char ch) {
    if (clv > 0) {
        float counter = 0,
            sum = 0;
        for (int i = 0; i < this->clv; i++) {
            for (int j = 0; j < text[i].lenth; j++) {
                if (text[i][j] == ch) counter++;
            }
            sum += text[i].lenth;
        }
        return counter / sum;
    }
    else return 0;
}

MyContStrings& MyContStrings::swap(MyStrings word1, MyStrings word2)
{
    int cur = 0;
    bool flag = true;
    for (int l = 0; l <2; l++) {
        for (int j = 0; j < text[l].lenth; j++)
        {
            if (text[l][j] == word1[0]) {
                for (int k = j, i = 0; k < word1.lenth; k++, i++)
                {
                    if (text[l][j] != word1[i])
                        flag = true;
                }
                if (flag)
                    cur = l;
            }
        }
    }
    if (flag) {
        this->delStr(cur);
        this->addStr(word2, cur);
    }
    return *this;
}

MyContStrings& MyContStrings::check()
{
    int cur = 0;
    bool flag = false;
    for (int l = 1; l < 3; l++)
    {
        for (int i = 0; i < text[l].lenth; i++)
        {
            if (text[l][i] == text[l - 1][i])
            {
                flag = true;
            }
        }
        if (flag)
            cur = l;
    }
    this->delStr(cur);
    return *this;
}