class Solution {
public:
    vector<int> printKClosest(vector<int>& arr, int n, int k, int x) {
        // Find the crossover point
        int id1 = findCrossOver(arr, 0, n - 1, x);
        
        // Initialize the second index
        int id2 = id1 + 1;
        
        // If x is present in the array, ignore it by decrementing id1
        if (arr[id1] == x) id1--;

        // Result vector to store the k closest elements
        vector<int> ans(k);
        for (int i = 0; i < k; i++) {
            // If both indices are valid
            if (id1 >= 0 && id2 < n) {
                // Calculate the differences from x
                int val1 = x - arr[id1], val2 = arr[id2] - x;
                // Choose the closer value or the greater value in case of tie
                if (val1 < val2) {
                    ans[i] = arr[id1];
                    id1--;
                } else {
                    ans[i] = arr[id2];
                    id2++;
                }
            } else if (id1 >= 0) { // If only id1 is valid
                ans[i] = arr[id1];
                id1--;
            } else { // If only id2 is valid
                ans[i] = arr[id2];
                id2++;
            }
        }
        
        return ans;
    }

private:
    int findCrossOver(vector<int>& arr, int low, int high, int x) {
        // Base case: x is greater than all elements
        if (arr[high] <= x) {
            return high;
        }
        // Base case: x is smaller than all elements
        if (arr[low] > x) {
            return low;
        }
        // Find the middle index
        int mid = (low + high) / 2;
        // Check if mid is the crossover point
        if (arr[mid] <= x && arr[mid + 1] > x) {
            return mid;
        } 
        // Recur to the right half if mid is less than x
        else if (arr[mid] < x) {
            return findCrossOver(arr, mid + 1, high, x);
        }
        // Recur to the left half if mid is greater than x
        return findCrossOver(arr, low, mid - 1, x);
    }
};