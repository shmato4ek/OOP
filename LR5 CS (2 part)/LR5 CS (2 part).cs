using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LR5_CS__2_part_
{
    class STR
    {
        public string str;
        public int length = 0;
        public STR()
        {

        }
        public STR(string _str)
        {
            this.str = _str;
            this.length = _str.Length;
        }
        public virtual int Len()
        {
            return this.length;
        }
        public virtual void Decrease(int _n)
        {
            char[] S = this.str.ToCharArray();
            char symb = S[_n - 1];
            string s = this.str.TrimStart(symb);
            this.length--;
            this.str = s;
        }
    }

    class Symbols : STR
    {
        STR str1;
        public Symbols()
        {

        }
        public Symbols(string _str)
        {
            str1 = new STR(_str);
            this.str = _str;
        }
        public override int Len()
        {
            return this.str1.length;
        }
        public override void Decrease(int _n)
        {
            if (_n%2==1)
            {
                string s = this.str.Remove(_n, 1);
                this.str = s;
                this.str1.length--;
            }
        }
    }

    class Numbers : STR
    {
        STR str2 = new STR();
        public Numbers()
        {

        }
        public Numbers(string _str)
        {
            int Num;
            bool isNum = int.TryParse(_str, out Num);
            if (isNum)
            {
                str2 = new STR(_str);
                this.str = _str;
            }
            else
                this.str = null;
        }
        public override int Len()
        {
            return str2.length;
        }
        public override void Decrease(int _n)
        {
            if (_n%2==0)
            {
                string s = this.str.Remove(_n-1, 1);
                this.str = s;
                this.str2.length--;
            }
        }
    }
    
    class Program
    {
        static void Main(string[] args)
        {
            Symbols symbols = new Symbols("HelloWorld");
            int length1 = symbols.Len();
            symbols.Decrease(3);
            length1 = symbols.Len();
            Numbers numbers = new Numbers("3228");
            int length2 = numbers.Len();
            numbers.Decrease(4);
            length2 = numbers.Len();
        }
    }
}
