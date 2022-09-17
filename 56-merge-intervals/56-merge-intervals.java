class Solution {
        public int[][] merge(int[][] intervals) {
        // First, sort the intervals based on their start time
        // The one with smaller start time comes first (ascending)
        Arrays.sort(intervals, (a,b) -> (a[0] - b[0]));
        
        ArrayList<int []> result = new ArrayList<>();
        // Now we have a sorted interval list, so go through all of them and combine
        for (int i = 0; i < intervals.length; i++) {
            // Make sure we have at least one event in result to be compared with
            if (i == 0) {
                result.add(intervals[0]); 
                continue;
            }
            
            int[] prev = result.get(result.size()-1);
            int[] curr = intervals[i];
            
            // intervals overlap when:
            // prev ends after/when curr starts
            if (prev[1] >= curr[0]) {
                // The new interval should cover both events
                // So it has an smallest start time and largest end time
                // Since it's the interval in result that overlaps with our new
                // interval, we just modify that interval in result
                // (it's guarantee that start time of prev is smaller or equal
                // to that of curr since we traverse a sorted array)
                prev[1] = Math.max(prev[1], curr[1]);
            } else {
                result.add(curr);
            }
        }
        return result.toArray(new int[result.size()][2]);
    }
}