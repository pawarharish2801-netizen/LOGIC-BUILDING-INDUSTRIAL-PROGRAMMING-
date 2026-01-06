#include <iostream> 
using namespace std;

template <class T>
class ArrayX
{
    public :
        T *Arr ;
        int iSize ;

        ArrayX(int no);
        ~ArrayX();
        void Accept();
        void Display();
        T Addition();
        T Maximum();
        int CountFrequency(T iNo);

};
template <class T>
ArrayX <T> :: ArrayX(int no)
{
    iSize = no;
    Arr = new T[iSize];
}

template <class T>
ArrayX <T>:: ~ArrayX()
{
    delete [] Arr;
}

template <class T>
void ArrayX <T> :: Accept()
{
    int iCnt = 0 ;
    
    cout << "Enter the Elements : \n";
    for ( iCnt = 0 ; iCnt < iSize ; iCnt++)
    {
        cin>>Arr[iCnt];
    }
}

template <class T>
void ArrayX <T> :: Display()
{
    int iCnt = 0 ;
    
    cout << "Elements of the Array are : \n";
    for ( iCnt = 0 ; iCnt < iSize ; iCnt++)
    {
        cout<<Arr[iCnt]<<"\t";
    }
    cout<<"\n";

}

template <class T>
T ArrayX <T> ::  Addition ()
{
    int iCnt = 0 ;
    T iSum = 0 ;
    
    for ( iCnt = 0 ; iCnt < iSize ; iCnt++)
    {
        iSum = iSum + Arr[iCnt];
    }
    return iSum;
}

template <class T>
T ArrayX <T> :: Maximum()
{
    T iMax;
    int iCnt = 0 ;

    iMax = Arr[0];
    for (iCnt = 0 ; iCnt < iSize ; iCnt++)
    {   
        if ( Arr[iCnt]> iMax)
        {
            iMax = Arr[iCnt];
        }
    }
    return iMax;
}

template <class T>
int ArrayX <T> :: CountFrequency(T iNo)
{
    int iCnt = 0 ;
    int iCount = 0 ;

    for ( iCnt = 0 ; iCnt < iSize ; iCnt++)
    {
        if ( Arr[iCnt] == iNo)
        {   
            iCount++ ;
        }
    }
    return iCount;
}

int main()
{
    // ArrayX aobj(10);
    int iValue = 0 ;

    cout<<"Enter the no of elements : \n";
    cin>>iValue ;

    //STEP 1 : ALLOCATE THE MEMORY
    ArrayX <int> *aobj = new ArrayX <int> (iValue);

    // STEP 2 : USE THE MEMORY 
    aobj->Accept();
    aobj->Display();

    cout<<"Summation of all elements : "<<aobj->Addition()<<"\n";
    cout<<"Maximum is : "<<aobj->Maximum()<<"\n";
    cout<<"Frequency  is : "<<aobj->CountFrequency (11)<<"\n";

    

    // STEP 3 : DEALLOCATE THE MEMORY
    delete(aobj);

    return 0;  
}