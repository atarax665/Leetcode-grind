class Solution {
    public int minMutation(String start, String end, String[] bank) {
        Map<String, List<String>> mutMap=new HashMap<String, List<String>>();
        mutMap.put(start, new ArrayList<String>());
            
        for(String m: bank)
        {
            if(isMutation(start, m))
            {
                mutMap.get(start).add(m);
            }
        }
        
        for(String str: bank)
        {
            List<String> mutList=new ArrayList<String>();
            
            for(String m: bank)
            {
                if(isMutation(str, m))
                {
                    mutList.add(m);
                }
            }
            mutMap.put(str, mutList);
        }
        Set<String> visited=new HashSet<String>();
        Queue<String> queue=new LinkedList<String>();
        queue.offer(start);
        visited.add(start);
        
        int count=0;
        while(queue.size()>0)
        {
            
            for(int s=queue.size();s>0;--s)
            {
                String cur=queue.poll();

                if(cur.equals(end))
                {
                    return count;
                }
                
                for(String next: mutMap.get(cur))
                {
                    if(!visited.contains(next))
                    {
                        visited.add(next);
                        queue.offer(next);
                    }
                }
            }
            count++;
            
        }
        return -1;
        
    }
    public boolean isMutation(String str1, String str2)
    {
        int diff=0;
        for(int i=0;i<str1.length();++i)
        {
            if(str1.charAt(i)!=str2.charAt(i))
            {
                diff++;
                if(diff>1)
                {
                    return false;
                }
            }
            
        }
        return diff==1;
    }
}