using System;

namespace LR3_CS
{
    class MyText
    {
        private int clv = 0;
        private string[] text;
        public MyText(string str1)
        {
            this.clv++;
            this.text = new string[this.clv];
            this.text[this.clv-1] = str1;
        }
        public int CLV//Свойство, которое контролирует доступ к количеству рядков в тексте
        {
            get
            {
                return this.clv;
            }
        }

        public string this[int index]//Индексатор
        {
            get
            {
                if (index >= 1 && index <= this.clv)
                    return text[index - 1];
                else
                    return null;
            }
        }
        public void addStr(string word)//Функция для добавления новой строчки
        {
            this.clv++;
            string[] str = new string[this.clv];
            for (int i = 0; i < this.clv-1; i++)
            {
                str[i] = this.text[i];
            }
            str[clv-1] = word;
            this.text = new string[this.clv];
            for(int i = 0; i < this.clv; i++)
            {
                this.text[i] = str[i];
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            MyText text = new MyText("Hello");
            text.addStr("world");
            text.addStr("I am");
            text.addStr("from");
            text.addStr("KPI");
            string str2 = text[2];
            int c = text.CLV;
        }
    }
}