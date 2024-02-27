#include<bits/stdc++.h>
using namespace std;
class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        
        sort(arr,arr+N);
        string temp1=arr[0];
        string temp2=arr[N-1];
        string ans="";
        for(int i=0; i<min(temp1.size(),temp2.size()); i++)
        {
             
             if(temp1[i]==temp2[i])
             {
                 ans+=temp1[i];
             }
             else
             {
                 break;
             }
            
            
        }
        if(ans=="")
        return "-1";
        return ans;
    }
};

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}
// int main()
// {
//     int t; cin >> t;
//     while (t--)
//     {
//         int n; cin >> n;
//         string arr[n];
//         for (int i = 0; i < n; ++i)
//             cin >> arr[i];
        
//         Solution ob;
//         cout << ob.longestCommonPrefix (arr, n) << endl;
//     }
// }