// Input : Hello    Output : _ello

import java.util.*;

class StringX
{
    public String Update(String str)
    {
        char Arr[] = str.toCharArray();

        Arr[0] = '_';

        return new String(Arr);     // Change
    }
}

class program253
{
    public static void main(String A[])
    {
        String sRet = null;

        Scanner scanobj = new Scanner(System.in);

        System.out.println("Enter string : ");
        String sobj = scanobj.nextLine();

        StringX strobj = new StringX();
        
        sRet = strobj.Update(sobj);

        System.out.println("Updated string : "+sRet);
    }
}