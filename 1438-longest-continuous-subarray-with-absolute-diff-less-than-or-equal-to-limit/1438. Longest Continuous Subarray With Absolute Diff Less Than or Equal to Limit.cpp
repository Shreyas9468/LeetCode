#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int l) {
        int i = 0;
        int j = 0;
        int n = nums.size();
        int cnt = 0;

        deque<int> maxDeque;
        deque<int> minDeque;

        while (j < n) {
            // Maintain the decreasing order in maxDeque
            while (!maxDeque.empty() && nums[j] > maxDeque.back()) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(nums[j]);

            // Maintain the increasing order in minDeque
            while (!minDeque.empty() && nums[j] < minDeque.back()) {
                minDeque.pop_back();
            }
            minDeque.push_back(nums[j]);

            // Check if the current window is valid
            while (!maxDeque.empty() && !minDeque.empty() && maxDeque.front() - minDeque.front() > l) {
                if (maxDeque.front() == nums[i]) {
                    maxDeque.pop_front();
                }
                if (minDeque.front() == nums[i]) {
                    minDeque.pop_front();
                }
                i++;
            }

            cnt = max(cnt, j - i + 1);
            j++;
        }

        return cnt;
    }
};
