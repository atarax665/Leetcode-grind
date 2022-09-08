class Solution {
    public List<List<Integer>> threeSum(int[] num) {
      HashMap<Integer,Integer> hm = new HashMap<>(); 
        List<List<Integer>> ll = new ArrayList<>();
          Arrays.sort(num);
          for(int i=0;i<num.length;i++)
        {
              hm.put(num[i],i);
          }
        
       // Arrays.sort(num);
         
        for(int i=0;i<num.length-2;i++)
         {
            if(i!=0 && num[i-1]==num[i])
                continue;
            
            for(int j=i+1;j<num.length-1;j++)
            {
                 if(j!=i+1 && num[j]==num[j-1]){  
                    continue;
                }
              
                int s = num[i] + num[j];
                
                
                if(hm.containsKey(-s) && hm.get(-s)>j )  
                {
               ll.add( Arrays.asList(num[i],num[j],-s));
                }
            }
            
        }
       
                  
                 return ll;   
         
    }
}