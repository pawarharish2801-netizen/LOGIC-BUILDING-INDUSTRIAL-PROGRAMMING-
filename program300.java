import java.util.*;

class program300
{
    public static void main(String A[])
    {
       Hashtable <String, Integer> hobj = new Hashtable <String, Integer>();

       hobj.put("PPA",27000);
       hobj.put("LB",28000);
       hobj.put("LSP",29000);
       hobj.put("PYTHON",30000);

       System.out.println(hobj);

       System.out.println(hobj.get("LB"));
    }
}