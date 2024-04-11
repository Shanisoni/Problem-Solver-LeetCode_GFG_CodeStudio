
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to convert a given Gray equivalent n to Binary equivalent.
    int grayToBinary(int n) {
        int prev = 0; // Initialize the previous bit to 0.
        for (int i = 31; i >= 0; i--) {
          
            n ^= (1 << i) * prev;
            
          
            if (n & (1 << i))
                prev = 1; // If set, update the previous bit to 1.
            else
                prev = 0; // If not set, update the previous bit to 0.
        }
        return n; // Return the converted binary equivalent.
    }
};

int main()
{
    int t,n;
    cin>>t;//testcases
    while(t--)
    {
        cin>>n;//initializing n
        
        Solution ob;
        //calling function grayToBinary()
       cout<< ob.grayToBinary(n)<<endl;
    }
}