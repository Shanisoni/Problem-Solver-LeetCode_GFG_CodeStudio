//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:

        int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
        {
            // your code here
             int dp[n1+1][n2+1][n3+1];

            for (int i = 0; i <= n1; i++) {
                for (int j = 0; j <= n2; j++) {
                    for (int k = 0; k <= n3; k++) {
                        if (i == 0 || j == 0 || k == 0)
                            dp[i][j][k] = 0;
                        else if (A[i-1] == B[j-1] && A[i-1] == C[k-1])
                            dp[i][j][k] = 1 + dp[i-1][j-1][k-1];
                        else
                            dp[i][j][k] = max(max(dp[i-1][j][k], dp[i][j-1][k]), dp[i][j][k-1]);
                    }
                }
            }

            return dp[n1][n2][n3];
        }
};


//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        Solution obj;
        cout << obj.LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}