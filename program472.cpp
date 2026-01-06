#include <iostream> 
using namespace std;

class ArrayX
{
    public :
        int *Arr ;
        int iSize ;

        ArrayX(int no)
        {
            cout<<"Inside Constructor\n";
            iSize = no;
            Arr = new int[iSize];
        }

    ~ArrayX()
    {
        cout<<"Inside Destructor\n";
        delete [] Arr;
    }

};
int main()
{
    // ArrayX aobj(10);

    //STEP 1 : ALLOCATE THE MEMORY
    ArrayX *aobj = new ArrayX(10);

    // STEP 2 : USE THE MEMORY 

    // STEP 3 : DEALLOCATE THE MEMORY
    delete(aobj);

    return 0;  
}