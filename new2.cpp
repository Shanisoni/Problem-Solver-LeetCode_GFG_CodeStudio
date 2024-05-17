class Solution {
public:
    int findPair(int n, int x, vector<int> &arr) {
        // Sort the array to enable binary search
        sort(arr.begin(), arr.end());
        
        // Iterate through each element in the array
        for (int i = 0; i < n; ++i) {
            // Calculate the value that should form the required difference with arr[i]
            int find = arr[i] - x;
            
            // Use binary search to check if 'find' exists in the array
            if (binary_search(arr.begin(), arr.end(), find)) {
                // If the required difference is zero, ensure it's not the same element
                if (find == arr[i] && x == 0) {
                    // Find the lower bound of 'find' to check for its multiple occurrences
                    int lb = lower_bound(arr.begin(), arr.end(), find) - arr.begin();
                    // Ensure the found element is not the same as the current element
                    if (lb != i) return 1;
                } else {
                    // If the difference is non-zero, return 1 as we found the pair
                    return 1;
                }
            }
        }
        
        // If no such pair is found, return -1
        return -1;
    }
};