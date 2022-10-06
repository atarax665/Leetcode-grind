class TimeMap {
    
    // HashMap of key(String) corresponding of TreeMap<TimeStamp,Value>>
    HashMap<String,TreeMap<Integer,String>> hm;
    
    public TimeMap() {
        hm = new HashMap<String,TreeMap<Integer,String>>();
    }
    
    public void set(String key, String value, int timestamp) {

        TreeMap<Integer,String> tmap;
        if(hm.get(key) != null)
            tmap = hm.get(key);  
        else
            tmap = new TreeMap<>(Collections.reverseOrder());  
        tmap.put(timestamp,value);
        hm.put(key,tmap);
        
    }
    
    public String get(String key, int timestamp) {
        for(Map.Entry m : hm.entrySet()){
            if(m.getKey().equals(key)){
                TreeMap<Integer,String> tmap = (TreeMap<Integer,String>)m.getValue();
                for(Map.Entry tm : tmap.entrySet()){
                    if((int)tm.getKey() <= timestamp) return String.valueOf(tm.getValue());
                }
            }
        }
        return "";
        
    }
}