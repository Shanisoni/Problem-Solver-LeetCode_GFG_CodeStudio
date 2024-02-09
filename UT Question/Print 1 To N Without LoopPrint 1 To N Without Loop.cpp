#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    //Complete this function
    void printNos(int N)
    {
          if (N > 0) {
            printNos(N - 1);  // Recursive call to print numbers from 1 to N-1
            cout << N << " "; // Print the current number
        }
    }
};

int main()
{
    int T;
    
    //taking testcases
    cin>>T;
    
    while(T--)
    {
        int N;
        
        //input N
        cin>>N;
        Solution ob;
        //calling printNos() function
        ob.printNos(N);
        cout << "\n";
    }
    return 0;
}
