class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();
        unordered_map<int, int> prefixSumFreq;
        int prefixSum = 0;

        // Iterate through each element in the nums vector
        for (int i = 0; i < n; i++) {
            prefixSum += nums[i];

            // Check if prefixSum - k exists in the prefixSumFreq map
            if (prefixSum == k) {
                count++;
            }
            if (prefixSumFreq.count(prefixSum - k) > 0) {
                count += prefixSumFreq[prefixSum - k];
            }

            // Increment the frequency of the current prefix sum
            prefixSumFreq[prefixSum]++;
        }

        return count;
    }
};
