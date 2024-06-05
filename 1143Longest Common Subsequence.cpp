class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
         int m = text1.length();
        int n = text2.length();

        // Create a 2D vector to store the lengths of common subsequences
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Fill the dp table
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // The result is stored in the bottom-right cell of the dp table

          // The result is stored in the bottom-right cell of the dp table
           // The result is stored in the bottom-right cell of the dp table

          // The result is stored in the bottom-right cell of the dp table
        return dp[m][n];
    }
};