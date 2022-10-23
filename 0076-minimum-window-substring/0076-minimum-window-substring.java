class Solution {
    public String minWindow(String s, String t) {
        
        if (t.length () > s.length ())
        {
            return "";
        }
        
        int i = 0, j = 0, start = -1, end = -1, length = 0, minLength = Integer.MAX_VALUE;
        int[] frequencyS = new int[128];
        int[] frequencyT = new int[128];
        
        for (char c : t.toCharArray ())
        {
            frequencyT[c]++;
            if (frequencyT[c] == 1)
            {
                length++;
            }
        }
        
        while (i < s.length())
        {
            char c = s.charAt (i++);
            ++frequencyS[c];
            if (frequencyS[c] == frequencyT[c])
            {
                length--;
            }
            
            while (length == 0)
            {
                if (i - j < minLength)
                {
                    start = j;
                    end = i;
                    minLength = i - j;
                }
                
                char ch = s.charAt(j++);
                if (frequencyS[ch] == frequencyT[ch])
                {
                    length++;
                }
                
                frequencyS[ch]--;
            }
        }
        
        return minLength == Integer.MAX_VALUE ? "" : s.substring (start, end);
    }
}