#include <bits/stdc++.h>
using namespace std;
// User function Template for C++
class Solution{
public:
    string matrixChainOrder(int p[], int n){
    
         // Create a 2D array to store the minimum number of multiplications
        vector<vector<int>> m(n, vector<int>(n, 0));

        // Initialize the base cases
        for (int i = 1; i < n; i++) {
            m[i][i] = 0;
        }

        // Fill the matrix using bottom-up dynamic programming
        for (int L = 2; L < n; L++) {
            for (int i = 1; i < n - L + 1; i++) {
                int j = i + L - 1;
                m[i][j] = INT_MAX;
                for (int k = i; k <= j - 1; k++) {
                    int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                    if (q < m[i][j]) {
                        m[i][j] = q;
                    }
                }
            }
        }

        // Generate the parenthesis expression
        string result = generateParenthesis(m, p, 1, n - 1);
        return result;
    }

    string generateParenthesis(vector<vector<int>>& m, int p[], int i, int j) {
        if (i == j) {
            return string(1, 'A' + i - 1);
        }

        int minMultiplications = m[i][j];
        for (int k = i; k < j; k++) {
            int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
            if (q == minMultiplications) {
                string left = generateParenthesis(m, p, i, k);
                string right = generateParenthesis(m, p, k + 1, j);
                return "(" + left + right + ")";
            }
        }

        return "";
    }
};

int get(int p[],int n)
{
    int m[n][n],ans = 1e9; 
    for (int i = 1; i < n; i++)
        m[i][i] = 0; 
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n-L+1; i++){ 
            m[i][i + L - 1] = INT_MAX; 
            for (int k = i; k <= i + L - 2; k++){ 
                int q = m[i][k] + m[k + 1][i + L - 1] + p[i-1] * p[k] * p[i + L - 1]; 
                if (q < m[i][i + L - 1])
                { 
                    m[i][i + L - 1] = q;
                }
            }
        }
    }
    return m[1][n-1];
}

int find(string s,int p[])
{
    vector<pair<int,int>> arr;
    int ans = 0;
    for(auto t:s)
    {
        if(t=='(')
        {
            arr.push_back({-1,-1});
        }
        else if(t==')')
        {
            pair<int,int> b=arr.back();
            arr.pop_back();
            pair<int,int> a=arr.back();
            arr.pop_back();
            arr.pop_back();
            arr.push_back({a.first,b.second});
            ans += a.first*a.second*b.second;
        }
        else 
        {
            arr.push_back({p[int(t-'A')],p[int(t-'A')+1]});
        }
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0;i < n;i++)
        {
            cin>>p[i];
        }
        Solution ob;
        string result = ob.matrixChainOrder(p, n);
        if(find(result,p)==get(p,n))
        {
            cout<<"True"<<endl;
        }
        else
        {
            cout<<"False"<<endl;
        }
    }
    return 0;
}
