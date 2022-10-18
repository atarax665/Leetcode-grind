class Solution {
    public String countAndSay(int n) {
      
        String countthesay="1";
        while(n!=1)
        {
           countthesay= say(countthesay);
            n--;
        }
        return countthesay;
    }
    public String say(String c)
    {
       
       
        int count=1;
        StringBuilder saystr=new StringBuilder();
         char[] s=c.toCharArray();
        char k=c.charAt(0);
        
    for(int i=1;i<s.length;i++)
    {
  
       if(s[i]==k)
       {
         count++;
       
       }
       else
       {
           saystr.append(count).append(k);
           count=1;
  k=s[i];
       }
    }
     saystr.append(count).append(k);
        
    return saystr.toString();
    }
}