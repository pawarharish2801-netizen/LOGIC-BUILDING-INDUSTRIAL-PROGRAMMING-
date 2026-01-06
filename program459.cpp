#include <iostream>
using namespace std ;

double Addition ( double No1 , double No2)
{
    double Ans;
    Ans = No1 + No2 ;
    return Ans ;
}

int main()
{
    float i = 0.0f , j = 0.0f ;
    float Ret = 0.0f ;

    cout<<"Enter first no : ";
    cin>>i;

    cout<<"Enter second no : ";
    cin>>j;

    Ret = Addition(i,j);
    
    cout<<"Addition is : "<<Ret<<"\n";                                                                                                                

    return 0 ;
}