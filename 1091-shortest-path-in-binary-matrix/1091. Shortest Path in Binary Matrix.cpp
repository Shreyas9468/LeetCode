class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        if(grid[0][0]==1 || grid[n-1][m-1]==1){
            return -1;
        }
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        q.push({0,0});
        vis[0][0]=1;
        int delr[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int delc[8] = {-1,  0,  1, 1, 1, 0, -1, -1};
        int ans=1;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int row=q.front().first;
                int col=q.front().second;
                q.pop();
                if(row==n-1 && col==m-1){
                    return ans;
                }
                for(int i=0;i<8;i++){
                    int nrow=row+delr[i];
                    int ncol=col+delc[i];

                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol]==1
                    && grid[nrow][ncol]==0){
                        q.push({nrow,ncol});
                        vis[nrow][ncol]=1;
                    }
                }  
            }
            ans++;
        }
        return -1;
    }
};