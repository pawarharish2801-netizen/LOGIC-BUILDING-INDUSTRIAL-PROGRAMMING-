#include<stdio.h>

void Display(int *Arr)
{
    int iCnt = 0;

    for(iCnt = 0; iCnt < 4; iCnt++)
    {
        printf("%d\n",Arr[iCnt]);
    }
}

int main()
{
    int Brr[] = {10,20,30,40};

    Display(Brr);   // Display(100);

    return 0;
}
