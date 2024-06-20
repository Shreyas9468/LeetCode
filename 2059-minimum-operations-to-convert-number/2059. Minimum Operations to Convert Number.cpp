class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        int n = nums.size();
        queue<int>q;
        q.push(start);
        int ops = 0;
        unordered_set<int>s; s.insert(start);
        vector<int>vis(1001,0); vis[start] = 1;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int x = q.front(); q.pop();
                if(x == goal) return ops;
                for(int j=0; j<n; j++){
                    int a = x + nums[j];
                    int b = x - nums[j];
                    int c = (x ^ nums[j]);
                    if(a == goal || b == goal || c == goal) return ops+1;
                    if(a >= 0 && a <= 1000 && vis[a] == 0) q.push(a), vis[a] = 1;
                    if(b >= 0 && b <= 1000 && vis[b] == 0) q.push(b), vis[b] = 1;
                    if(c >= 0 && c <= 1000 && vis[c] == 0) q.push(c), vis[c] = 1;
                }
            }
            ops++;
        }
        return -1;
    }
};