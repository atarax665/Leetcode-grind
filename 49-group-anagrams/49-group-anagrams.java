class Solution {
    public List<List<String>> groupAnagrams(String[] str) {
       HashMap<String,List<String>> hm= new HashMap<>();
      //  List<String> emp= new ArrayList<>();
//       
        for(int i=0;i<str.length;i++)
        {
            if(str[i].equals("")){
               if(!hm.containsKey("") )
        {
           hm.put("",new ArrayList<String>());
               //hm.get("").add(""); 
                
        }
            else if(hm.containsKey(""))
            {
                hm.get("").add("");
                continue;
            }}
          
     if (!hm.containsKey(sortstr(str[i]))){
               hm.put(sortstr(str[i]),new ArrayList<String>());
                hm.get(sortstr(str[i])).add(str[i]);
                
            }
             else if(hm.containsKey(sortstr(str[i])))
            {
                hm.get(sortstr(str[i])).add(str[i]);
            }
                
           
    
              }
        List<List<String>> ga = hm.values().stream().collect(Collectors.toCollection(ArrayList:: new));
        return ga;
               
               }
               
    
    public String sortstr(String str)
    { 
       char[] ss= str.toCharArray();
        Arrays.sort(ss);
        return new String(ss);
        
        
       
       
    }
}