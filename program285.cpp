#include<iostream>
using namespace std;

void Display()
{
    int iCnt = 0;       // auto storage class
    cout<<"Jay Ganesh..."<<iCnt<<"\n";
    iCnt++;
    Display();
}

int main()
{
    Display();

    return 0;
}