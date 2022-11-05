class Solution {
    List<String> foundWords = new ArrayList();
    int R, C;
    char[][] board;
    
    class TrieNode {
        TrieNode[] nextNodes = new TrieNode[27];
        boolean isWordAddedInRes = false;
        String endingWord;
    }

    void makenodes(String[] words, TrieNode headNode) {
        TrieNode node;
        for(String word : words) {
            node = headNode;
            char[] wordChar = word.toCharArray();
            for(char c : wordChar) {
                int charIndx = c-'a';
                if(node.nextNodes[charIndx] == null) {
                    node.nextNodes[charIndx] = new TrieNode();
                }
                node = node.nextNodes[charIndx];
            }
            node.nextNodes[26] = new TrieNode();
            node.nextNodes[26].endingWord = word;
        }
    }

    void dfs(boolean[][] visited, TrieNode node, int r, int c) {
        if(r < 0 || r >= R || c < 0 || c >= C || visited[r][c]) return;
        int charIndx = board[r][c] - 'a';
        TrieNode nextNode = node.nextNodes[charIndx];
        if(nextNode == null) return;
        
        if(nextNode.nextNodes[26] != null) {
            TrieNode endNode = nextNode.nextNodes[26];
            if(endNode.isWordAddedInRes == false) {
                endNode.isWordAddedInRes = true;
                String foundWord = nextNode.nextNodes[26].endingWord;
                foundWords.add(foundWord);
            }
        }
        visited[r][c] = true;
        dfs(visited, nextNode, r+1, c);
        dfs(visited, nextNode, r-1, c);
        dfs(visited, nextNode, r, c+1);
        dfs(visited, nextNode, r, c-1);
        visited[r][c] = false;
    }

    public List<String> findWords(char[][] board, String[] words) {
        this.R = board.length;
        this.C = board[0].length;
        this.board = board;
        boolean[][] visited = new boolean[R][C];

        TrieNode headNode = new TrieNode();
        makenodes(words, headNode);

        for(int r = 0; r < R; r++) {
            for(int c = 0; c < C; c++) {
                dfs(visited, headNode, r, c);
            }
        }
        return foundWords;
    }
}