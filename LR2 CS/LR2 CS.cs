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
            MyStringsLib.MyContStrings text = new MyStringsLib.MyContStrings();
            text.addStr("Hello", 0);
            text.addStr("World", 1);
            text.addStr("!!!", 2);
            text.delStr(3);
            double x = text.freq('l');
            text.swap("Hello", "Hi");
            text.addStr("word", 2);
            text.check();
            text.cleanStr();
        }
    }
}
