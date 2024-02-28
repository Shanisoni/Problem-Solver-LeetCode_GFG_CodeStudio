#include <bits/stdc++.h>

using namespace std;
class Solution{
public:
	
	long long sumBitDifferences(int arr[], int n) {
	    // code here
	       long long ans = 0;
        for(int bit=0;bit<32;bit++) {
            long long countOne = 0, countZero = 0;
            for(int i=0;i<n;i++) {
                if(arr[i]%2) countOne++;
                else countZero++;
                arr[i] = arr[i]/2;
            }
            ans += countOne*countZero*2;
        }
        return ans;
    
	}
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.sumBitDifferences(arr, n);
        cout << ans << "\n";
    }
    return 0;
}