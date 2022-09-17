class Solution {
        public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, (a,b) -> (a[0] - b[0]));
        
        ArrayList<int []> result = new ArrayList<>();
        for (int i = 0; i < intervals.length; i++) {
            if (i == 0) {
                result.add(intervals[0]); 
                continue;
            }
            
            int[] prev = result.get(result.size()-1);
            int[] curr = intervals[i];
            if (prev[1] >= curr[0]) {
                prev[1] = Math.max(prev[1], curr[1]);
            } 
            else
            {
                result.add(curr);
            }
        }
        return result.toArray(new int[result.size()][2]);
    }
}