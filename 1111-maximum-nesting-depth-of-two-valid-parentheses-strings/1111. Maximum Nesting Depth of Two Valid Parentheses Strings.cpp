class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.length();

        vector<int>ans(n);
        for(int i = 0;i<n;i++){
            ans [i] = seq[i] =='(' ? i&1 : (1- (i&1));
        }
        return ans;
    }
};