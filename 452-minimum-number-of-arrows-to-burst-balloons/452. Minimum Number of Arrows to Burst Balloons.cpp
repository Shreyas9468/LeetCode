class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        sort(points.begin(),points.end());
        vector<int> ans;
        int i =0;
        int xs = points[0][0];
        ans.push_back(xs);
        int xe = points[0][1];
        while(i<points.size()){
            if(xe<points[i][0]){
                ans.push_back(xs);
                xs = points[i][0];
            
                xe = points[i][1];
            }
            xe = min(xe,points[i][1]);
            i++;
        }
        return ans.size();
    }
};