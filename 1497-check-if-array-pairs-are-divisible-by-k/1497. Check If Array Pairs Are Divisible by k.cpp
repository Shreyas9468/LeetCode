class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        map<int,int>mp;
        for(auto it : arr){
            mp[(it%k+k)%k]++;
        }
        if(mp[0]%2==1) return false;
        for(int i =1;i<k;i++){
            if(mp[i]!=mp[k-i]){
                return false;
            }
        }
        return true;
    }


};