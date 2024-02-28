#include"Date.h"
void Test1()
{
    Date d0(2024,2,28);
    Date d1(d0);
    Date d3(d0);
    d1+=2;
    d1.Print();
    d1++;
    d1.Print();
    d3 = d0 + 1000;
    d3.Print();
    cout << d3 - d0<< endl;
}
int main()
{
    Test1();
}