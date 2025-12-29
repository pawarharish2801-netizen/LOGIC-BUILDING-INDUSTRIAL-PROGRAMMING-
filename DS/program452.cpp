// Doubly Circular

#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node* PNODE;

class DoublyCL
{
    private:
        PNODE first;
        PNODE last;
        int iCount;

    public:
        DoublyCL()
        {
            cout<<"Object of DoublyCL gets created.\n";
            this->first = NULL;
            this->last = NULL;
            this->iCount = 0;
        }

        void InsertFirst(int no)
        {
            PNODE newn = NULL;

            newn = new node ;

            newn->data = no ;
            newn->next = NULL;
            newn->prev = NULL ;

            if ( first == NULL && last == NULL)
            {
                first = newn ;
                last = newn ;
            }
            else
            {
                newn->next = first ;
                newn->next->prev = newn ;
                first = newn ;
            }
            last->next = first ;
            first->prev = last ; 

            this->iCount++ ;
        }

        void InsertLast(int no)
        {
            PNODE newn = NULL;


            newn = new node ;

            newn->data = no ;
            newn->next = NULL;
            newn->prev = NULL ;

            if ( first == NULL && last == NULL)
            {
                first = newn ;
                last = newn ;
            }
            else
            {
                last->next = newn ;
                newn->prev = last ;
                last = newn ;
            }
            last->next = first ;
            first->prev = last ; 

            this->iCount++ ;
        }

        void InsertAtPos(int no, int pos)
        {
            PNODE temp = NULL  ;
            PNODE newn = NULL ;

            int iCnt = 0 ;
            if ( pos < 1 || pos > iCount+1)
            {
                cout<<"Invalid Position ";
                return ;
            }

            if (pos == 1)
            {
                InsertFirst(no);
            }
            else if ( pos == iCount+1)
            {
                InsertLast(no);
            }
            else
            {
                temp = this->first ;
                
                newn = new node ;
                
                newn->data = no ;
                newn->next = NULL ;
                newn->prev = NULL ;

                for ( iCnt = 1 ; iCnt < pos -1 ; iCnt++)
                {
                    temp = temp->next ;
                }
                newn->next = temp->next ;
                newn->next->prev = newn ;
                temp->next = newn ;
                newn->prev = temp ;

                this->iCount++ ;

            }
        }

        void DeleteFirst()
        {

            if ( this->first == NULL && last == NULL)
            {
                return ;
            }
            else if ( first == last)
            {
                delete first ;
                first = NULL ;
                last = NULL ;
            }
            else
            {
                first = first ->next ;
                delete last ->next ;
                
            }
            last->next = first ;
            first->prev = last ;

            this->iCount -- ;


        }

        void DeleteLast()
        { 
            if ( this->first == NULL && last == NULL)
            {
                return ;
            }
            else if ( first == last)
            {
                delete first ;
                first = NULL ;
                last = NULL ;
            }
            else
            {
                last = last->prev ;
                delete last->next ;
            }

            last->next = first ;
            first->prev = last ;

            this->iCount -- ;

        }

        void DeleteAtPos(int pos)
        {
            PNODE temp = NULL  ;

            int iCnt = 0 ;
            if ( pos < 1 || pos > iCount)
            {
                cout<<"Invalid Position ";
                return ;
            }

            if (pos == 1)
            {
                DeleteFirst();
            }
            else if ( pos == iCount)
            {
                DeleteLast();
            }
            else
            {
                temp = this->first ;
                
                for ( iCnt = 1 ; iCnt < pos -1 ; iCnt++)
                {
                    temp = temp->next ;
                }

                temp->next = temp->next->next ;
                delete (temp->next->prev);
                temp->next->prev = temp;

                this->iCount -- ;
            }
        }

        void Display()
        {
            PNODE temp = NULL ;

            temp = this->first ;

            cout<<" <= " ;
            do 
            {
                cout<<" | " << temp->data << " | <->" ;
                temp = temp->next ;
            } while ( temp != first);  
            cout<<"\n";
        }

        int Count()
        {
            return iCount;
        }
};

int main()
{
    DoublyCL obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);
    
    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    obj.DeleteFirst();
    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    obj.DeleteLast();

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    obj.InsertAtPos(105,4);

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    obj.DeleteAtPos(4);

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    return 0;
}