#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int largest(vector<int> &arr, int n)
    {
         int maxElement = arr[0]; // Initialize maxElement with the first element

        // Traverse the array to find the largest element
        for (int i = 1; i < n; i++)
        {
            if (arr[i] > maxElement)
            {
                maxElement = arr[i]; // Update maxElement if a larger element is found
            }
        }

        return maxElement;
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int>arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        cout << ob.largest(arr, n) << "\n";
    }
    return 0;
}