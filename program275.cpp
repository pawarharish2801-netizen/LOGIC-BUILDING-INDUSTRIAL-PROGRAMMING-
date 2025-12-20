#include<iostream>
using namespace std;

template <class T, class W>
void Display(T no1, W no2)
{
    cout<<no1<<"\n";
    cout<<no2<<"\n";
}

int main()
{
    int A = 11;
    double B = 90.9987;

    Display(A,B);
    
    return 0;
}