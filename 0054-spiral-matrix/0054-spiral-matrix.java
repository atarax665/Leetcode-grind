class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> li = new ArrayList<Integer>();
        int left = 0, right = matrix[0].length - 1;
        int top = 0, bottom = matrix.length - 1;
        
        while(left <= right && top <= bottom)
        {
            for(int i = left; i <= right; i++)
            {
                li.add(matrix[top][i]);
            }
            top++;
            
            for(int i = top; i<= bottom; i++)
            {
                li.add(matrix[i][right]);
            }
            right--;
            
            if(left > right || top > bottom)
                break;
            
            for(int i = right; i >= left; i--)
            {
                li.add(matrix[bottom][i]);
            }
            bottom--;
            for(int i = bottom; i>= top; i--)
            {
                li.add(matrix[i][left]);
            }
            left++;
        }
        for(int i = 0; i < li.size(); i++)
        {
            System.out.println(li.get(i));
        }
        return li;
    }
}