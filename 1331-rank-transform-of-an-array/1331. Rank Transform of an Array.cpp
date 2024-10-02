class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>store = arr;

        sort(arr.begin(),arr.end());
       map<int,int>vp;
        int j=1;
        for(int i =0;i<arr.size();i++){
            if(vp.find(arr[i])!=vp.end()){
                 continue;
            }
            else{
                 vp[arr[i]] = j;
                 j++;
            }
        }
        
        for(int i=0;i<store.size();i++){
            store[i] = vp[store[i]];
        }
        return store;

    }
};