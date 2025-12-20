import java.util.*;

class program302
{
    public static void main(String A[])
    {
       Hashtable <String, Integer> hobj = new Hashtable <String, Integer>();

       hobj.put("PPA",27000);
       hobj.put("LB",28000);
       hobj.put("LSP",29000);
       hobj.put("PYTHON",30000);

       System.out.println(hobj);

       System.out.println(hobj.keys());

       Enumeration eobj = hobj.keys();

       String key = null;

       while(eobj.hasMoreElements())
       {
            key = (String)eobj.nextElement();
            System.out.println("Key : "+key);
            System.out.println("Value : "+hobj.get(key));
       }
    }
}