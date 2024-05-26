class Solution {
public:
    int findMinCost(string x, string y, int costX, int costY) {
        int n = x.size(), m = y.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(x[i - 1] == y[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        
        int lcs = dp[n][m];
        int xLen = (n - lcs) * costX;
        int yLen = (m - lcs) * costY;
        
        return xLen + yLen;
    }
};