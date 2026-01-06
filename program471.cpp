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

    ArrayX *aobj = new ArrayX(10);

    return 0;
}