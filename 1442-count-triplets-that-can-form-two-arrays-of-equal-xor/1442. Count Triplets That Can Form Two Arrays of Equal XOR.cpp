class Solution {
public:
    int countTriplets(vector<int>& arr) {
        unordered_map<int , vector<int>> mp;
        mp[0].push_back(-1);
        int x =0;
        int ans =0;
        for(int  i= 0;i<arr.size();i++){
            x^=arr[i];
            if(mp.find(x) !=mp.end()){
                for(auto it : mp[x]){
                    ans += (i-it)-1;
                }
            }
            mp[x].push_back(i);
        }
        return ans;

    }
};