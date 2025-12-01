import java.util.*;

class Number
{
    public boolean CheckPerfect(int iNo)
    {
        int i = 0, iSum = 0;

        if(iNo < 0)
        {
            iNo = -iNo;
        }
                                        
         // Reverse loop                               

        for(i = iNo/2 ; (i >= 1) && (iSum < iNo); i--)
        {
            if((iNo % i) == 0)
            {
                iSum = iSum + i;
            }
        }

        return (iSum == iNo); 
    }
} // End of Number

class program85
{
    public static void main(String A[])
    {
        int iValue = 0;
        boolean bRet = false;

        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter number : ");
        iValue = sobj.nextInt();
        
        Number nobj = new Number();
        bRet = nobj.CheckPerfect(iValue); 

        if(bRet == true)
        {
            System.out.println(iValue+" is perfect number");
        }
        else
        {
            System.out.println(iValue+" is not a perfect number");
        }

        // Important
        
        sobj = null;
        nobj = null;

        System.gc();
    }
}
