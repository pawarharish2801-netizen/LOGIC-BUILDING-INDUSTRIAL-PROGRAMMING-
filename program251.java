import java.util.*;

class StringX
{
    public int CountCapital(String str)
    {
        int iCnt = 0;
        int iCount = 0;

        char Arr[] = str.toCharArray();

        for(iCnt = 0; iCnt < Arr.length; iCnt++)
        {
            if(Arr[iCnt] >= 'A' && Arr[iCnt] <= 'Z')
            {
                iCount++;
            }
        }

        return iCount;
    }
}

class program251
{
    public static void main(String A[])
    {
        int iRet = 0;

        Scanner scanobj = new Scanner(System.in);

        System.out.println("Enter string : ");
        String sobj = scanobj.nextLine();

        StringX strobj = new StringX();
        
        iRet = strobj.CountCapital(sobj);

        System.out.println("Frequency of capital characters : "+iRet);
    }
}