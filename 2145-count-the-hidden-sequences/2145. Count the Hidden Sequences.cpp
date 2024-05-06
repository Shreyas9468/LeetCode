#define ll long long
class Solution {
public:

    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        ll sum = 0;
        ll mini = 0 , maxi =0;
        for(auto it : differences){
            sum+=it;
            mini = min(mini , sum);
            maxi = max(maxi , sum);
        }
        ll ub = upper - maxi;
        ll lb = lower - mini;
        return ub- lb+1>0 ? ub-lb+1:0;
    }
};