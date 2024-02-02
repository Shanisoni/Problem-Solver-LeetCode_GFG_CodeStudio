#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        //Your code here
        // Check if the string is empty
        if (s.empty()) {
            return -1;
        }
        
        // Initialize result and sign
        int result = 0;
        int sign = 1;

        // Initialize index to start from the first character
        int i = 0;

        // Check for the sign character
        if (s[0] == '-') {
            sign = -1;
            i++;
        }

        // Iterate through the string and convert to integer
        while (i < s.length()) {
            // Check if the character is numeric
            if (isdigit(s[i])) {
                // Convert character to integer and add to result
                result = result * 10 + (s[i] - '0');
                i++;
            } else {
                // If a non-numeric character is encountered, return -1
                return -1;
            }
        }

        // Multiply the result by the sign to get the final result
        return sign * result;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}