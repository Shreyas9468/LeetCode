class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int operations = 0;

        for (int i = 0; i <= n - 3; i++) {
            if (nums[i] == 0) {
                for (int j = 0; j < 3; j++) {
                    nums[i + j] = 1 - nums[i + j];  
                }
                operations += 1;
            }
        }

        // Check if the last two elements are 1
        for (int i = n - 2; i < n; i++) {
            if (nums[i] == 0) {
                return -1;
            }
        }

        return operations;
    }
};