class Solution {
public:
    bool checkPossibility(std::vector<int>& nums) {
        int count = 0; // Counter to track the number of decreasing elements
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) { // If the current element is greater than the next one
                count++;
                if (count > 1) {
                    return false; // If more than one element needs to be modified, return false
                }

                // Check if we can modify the current or next element to make the array non-decreasing
                if (i > 0 && nums[i - 1] > nums[i + 1]) {
                    nums[i + 1] = nums[i]; // Modify the next element to match the current one
                } else {
                    nums[i] = nums[i + 1]; // Modify the current element to match the next one
                }
            }
        }
        return true;
    }
};