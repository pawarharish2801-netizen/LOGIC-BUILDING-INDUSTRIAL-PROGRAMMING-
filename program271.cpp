#include<iostream>
using namespace std;

template <class T>
T Summation(T Arr[], int iSize)
{
    int iCnt = 0;
    T iSum;

    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        iSum = iSum + Arr[iCnt];
    }

    return iSum;
}

int main()
{
    float Brr[] = {10.1f,20.2f,30.3f,40.4f,50.5f};
    float iRet = 0.0f;

    iRet = Summation(Brr,5);

    cout<<"Summation is : "<<iRet<<"\n";

    return 0;
}