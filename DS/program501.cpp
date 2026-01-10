//////////////////////////////////////////////////////////////////////
//FINAL CODE OF QUEUE USING GENERIC APPROACH 
//////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

#pragma pack(1)
template <class T>
class Queuenode
{
    public :
    T data ;
    Queuenode <T> *next ;

    Queuenode(T no)
    {
        this->data = no ;
        this->next = NULL;
    }
};

template <class T>
class Queue 
{
    private :
        Queuenode <T> *first ;
        Queuenode <T> *last ;
        int iCount ;

    public :
        Queue();

        void enqueue(T);          //INSERTLAST       
        T dequeue();              //DELETEFIRST
        void display();     
        int count();
};


template <class T>
Queue <T> ::  Queue()
{
    cout<<"Queue gets created Successfully\n";
    this->first = NULL ;
    this->last = NULL;
    this->iCount = 0 ;   
}

template <class T>
void  Queue <T> ::  enqueue(T no)
{
    Queuenode <T> *newn = NULL ;
    newn = new Queuenode <T>(no);

    if (this->first ==NULL && this->last ==NULL )
    {
        this->first = newn ;
        this->last = newn ;
    }
    else
    {
        this->last->next = newn ;
        this->last = this->last->next;   
    }
    
    this->iCount++ ;
}

template <class T>
T Queue <T> ::  dequeue()
{
    T Value = 0 ;
    Queuenode <T> *temp = NULL ;

    if ( this->first == NULL && this->last ==NULL)
    {
        cout<<"Queue is empty\n";
        return -1 ;
    }

    Value = this->first->data ;

    temp = this->first;

    this->first = this->first->next ;
    delete temp ;

    this->iCount-- ;
    return Value;
}

template <class T>
void Queue <T> ::  display()
{
    Queuenode <T> *temp = this->first ;

    if(this->first == NULL && this->last == NULL)
    {
        cout<<"Queue is empty\n";
        return ;
    }
    
    while (temp != NULL)
    {
        cout<<" | "<<temp->data<<" | - ";
        temp = temp->next;
    }
    cout<<"\n";
}

template <class T>
int Queue  <T> ::  count()
{
    return this->iCount ;
}

int main()
{
    Queue <int> *qobj = new Queue <int>();

    int iChoice = 0 ;
    int Value = 0 ;
    int iRet = 0 ;

    while(1)
    {
        cout<<"---------------------------------------------------\n";
        cout<<"------------Please Select the Option---------------\n";
        cout<<" 1   : Insert New Element into queue               \n";
        cout<<" 2   : Remove New Element into queue               \n";
        cout<<" 3   : Display Elements of the queue               \n";
        cout<<" 4   : Count the no of elements from the queue     \n";
        cout<<" 0   : Exit the Application                        \n";
        cin>>iChoice ;
        cout<<"---------------------------------------------------\n";

        switch (iChoice )
        {
            case 1 :
                cout<<"Enter the element that you want to insert : \n";
                cin>>Value ;
                qobj->enqueue(Value);
                cout<<"Elements gets inserted Successfully \n";
                break ;

            case 2 :
                iRet = qobj->dequeue();
                
                if( iRet != -1)
                {
                    cout<<"Element removed from queue is : "<<iRet<<"\n";
                }
                break;

            case 3 :
                cout<<"Elements of the queue are : \n";
                qobj->display();
                break;

            case 4 :
                iRet = qobj->count() ;
                cout<<"No of elements in queue are : "<<iRet<<"\n";
                break ;

            case 0 :
                cout<<"Thank you for using our application" ;
                delete qobj;
                return 0 ;

            default:
                cout<<"Please Enter the Valid Option \n";
        }   //End of switch
    }   //End of while



    return 0 ;
    
}//End of main