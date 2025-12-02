#include<iostream>
using namespace std;

int Add(int No1, int No2)
{
    int Ans;
    Ans = No1 + No2;
    return Ans;
}

int main()
{
    int iValue1 = 10, iValue2 = 11, iRet = 0;

    iRet = Add(iValue1, iValue2);

    cout<<iRet;

    return 0;
}