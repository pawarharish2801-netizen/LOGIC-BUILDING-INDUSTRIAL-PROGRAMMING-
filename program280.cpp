// OOP approach (Generic)

#include<iostream>
using namespace std;

template <class T>
class Arithematic
{
    public:
        T No1;
        T No2;
 
    Arithematic(T A, T B)
    {
        No1 = A;
        No2 = B;
    }

    T Addition()
    {
        T Ans = 0;
        Ans = No1 + No2;
        return Ans;
    }

    T Substraction()
    {
        T Ans = 0;
        Ans = No1 - No2;
        return Ans;
    }
};

int main()
{
    Arithematic <int> aobj1(11,10);       
    Arithematic <double> aobj2(101.5,50.3);     

    cout<<aobj1.Addition()<<"\n";
    cout<<aobj1.Substraction()<<"\n";
    
    cout<<aobj2.Addition()<<"\n";
    cout<<aobj2.Substraction()<<"\n";
     
    return 0;
}