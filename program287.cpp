#include<iostream>
using namespace std;

void Display()
{
    static int iCnt = 0;       // static storage class
    cout<<"Jay Ganesh..."<<iCnt<<"\n";
    iCnt++;
    Display();
}

int main()
{
    Display();

    return 0;
}