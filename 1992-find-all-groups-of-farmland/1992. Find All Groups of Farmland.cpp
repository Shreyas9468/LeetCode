class Solution {
public:

    void dfs(int i, int j,vector<vector<int>>&land,vector<vector<bool>>&vis,vector<int>&ans,int m,int n)
    {
        vis[i][j] = true;
        if(i==m-1 &&j==n-1){
            ans.push_back(i);
            ans.push_back(j);
        }
        else  if(i+1<=m-1 && j+1<=n-1 && land[i+1][j]==0 && land[i][j+1]==0){
            ans.push_back(i);
            ans.push_back(j);
        }
        else if(i == m-1 && land[i][j+1]==0){
            ans.push_back(i);
            ans.push_back(j);
        }
        else if(j==n-1 && land[i+1][j]==0){
            ans.push_back(i);
            ans.push_back(j);
        }

        int dx[] = {0,0,-1,1};
        int dy[] = {1,-1,0,0};
        for(int k=0;k<4;k++){
            int r = i + dx[k];
            int c = j + dy[k];
            if(r<=m-1 &&c<=n-1&&r>=0&&c>=0&&land[r][c] ==1 &&!vis[r][c] ){
                dfs(r,c,land,vis,ans,m,n);
            }
        }

    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size();
        int n = land[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        vector<vector<int>>res;
        for(int i=0;i<m;i++){
            for(int j =0 ;j<n;j++){
                if(land[i][j]==1 && !vis[i][j]){
                    vector<int>ans;
                    ans.push_back(i);
                    ans.push_back(j);
                    dfs(i,j,land,vis,ans,m,n);
                    res.push_back(ans);
                }
            }
        }
        return res;
    }
};