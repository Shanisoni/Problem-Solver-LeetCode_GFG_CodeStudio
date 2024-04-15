#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
   long long trappingWater(int arr[], int n){
        // code here
        int a=0,b=1,a_;
        long long sum =0;
        
        while(a!=b-1 || b<n){
            if( b == n && a!=b-1){
                for(int i=0;i<b-a;i++){
                    sum -= arr[a] - arr[i+a];
                }
                a_ = a;
                a = b-1;
                b = b-2;
                while(b>a_){
                    
                    if( arr[a] > arr[b] )
                        sum += arr[a] - arr[b];
                    else
                    a=b;
                    b--;
                }
                break;
            }
            
            if( arr[a] > arr[b] )
                sum += arr[a] - arr[b];
            else
                a=b;
            b++;
        }
        
        return sum;
   }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}