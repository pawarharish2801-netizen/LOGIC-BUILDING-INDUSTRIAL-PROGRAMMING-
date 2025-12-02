#include<iostream>
using namespace std;

template <class T>
T Add(T No1, T No2)
{
    T Ans;
    Ans = No1 + No2;
    return Ans;
}

int main()
{
    int iValue1 = 10, iValue2 = 11, iRet = 0;
    float fValue1 = 10.0f, fValue2 = 11.0f, fRet = 0.0f;
    double dValue1 = 10.0, dValue2 = 11.0, dRet = 0.0;

    iRet = Add(iValue1, iValue2);
    cout<<"Addition of int : "<<iRet<<"\n";

    fRet = Add(fValue1, fValue2);
    cout<<"Addition of float : "<<fRet<<"\n";

    dRet = Add(dValue1, dValue2);
    cout<<"Addition of double : "<<dRet<<"\n";
    
    return 0;
}