#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution {
public:
    // Function to find the length of the longest subarray with sum 0.
    int maxLen(vector<int>& A, int n) {
        unordered_map<int, int> sumIndex;
        int maxLength = 0;
        int currentSum = 0;

        for (int i = 0; i < n; i++) {
            currentSum += A[i];

            if (currentSum == 0) {
                maxLength = max(maxLength, i + 1);
            } else {
                if (sumIndex.find(currentSum) != sumIndex.end()) {
                    maxLength = max(maxLength, i - sumIndex[currentSum]);
                } else {
                    sumIndex[currentSum] = i;
                }
            }
        }

        return maxLength;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}