class Solution {
   public int longestPalindrome(String s) {
        Map<Character,Integer> hm= new HashMap<>();
        char[] c= s.toCharArray();
        int freq=0,odd=0;
        int flag=0;
        for(char i: c)
        {
         hm.put(i,hm.getOrDefault(i,0)+1);
            freq++;
        }
       for (Map.Entry<Character,Integer> i : hm.entrySet()) {
           if(i.getValue() % 2 == 1)
           {
               flag = 1;
               odd++;
           }
       }
        if(flag==1)
        {
            return freq-(odd-1);
        }
        return freq;
        
    }
}