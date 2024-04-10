#include<bits/stdc++.h> 
using namespace std; 
class Solution{
    public:
    int findSingle(int n, int arr[]){
        // code here
          int ans = 0;
        for(int i=0; i<n; i++){
            ans ^= arr[i];
        }
        return ans;
    }
};

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, X;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        
        Solution ob;
        cout << ob.findSingle(N, arr) << endl;
    }
    return 0; 
}