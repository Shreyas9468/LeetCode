class Solution {
public:
    bool issati(long long maxtime, vector<int>& time, int totalTrips) {
        long long maxtrip = 0;
        for (auto it : time) {
            maxtrip += (maxtime / it);
        }
        return maxtrip >= totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        //long long ans = 0;

        long long i = 1;

        long long j = (1e14);

        while (i < j) {
            long long mid = (i + j) / 2;
            if (issati(mid, time, totalTrips)) {
                j = mid;
            } else {
                i = mid + 1;
            }
        }
        return i;
    }
};