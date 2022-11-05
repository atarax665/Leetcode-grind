class Solution {
	class TrieNode {
        TrieNode[] next = new TrieNode[26];
        String word;
    }
	
	public TrieNode buildTrie(String[] words) {
        TrieNode root = new TrieNode();
		
        for (String word : words) {
            TrieNode curr = root;
            
			for (char c : word.toCharArray()) {
                int i = c - 'a';
                
				if (curr.next[i] == null) 
					curr.next[i] = new TrieNode();
                
				curr = curr.next[i];
           }
           
		   curr.word = word;
        }
		
        return root;
    }
	
    public List<String> findWords(char[][] board, String[] words) {
        List<String> result = new ArrayList<>();
        TrieNode root = buildTrie(words);
		
        for (int row = 0; row < board.length; row++) {
            for (int col = 0; col < board[0].length; col++) {
                dfs (board, row, col, root, result);
            }
        }
		
        return result;
    }

    public void dfs(char[][] board, int row, int col, TrieNode trie, List<String> result) {
        if (row < 0 || row >= board.length || col < 0 || col >= board[0].length)
            return;
        
        char c = board[row][col];
        
		if (c == '#' || trie.next[c - 'a'] == null) 
			return;
        
		trie = trie.next[c - 'a'];
        
		if (trie.word != null) {   
            result.add(trie.word);
            trie.word = null;   
        }

        board[row][col] = '#';
		
		dfs(board, row - 1, col, trie, result); 
        dfs(board, row, col - 1, trie, result);
        dfs(board, row + 1, col, trie, result); 
        dfs(board, row, col + 1, trie, result); 
		
        board[row][col] = c;
    }
}