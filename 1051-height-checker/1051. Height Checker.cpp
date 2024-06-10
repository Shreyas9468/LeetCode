class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>st = heights;

        sort(st.begin(),st.end());
        int cnt =0;
        for(int i = 0;i<st.size();i++){
            if(st[i] != heights[i]){
                cnt++;
            }
        }
        return cnt;
    }
};