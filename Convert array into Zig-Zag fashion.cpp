#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    // Program for zig-zag conversion of array
   void zigZag(int arr[], int n) {
        int i=0, j=1;
        bool flag=1;
        while(i<n && j<n) {
            if(arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
            if(flag) i = j+1;
            else j = i+1;
            flag = !flag;
        }
    }
};

bool isZigzag(int arr[], int n){
    int f=1;
    
    for(int i=1; i<n; i++){
        if(f){
            if(arr[i-1]>arr[i]) return 0;
        }
        else{
            if(arr[i-1]<arr[i]) return 0;
        }
        f=f^1;
    }
    
    return 1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.zigZag(arr, n);
        bool check=1;
        check=isZigzag(arr,n);
        
        if(check) cout<<"1\n";
        else cout<<"0\n";
        
    }
    return 0;
}