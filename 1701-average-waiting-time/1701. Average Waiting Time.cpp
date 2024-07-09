class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& c) {
        double sum = 0;
        int n = c.size();
        int nextprep = c[0][0];
        for(auto it : c){
            int ai = it[0];
            int ti = it[1];
            int prep =max( nextprep  , ai);
            prep += ti;
            sum+=(prep - ai);
            nextprep = prep;
        }
        return sum/n*1.0;
    }
};