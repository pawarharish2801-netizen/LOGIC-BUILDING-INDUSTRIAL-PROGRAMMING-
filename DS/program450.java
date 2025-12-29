// Doubly Linear

class node
{
    public int data;
    public node next;
    public node prev;

    public node(int no)
    {
        this.data = no;
        this.next = null;
        this.prev = null;
    }
}

class DoublyLL
{
    private node first;
    
    private int iCount;

    public DoublyLL()
    {
        System.out.println("Object of DoublyLL gets created.");
        
        this.first = null;
        
        this.iCount = 0;
    }

    public void InsertFirst(int no)
    {
        node newn = null;

        newn = new node(no);

        
        newn.next = first ;
        first = newn ;

        iCount++;
        
    }

    public void InsertLast(int no)
    {
        node newn = null ; 
        node temp = null ;

        newn = new node(no);

        if(first  == null)
        {
            first = newn ;
        }
        else
        {
           temp = this.first;
           
           while(temp.next != null)
           {
                temp = temp.next;
           }
           newn.prev = temp ;
           temp.next = newn ;
        }
        iCount++;
    }

    public void InsertAtPos(int no, int pos)
    {
        node temp = null ;
        node newn = null ;
        int iCnt = 0 ;
        if ( pos < 1 || pos > iCount+1)
        {
            System.out.println("Invalid Positon");
            return ; 
        }

        if (pos == 1)
        {
            InsertFirst(no);
        }
        else if ( pos == iCount + 1)
        {
            InsertLast(no);
        }
        else
        {
            temp = this.first ;
            
            newn = new node(no);

            for( iCnt = 1 ; iCnt< pos - 1 ; iCnt++)
            {
                temp = temp.next;
            }
            newn.next = temp.next ;
            newn.next.prev = newn ;
            temp.next = newn ;
            newn.prev = temp ;
            iCount++ ;
        }
    
    }

    public void DeleteFirst()
    {
        if ( this.first == null)
        {
            return ;
        }
        else if(first.next == null)
        {
            this.first = null ;
           
        }
        else
        {
            this.first = this.first.next ;
            this.first.prev = null ;
        }
        iCount-- ;
         System.gc();
    }
    
    public void DeleteLast()
    {
        node temp = null ;
        if ( this.first == null)
        {
            return ;
        }
        else if(first.next == null)
        {
            this.first = null ;
           
        }
        else
        {   
            temp = this.first ;

            while(temp.next.next != null)
            {
                temp = temp.next ;
            }
            temp.next = null ;
        }
        iCount-- ;
         System.gc();
    }
    
    public void DeleteAtPos(int pos)
    {
        node temp = null ;
        int iCnt = 0 ;
        if ( pos < 1 || pos > iCount)
        {
            System.out.println("Invalid Positon");
            return ; 
        }

        if (pos == 1)
        {
            DeleteFirst();
        }
        else if ( pos == iCount + 1)
        {
            DeleteLast();
        }
        else
        {
            temp = this.first ;
        
            for( iCnt = 1 ; iCnt< pos - 1 ; iCnt++)
            {
                temp = temp.next;
            }
            temp.next = temp.next.next ; 
            temp.next.prev = temp ;

            iCount-- ;
            System.gc();
        }
    }
    
    public void Display()
    {
        node temp = null ;

        temp = this.first;
        System.out.print("NULL <->");
        while(temp != null)
        {
           System.out.print(" | " + temp.data + " | <->"); 
           temp = temp.next;
        }

        System.out.println("NULL");
    }

    public int Count()
    {
        return this.iCount;
    }
}

class program450
{
    public static void main(String A[])
    {
        DoublyLL obj = null;
        int iRet = 0;

        obj = new DoublyLL();

        obj.InsertFirst(51);
        obj.InsertFirst(21);
        obj.InsertFirst(11);
        
        obj.Display();

        iRet = obj.Count();

        System.out.println("Number of nodes are : "+iRet);

        obj.InsertLast(101);
        obj.InsertLast(111);
        obj.InsertLast(121);
        
        obj.Display();

        iRet = obj.Count();

        System.out.println("Number of nodes are : "+iRet);

        obj.DeleteFirst();

        obj.Display();

        iRet = obj.Count();

        System.out.println("Number of nodes are : "+iRet);

        obj.DeleteLast();

        obj.Display();

        iRet = obj.Count();

        System.out.println("Number of nodes are : "+iRet);
       
        obj.InsertAtPos(105,4);

        obj.Display();

        iRet = obj.Count();

        System.out.println("Number of nodes are : "+iRet);
       
        obj.DeleteAtPos(4);
        
        obj.Display();

        iRet = obj.Count();

        System.out.println("Number of nodes are : "+iRet);
    
        // Important for memory deallocation 
        obj = null;
        System.gc();
    }
}