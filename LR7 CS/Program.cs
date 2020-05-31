using System;

namespace LR7_CS
{
    class Nodes
    {
        public int element;
        public Nodes next, prev;
    };

    class List
    {
        public Nodes Head;
        public Nodes Tail;
        public int Count; 
        public List()
        {
            Head = Tail = null;
            Count = 0;
        }
        public void DelAll()
        {
            while (Count != 0)
                Del(1);
        }
        public void Del(int pos)
        {
            int i = 1;
            Nodes Del = Head;
            while (i < pos)
            {
                Del = Del.next;
                i++;
            }
            Nodes PrevDel = Del.prev;
            Nodes AfterDel = Del.next;
            if (PrevDel != null && Count != 1)
                PrevDel.next = AfterDel;
            if (AfterDel != null && Count != 1)
                AfterDel.prev = PrevDel;
            if (pos == 1)
                Head = AfterDel;
            if (pos == Count)
                Tail = PrevDel;
            Count--;
        }
        public void AddHead(int n)
        {
            Nodes tmp = new Nodes();
            tmp.prev = null;
            tmp.element = n;
            tmp.next = Head;
            if (Head != null)
                Head.prev = tmp;
            if (Count == 0)
                Head = Tail = tmp;
            else
                Head = tmp;
            Count++;
        }
        public void Print()
        {
            if (Count != 0)
            {
                Nodes tmp = Head;
                Console.Write("( ");
                while (tmp.next != null)
                {
                    Console.Write(tmp.element + ", ");
                    tmp = tmp.next;
                }
                Console.Write(tmp.element + " )\n\n");
            }
        }
        public int Check()
        {
            Nodes tmp = Head;
            int c = 0;
            double ammount = 0;
            double sum = 0;
            double avarage;
            while (tmp != null)
            {
                sum += tmp.element;
                ammount++;
                tmp = tmp.next;
            }
            avarage = sum / ammount;
            tmp = Head;
            while (tmp != null)
            {
                if (tmp.element < avarage)
                    c++;
                tmp = tmp.next;
            }
            return c;
        }
        public void DelBeforeMax()
        {
            Nodes tmp = Head;
            int max = tmp.element;
            int pos = 0;
            int cur = 0;
            while (tmp != null)
            {
                if (tmp.element > max)
                {
                    max = tmp.element;
                    pos = cur;
                }
                tmp = tmp.next;
                cur++;
            }
            cur = 0;
            while (cur < pos)
            {
                Del(1);
                cur++;
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            List L = new List();
            int n = 10;
            int[] a = { 2, 3, 5, 1, 9, 8, 4, 0, 6, 7 };
            for (int i = 0; i < n; i++)
                L.AddHead(a[i]);
            Console.WriteLine ("List L:\n");
            L.Print();
            int c = L.Check();
            Console.WriteLine(c + "\n");
            L.DelBeforeMax();
            L.Print();
        }
    }
}
