class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        unordered_map<long long, long long> remainder_count;
        long long count = 0;
        for (int hour : hours) {
            long  long remainder = hour % 24;
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

