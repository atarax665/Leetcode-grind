class Solution {
    public int[] parent;
    public boolean equationsPossible(String[] equations) {
        parent = new int[26];
        Arrays.fill(parent, -1);
        for (String equation : equations) {
            if (equation.charAt(1) == '=') {
                union(equation.charAt(0) - 'a', equation.charAt(3) - 'a');
            }
        }
        for (String equation : equations) {
            if (equation.charAt(1) == '!') {
                int x1 = find(equation.charAt(0) - 'a');
                int x2 = find(equation.charAt(3) - 'a');
                if (x1 == x2) return false;
            }
        }
        return true;
    }
    
    public int find(int x) {
        if (parent[x] == -1) parent[x] = x;
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    
    public void union(int x, int y) {
        int fx = find(x), fy = find(y);
        parent[fx] = fy;
    }
}