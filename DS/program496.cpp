
#include <iostream>
using namespace std;

#pragma pack(1)
class Queuenode
{
    public :
    int data ;
    Queuenode *next ;

    Queuenode(int no)
    {
        this->data = no ;
        this->next = NULL;
    }
};

class Queue
{
    private :
        Queuenode *first ;
        int iCount ;

    public :
        Queue();

        void enqueue(int);          //INSERTLAST       
        int dequeue();              //DELETEFIRST
        void display();     
        int count();
};

Queue ::  Queue()
{
    cout<<"Queue gets created Successfully\n";
    this->first = NULL ;
    this->iCount = 0 ;   
}

void  Queue ::  enqueue(int no)
{
    Queuenode *newn = NULL ;
    Queuenode *temp = NULL ;
    newn = new Queuenode(no);

    if (this->first ==NULL)
    {
        this->first = newn ;
    }
    else
    {
        temp = this->first ;
        while (temp->next != NULL)
        {
            temp = temp->next ;
        }
        temp->next = newn ;
    }
    
    this->iCount++ ;
}

int Queue ::  dequeue()
{
    int Value = 0 ;
    Queuenode *temp = NULL ;

    if ( this->first == NULL)
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


void Queue ::  display()
{
    Queuenode *temp = this->first ;

    if(this->first == NULL)
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

int Queue ::  count()
{
    return this->iCount ;
}

int main()
{
    Queue *qobj = new Queue();

    qobj->enqueue(11);
    qobj->enqueue(21);
    qobj->enqueue(51);
    qobj->enqueue(101);
    
    qobj->display();
    cout<<"Number of elements in the Queue are : "<<qobj->count()<<"\n";

    cout<<"Removed element is :"<<qobj->dequeue()<<"\n";

    qobj->display();
    cout<<"Number of elements in the Queue are : "<<qobj->count()<<"\n";

    cout<<"Removed element is :"<<qobj->dequeue()<<"\n";

    qobj->display();
    cout<<"Number of elements in the Queue are : "<<qobj->count()<<"\n";

    qobj->enqueue(121);

    qobj->display();
    cout<<"Number of elements in the Queue are : "<<qobj->count()<<"\n";

 
    delete(qobj);

    return 0 ;
}