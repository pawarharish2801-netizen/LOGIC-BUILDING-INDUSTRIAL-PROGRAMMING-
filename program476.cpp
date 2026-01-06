#include <iostream> 
using namespace std;


class ArrayX
{
    public :
        int *Arr ;
        int iSize ;

        ArrayX(int no);
        ~ArrayX();
        void Accept();
        void Display();
        int Addition();
        int Maximum();

};
ArrayX :: ArrayX(int no)
    {
        iSize = no;
        Arr = new int[iSize];
    }

ArrayX :: ~ArrayX()
{
    delete [] Arr;
}


void ArrayX :: Accept()
{
    int iCnt = 0 ;
    
    cout << "Enter the Elements : \n";
    for ( iCnt = 0 ; iCnt < iSize ; iCnt++)
    {
        cin>>Arr[iCnt];
    }
}


void ArrayX :: Display()
{
    int iCnt = 0 ;
    
    cout << "Elements of the Array are : \n";
    for ( iCnt = 0 ; iCnt < iSize ; iCnt++)
    {
        cout<<Arr[iCnt]<<"\t";
    }
    cout<<"\n";

}

int ArrayX ::  Addition()
{
    int iCnt = 0 ;
    int iSum = 0 ;
    
    for ( iCnt = 0 ; iCnt < iSize ; iCnt++)
    {
        iSum = iSum + Arr[iCnt];
    }
    return iSum;
}

int ArrayX :: Maximum()
{
    int iMax = 0 ;
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
int main()
{
    // ArrayX aobj(10);
    int iValue = 0 ;

    cout<<"Enter the no of elements : \n";
    cin>>iValue ;

    //STEP 1 : ALLOCATE THE MEMORY
    ArrayX *aobj = new ArrayX(iValue);

    // STEP 2 : USE THE MEMORY 
    aobj->Accept();
    aobj->Display();

    cout<<"Summation of all elements : "<<aobj->Addition()<<"\n";
    cout<<"Maximum is : "<<aobj->Maximum()<<"\n";

    // STEP 3 : DEALLOCATE THE MEMORY
    delete(aobj);

    return 0;  
}