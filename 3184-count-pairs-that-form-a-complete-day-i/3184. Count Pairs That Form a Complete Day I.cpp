class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        unordered_map<int, int> remainder_count;
        int count = 0;
        for (int hour : hours) {
            int remainder = hour % 24;
            if (remainder == 0) {
                count += remainder_count[0];
            } else {
                count += remainder_count[24 - remainder];
            }
            ++remainder_count[remainder];
        }
        return count;
    }
};