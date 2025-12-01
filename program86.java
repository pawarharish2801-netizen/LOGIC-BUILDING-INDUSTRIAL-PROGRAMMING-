// Input : 5
// Output : 5 * 4 * 3 * 2 * 1 = 120

import java.util.*;

class Number
{
    public int CalculateFactorial(int iNo)
    {
        int i = 0, iFact = 1;

        for(i = 1; i <= iNo; i++)
        {
            iFact = iFact * i;
        }

        return iFact;
    }
} // End of Number

class program86
{
    public static void main(String A[])
    {
        int iValue = 0, iRet = 0;

        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter number : ");
        iValue = sobj.nextInt();
        
        Number nobj = new Number();
        iRet = nobj.CalculateFactorial(iValue); 

        System.out.println("Factorial is : "+iRet);

        // Important
        
        sobj = null;
        nobj = null;

        System.gc();
    }
}
