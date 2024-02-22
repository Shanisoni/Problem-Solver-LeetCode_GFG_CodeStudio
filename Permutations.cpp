class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
         vector<vector<int>> result;
        vector<int> current;

        permuteHelper(nums, result, current);
        
        return result;
    }

private:
    void permuteHelper(vector<int>& nums, vector<vector<int>>& result, vector<int>& current) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (find(current.begin(), current.end(), nums[i]) != current.end()) {
                continue;  // Skip elements already in the current permutation
            }

            current.push_back(nums[i]);
            permuteHelper(nums, result, current);
            current.pop_back();
        }
    }
};