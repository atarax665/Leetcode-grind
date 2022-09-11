class Solution {
public:
    int dp[3001][1001];
    const int N = 1e9+7;
	
	int findAnswer(int startPos, int endPos, int cur, int k) {
        int curTmp = cur - 1000;
        if(k < 0) return 0;
        if(k == 0 && curTmp == endPos) return 1;
        if(dp[cur][k] != -1) return dp[cur][k];
        return dp[cur][k] = (findAnswer(startPos, endPos, cur - 1, k - 1) + findAnswer(startPos, endPos, cur + 1, k - 1)) % N;
    }
        
    int numberOfWays(int startPos, int endPos, int k) {
        memset(dp, -1, sizeof(dp));
        int ans = findAnswer(startPos, endPos, startPos + 1000, k);
        return ans;
    }
};