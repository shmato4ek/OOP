#include <iostream>

using namespace std;
 
struct Nodes
{
   int element;
   Nodes * next, * prev;
};

class List
{
   Nodes * Head, * Tail;
   int Count;
public:
    List()
    {
        Head = Tail = NULL;
        Count = 0;
    }
    ~List()
    {
        DelAll();
    }
   void DelAll()
   {
       while (Count != 0)
           Del(1);
   }
   void Del(int pos)
   {
       int i = 1;
       Nodes* Del = Head;
       while (i < pos)
       {
           Del = Del->next;
           i++;
       }
       Nodes* PrevDel = Del->prev;
       Nodes* AfterDel = Del->next;
       if (PrevDel != 0 && Count != 1)
           PrevDel->next = AfterDel;
       if (AfterDel != 0 && Count != 1)
           AfterDel->prev = PrevDel;
       if (pos == 1)
           Head = AfterDel;
       if (pos == Count)
           Tail = PrevDel;
       delete Del;
       Count--;
   }
   void AddHead(int n)
   {
       Nodes* tmp = new Nodes;
       tmp->prev = 0;
       tmp->element = n;
       tmp->next = Head;
       if (Head != 0)
           Head->prev = tmp;
       if (Count == 0)
           Head = Tail = tmp;
       else
           Head = tmp;
       Count++;
   }
   void Print()
   {
       if (Count != 0)
       {
           Nodes* tmp = Head;
           cout << "( ";
           while (tmp->next != 0)
           {
               cout << tmp->element << ", ";
               tmp = tmp->next;
           }
           cout << tmp->element << " )\n";
       }
   }
   int Check()
   {
       Nodes* tmp = Head;
       int c = 0;
       double ammount = 0;
       double sum = 0;
       double avarage;
       while (tmp != NULL)
       {
           sum += tmp->element;
           ammount++;
           tmp = tmp->next;
       }
       avarage = sum / ammount;
       tmp = Head;
       while (tmp != NULL)
       {
           if (tmp->element < avarage)
               c++;
           tmp = tmp->next;
       }
       return c;
   }
   void DelBeforeMax()
   {
       Nodes* tmp = Head;
       int max = tmp->element;
       int pos = 0;
       int cur = 0;
       while (tmp!=NULL)
       {
           if (tmp->element>max)
           {
               max = tmp->element;
               pos = cur;
           }
           tmp = tmp->next;
           cur++;
       }
       cur = 0;
       while (cur < pos)
       {
           Del(1);
           cur++;
       }
   }
};
void main()
{
    List L;
    const int n = 10;
    int a[n] = { 2, 3, 5, 1, 9, 8, 4, 0, 6, 7 };
    for (int i = 0; i < n; i++)
        L.AddHead(a[i]);
    cout << "List L:\n";
    L.Print();
    int c = L.Check();
    cout << endl << c << endl << endl;
    L.DelBeforeMax();
    L.Print();
}