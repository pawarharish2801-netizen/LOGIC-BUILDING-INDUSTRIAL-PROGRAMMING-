// Doubly Lieanr

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

class DoublyLL
{
    private:
        PNODE first;
        int iCount;

    public:
        DoublyLL()
        {
            cout<<"Object of DoublyLL gets created.\n";
            this->first = NULL;
            this->iCount = 0;
        }

        void InsertFirst(int no)
        {
            PNODE newn = NULL;

            newn = new node;

            newn->data = no ;
            newn->next =  NULL;
            newn->prev = NULL ;

            if ( first == NULL)
            {
                first = newn ;
            }
            else 
            {
                newn->next = first ;
                newn->next->prev = newn ;
                first = newn ;
            }
            iCount++ ;
        }
        

        void InsertLast(int no)
        {
            PNODE newn = NULL;
            PNODE temp = NULL ;

            newn = new node;

            newn->data = no ;
            newn->next =  NULL;
            newn->prev = NULL ;

            if ( first == NULL)
            {
                first = newn ;
            }
            else 
            {
                temp = this->first ;
                while(temp->next != NULL)
                {
                    temp= temp->next;
                }
                temp->next = newn ;
                newn->prev = temp;
            }
            iCount++ ;
        }

        void InsertAtPos(int no, int pos)
        {
            PNODE temp = NULL ;
            
            PNODE newn = NULL ;
            int iCnt = 0 ;

            if ( pos <1 || pos > iCount +1 )
            {
                cout << " Invalid Position \n";
                return ;
            }
            
            if ( pos == 1)
            {
                this->InsertFirst(no);
            }
            else if ( pos == iCount+1)
            {
                this->InsertLast(no);
            }
            else
            {
                newn = new node ;

                newn->data = no ;
                newn->next = NULL ;
                newn->prev = NULL ;

                temp = this->first ;

                for ( iCnt = 1 ; iCnt < pos - 1 ; iCnt++)
                {
                    temp = temp->next ;
                }
                newn->next = temp->next ;
                newn->next->prev = newn ;
                temp->next = newn ;
                newn->prev = temp ;

                this->iCount++;
            }

        }

        void DeleteFirst()
        {
            PNODE temp = NULL ;
            if ( first == NULL)
            {
                return ;
            }
            else if ( first->next == NULL)
            {
                delete first ;
                first = NULL;
            } 
            else
            {
                temp = this->first ;
                first = first ->next ;
                first->prev = nullptr ;
                delete temp ;
            }
            iCount-- ;
        }

        void DeleteLast()
        {
            PNODE temp = NULL ;
            PNODE target = NULL;
            if ( first == NULL)
            {
                return ;
            }
            else if ( first->next == NULL)
            {
                delete first ;
                first = NULL;
            } 
            else
            {
                temp = this->first ;

                while(temp->next->next != NULL )
                {
                    temp = temp->next ;
                }
                target = temp->next ;
                delete target ;
                temp->next = NULL;
            }
            iCount-- ;
        }

        void DeleteAtPos(int pos)
        {
            
            PNODE temp = NULL ;
        
            int iCnt = 0 ;

            if ( pos <1 || pos > iCount  )
            {
                cout << " Invalid Position \n";
                return ;
            }
            
            if ( pos == 1)
            {
                this->DeleteFirst();
            }
            else if ( pos == iCount)
            {
                this->DeleteLast();
            }
            else
            {
            
                temp = this->first ;

                for ( iCnt = 1 ; iCnt < pos - 1 ; iCnt++)
                {
                    temp = temp->next ;
                }
                temp->next = temp->next->next;
                delete (temp->next->prev);
                temp->next->prev = temp ;

                this->iCount--;
            }

        }

        void Display()
        {
            PNODE temp = NULL ;

            temp = this->first ;

            while (temp != NULL)
            {
                cout<<" | "<<temp->data<<" | <=>";
                temp = temp->next ;
            }
            cout << "\n";
        }

        int Count()
        {
            return iCount;
        }
};

int main()
{
    DoublyLL obj;
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