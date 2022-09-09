class Solution {
    public boolean wordPattern(String pattern, String s) {
        HashMap <Character, String> map=new HashMap<Character, String>();
        String [] arr=s.split(" ");
        if(pattern.length()!=arr.length)
            return false;
        for(int i=0;i<pattern.length();i++){
            if(map.containsKey(pattern.charAt(i))==false){
                if(map.containsValue(arr[i])==false)
                     map.put(pattern.charAt(i), arr[i] );
                else
                    return false;
            }
               else{
                   if((map.get(pattern.charAt(i)).equals(arr[i]))==false)
                       return false;
               }
        }
       return true;
    }
}