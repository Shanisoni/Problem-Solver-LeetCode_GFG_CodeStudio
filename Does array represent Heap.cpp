#include <bits/stdc++.h>
using namespace std;


class Solution{
    public:
    bool isMaxHeap(int arr[], int n)
    {
        for(int i=0;i<n;i++){
            
            int leftChild=2*i+1;
            int rightChild=2*i+2;
            
            if(arr[i]< arr[leftChild] || arr[i]<arr[rightChild]){
                return false;
            }
        }
        return true;
    }
};
int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
       int n;
       cin >> n;
       int a[4*n]={0};
       for(int i =0;i<n;i++){
           cin >> a[i];
       }
       Solution ob;
       cout<<ob.isMaxHeap(a, n)<<endl;
        
    }
    return 0;
}