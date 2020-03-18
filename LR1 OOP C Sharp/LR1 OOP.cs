using System;
namespace LR1
{
    class MainClass
    {
        public static string G(int number, int number2)
        {
            for (int i = 31; i >= 0; i--)          
            {
                int count = (1 << i);
                int arg1 = number & count;         
                int arg2 = number2 & count;           
                if (arg1 != 0 && arg2 == 0)         
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
        public static void F(ref int number)
        {
            bool flag = true;
            int number1 = number;
            int count1 = 0;
            for (int i = 0; flag; i++)
            {
                int count = (1 << i);
                count1++;
                if ((number1 & count) != 0)
                    flag = false;
            }
            for (int i = 0; i < count1; i++)ы
            {
                int count = (1 << i);
                number ^= count;
            }
        }
        public static void Main(string[] args)
        {
            Random randNum = new Random();
            int number = randNum.Next(1, 11);
            int number2 = randNum.Next(1, 11);
            string max;
            max = G(number, number2);
            Console.WriteLine("\n" + max + " is bigger");
            F(ref number);
        }
    }
}