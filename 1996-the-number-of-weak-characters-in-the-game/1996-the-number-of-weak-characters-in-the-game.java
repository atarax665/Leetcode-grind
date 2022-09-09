class Solution {
    class Comp implements Comparator<int[]>{
        public int compare(int[] a,int[] b)
        {
            if(a[1]==b[1])
                return Integer.compare(b[0],a[0]);
            else
                return Integer.compare(a[1],b[1]);
            
        }
    }
    
    public int numberOfWeakCharacters(int[][] prop) {
        
         
        Arrays.sort(prop,new Comp());
        int c=0;
        int largestnum=prop[prop.length-1][0];
        for(int i=prop.length-2;i>=0;i--)
        {
            if(largestnum>prop[i][0])
                c++;
            else
                largestnum=prop[i][0];
        }
        return c;
    }   
}