class TimeMap {
  public Map<String,TreeMap<Integer,String>> hm= new HashMap<>();
    public TimeMap() {
    
    }
    
    public void set(String key, String value, int timestamp) {
        if(!hm.containsKey(key))
       {
           hm.put(key,new TreeMap<>(Collections.reverseOrder()));
           hm.get(key).put(timestamp,value);
       }
           
            hm.get(key).put(timestamp,value);
        
       

    
    }
    
    public String get(String key, int timestamp) {
        for(Map.Entry m : hm.entrySet()){
            
            if(m.getKey().equals(key)){
               
                TreeMap<Integer,String> tmap = (    TreeMap<Integer,String>)m.getValue();
               
                for(Map.Entry i : tmap.entrySet()){
                    if((int)i.getKey() <= timestamp) 
                    return String.valueOf(i.getValue());
                }
            }
        }
       
        return "";
    }
}