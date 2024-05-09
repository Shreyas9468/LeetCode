class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        map<double, int> mp;
        
        for (const auto& it : rectangles) {
            double slope = static_cast<double>(it[0]) / it[1];
            mp[slope]++;
        }
        
        long long ans = 0;
        
        for (const auto& it : mp) {
            int n = it.second;
            ans += static_cast<long long>(n) * (n - 1) / 2;
        }
        
        return ans;
    }
};