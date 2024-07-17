class Solution {
public:
    int countHomogenous(string s) {
        const int MOD = 1e9 + 7;
        long long count = 0; 

        int n = s.length();
        int streak = 1;

        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                streak++;
            } else {
                count += (long long)streak * (streak + 1) / 2 % MOD; 
                streak = 1;
            }
        }

        count += (long long)streak * (streak + 1) / 2 % MOD; 

        return count % MOD; 
    }
};