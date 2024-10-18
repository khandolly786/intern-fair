class Solution {
public:
    int countSubsets(int idx, int currOR, vector<int>& nums, int maxOR) {
        // Base case: if we reach the end of the array
        if (idx == nums.size()) {
            // If the current OR matches the max OR, this subset is valid
            return currOR == maxOR ? 1 : 0;
        }

        // Option 1: Take the current element (OR it with currOR)
        int takecount = countSubsets(idx + 1, currOR | nums[idx], nums, maxOR);

        // Option 2: Do not take the current element
        int notcount = countSubsets(idx + 1, currOR, nums, maxOR);

        // Return the total count from both options
        return takecount + notcount;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int maxOR = 0;

        // Compute the maximum possible OR of all elements
        for (int &num : nums) {
            maxOR |= num;
        }

        int currOR = 0;

        // Start the recursive function to count subsets
        return countSubsets(0, currOR, nums, maxOR);
    }
};

