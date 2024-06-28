class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& r) {
        //
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        vector<int>v(n,0);
        for(auto it :r ){
            v[it[0]]++;
            v[it[1]]++;
        }
        priority_queue<pair<int,int>>pq;
        for(int i =0;i<n;i++){
            pq.push({v[i] , i});
        }
        int cuimp = n;
        vector<int>st(n,0);
        while(!pq.empty()){
            int ind = pq.top().second;
            pq.pop();
            st[ind] = cuimp--;
        }
        long long sum =0;
        for(auto it : r){
            sum+= (st[it[0]] + st[it[1]]);
        }
        return sum;

    }
};