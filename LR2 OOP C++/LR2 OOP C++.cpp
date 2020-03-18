#include "MyStrings.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");

    MyContStrings text;
    text.text[0] = "Hello";
    cout << endl;
    text.Print();
    cout << endl;
    text.addStr("world", 1);
    text.addStr("!!!", 2);
    cout << "* * 1 * *" << endl;
    text.Print();
    cout << "* * 2 * *" << endl;
    cout << endl;
    text.delStr(3);
    text.Print();
    cout << "* * 3 * *" << endl;
    cout << endl;
    float x = text.freq('l');
    cout << x;
    cout << endl << endl;
    cout << "* * 4 * *" << endl;
    text.swap("Hello", "Hi");
    text.Print();
    cout << endl << endl;
    cout << "* * 5 * *" << endl;
    text.addStr("world",2);
    text.Print();
    cout << endl << endl;
    text.check();
    text.Print();
    cout << endl << endl;
    text.cleanStr();
    cout << "* * 7 * *" << endl;
    text.Print();
    cout << "* * 00 * *" << endl;
    cout << endl;

    return 0;
}