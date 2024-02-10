#include<bits/stdc++.h>
using namespace std;


class Solution {
    int n;
    long long int rec(int i, int j, int k, vector<vector<int>> &arr, vector<vector<vector<int>>> &dp)
    {
        if(i>=n || j>=n || k<0)return 0;
        if(i==n-1 && j==n-1)return k==arr[i][j];
        
        if(dp[i][j][k] != -1)return dp[i][j][k];
        
        return dp[i][j][k] = rec(i+1, j, k-arr[i][j], arr, dp)+rec(i, j+1, k-arr[i][j], arr, dp);
    }
    
public:
    
    long long numberOfPath(int N, int k, vector<vector<int>> &arr){
        
        n = N;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k+1, -1)));
        return rec(0, 0, k, arr, dp);
    }
};


int main()
{
    Solution obj;
    int i,j,k,l,m,n,t;
    cin>>t;
    while(t--)
    {
        cin>>k>>n;
        vector<vector<int>> v(n, vector<int>(n, 0));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>v[i][j];
        cout << obj.numberOfPath(n, k, v) << endl;
    }
}