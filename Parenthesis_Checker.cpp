
#include<bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        
         stack<char> s;
        for (char c : x) {
            if (c == '(' || c == '[' || c == '{') {
                // Push opening brackets onto the stack.
                s.push(c);
            } else {
                // Check if the stack is empty (unmatched closing bracket).
                if (s.empty()) return false;

                // Pop the top element from the stack and check for matching brackets.
                char top = s.top();
                s.pop();
                if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{')) {
                    return false;
                }
            }
        }

        // Check if there are any unmatched opening brackets left in the stack.
        return s.empty();
    }

};


int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
