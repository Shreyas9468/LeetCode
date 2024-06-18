class Solution {
public:
    Solution(){
ios::sync_with_stdio(0);
cout.tie(0);
cin.tie(0);}
    int bs(vector<pair<int,int>>&vp ,int val){
        int s = 0;
        int e = vp.size()-1;
        int mid = 0;
        while(s<e){
            mid = s + (e-s)/2;
            if(vp[mid].first == val){
                break;
            }
            else if(vp[mid].first > val){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        int mp = 0;
        for(int i = e;i>=0;i--){
            if(vp[i].first<=val){
                mp = max(mp,vp[i].second);
            }
        }
        return mp;
    }

    int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w) {
        int n = d.size();
        int m = w.size();
        vector<pair<int,int>>vp;
        for(int i = 0;i<n;i++){
            vp.push_back({d[i],p[i]});
        }
        sort(vp.begin(),vp.end());
        int tp = 0;
       for(auto it : w){
            tp += bs(vp , it);
       }
       return tp;
    }
};