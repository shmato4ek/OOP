using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LR2_CS
{
    class Program
    {
        static void Main(string[] args)
        {
            MyStringsLib.MyStrings text1 = new MyStringsLib.MyStrings("Hello");
            MyStringsLib.MyContStrings text = new MyStringsLib.MyContStrings(text1);
            text.addStr("world", 1);
            text.addStr("!!!", 2);
            text.delStr(3);
            MyStringsLib.MyStrings symb = new MyStringsLib.MyStrings("l");
            double x = text.freq(symb);
            text.swap("Hello", "Hi");
            text.addStr("word", 2);
            text.check();
            text.cleanStr();
        }
    }
}
