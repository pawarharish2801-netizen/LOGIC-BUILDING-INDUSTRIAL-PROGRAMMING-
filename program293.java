import java.util.*;

class program293
{
    public static void main(String A[])
    {
        int Arr[] = {45,21,90,54,78};

        // this is foreach loop
        for(int no : Arr)
        {
            System.out.println(no);
        }

        Arrays.sort(Arr);

        System.out.println("Array after sorting : ");
        
        for(int no : Arr)
        {
            System.out.println(no);
        }

    }
}