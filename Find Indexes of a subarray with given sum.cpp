#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
    vector<int> subarraySum(vector<int>arr, int n, long long s) {
        int i = 0, j = 0;
        int sum = arr[0];
        while(i < n && j < n) {
            if(i > j) {
                j++;
                sum += arr[j];
            }
            if(sum == s) return {i+1, j+1};
            else if(sum < s) {
                j++;
                sum += arr[j];
            }
            else if(sum > s) {
                sum -= arr[i];
                i++;
            }
        }
        
        return {-1};
    }
};
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}