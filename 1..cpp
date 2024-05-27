class Solution {
public:
    int longestSubseq(int n, vector<int> &a) {
        vector<int> dp(n, 1);
        int maxi = 0;
        
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(abs(a[i] - a[j]) == 1 and dp[i] < 1 + dp[j])
                    dp[i] = 1 + dp[j];
                    
                maxi = max(maxi, dp[i]);
            }
        }
        
        return maxi;
    }
};