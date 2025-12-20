#include<iostream>
using namespace std;

void Display()
{
    static int iCnt = 1;
    
    if(iCnt <= 4)
    {
        cout<<"Jay Ganesh...\n";
        iCnt++;
        Display();
    }
}

int main()
{
    Display();

    return 0;
}