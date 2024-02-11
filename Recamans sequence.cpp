#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    vector<int> recamanSequence(int n){
         vector<int> result;
        unordered_set<int> seen;
        
        result.push_back(0);
        seen.insert(0);
        
        for (int i = 1; i < n; i++) {
            int prev = result[i - 1];
            int next = prev - i;
            
            if (next < 0 || seen.find(next) != seen.end()) {
                next = prev + i;
            }
            
            result.push_back(next);
            seen.insert(next);
        }
        
        return result;
    
    }
};
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<int> ans = ob.recamanSequence(n);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}