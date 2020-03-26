#include "MyStrings.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");

    MyContStrings text1;
    text1.text[0] = "Hello";
    cout << endl;
    text1.Print();
    cout << endl;
    text1.addStr("world", 1);
    text1.addStr("!!!", 2);
    cout << "* * 1 * *" << endl;
    text1.Print();
    cout << "* * 2 * *" << endl;
    cout << endl;
    text1.delStr(3);
    text1.Print();
    cout << "* * 3 * *" << endl;
    cout << endl;
    float x = text1.freq('l');
    cout << x;
    cout << endl << endl;
    cout << "* * 4 * *" << endl;
    text1.swap("world", "everyone");
    text1.Print();
    cout << endl << endl;
    cout << "* * 5 * *" << endl;
    text1.addStr("world",2);
    text1.Print();
    cout << endl << endl;
    text1.check();
    text1.Print();
    cout << endl << endl;
    text1.cleanStr();
    cout << "* * 7 * *" << endl;
    text1.Print();
    cout << "* * 00 * *" << endl;
    cout << endl;

    return 0;
}