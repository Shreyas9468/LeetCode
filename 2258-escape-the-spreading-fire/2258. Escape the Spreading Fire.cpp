class Solution {
public:
    int dfs(int i,int j,int t,vector<vector<int>>& vis,vector<vector<int>>& dis){
        if(i==vis.size()-1 && j==vis[0].size()-1) return 1;
        if(dis[i][j]==t) return 0;
        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};
        vis[i][j]=t;
        for(int k=0;k<4;k++){
            int nx=dx[k]+i,ny=dy[k]+j;
            if(nx<0 || ny<0 || nx>=vis.size() || ny>=vis[0].size()) continue;
            if(vis[nx][ny]>t+1 && dis[nx][ny]>=t+1 && dfs(nx,ny,t+1,vis,dis)) return 1;
        }
        return 0;
    }
    int chk(int tm,vector<vector<int>>& a){
        queue<vector<int>> q;
        vector<vector<int>> dis(a.size(),vector<int> (a[0].size(),INT_MAX));
        vector<vector<int>> vis(a.size(),vector<int> (a[0].size(),INT_MAX));
        for(int i=0;i<a.size();i++){
            for(int j=0;j<a[0].size();j++){
                if(a[i][j]==1) q.push({i,j,0}),dis[i][j]=0;
                else if(a[i][j]==2) dis[i][j]=-1;
            }
        }
        while(q.size()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                int cx=q.front()[0],cy=q.front()[1],t=q.front()[2];q.pop();
                int dx[]={0,0,1,-1};
                int dy[]={1,-1,0,0};
                for(int j=0;j<4;j++){
                    int nx=dx[j]+cx,ny=dy[j]+cy;
                    if(nx<0 || ny<0 || nx>=a.size() || ny>=a[0].size() || dis[nx][ny]<=t+1) continue;
                    q.push({nx,ny,t+1});
                    dis[nx][ny]=1+t;
                }
            }
        }
        return dfs(0,0,tm,vis,dis);
    }
    int maximumMinutes(vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size();
        int l=-1,r=n*m+100,ans=-1;
        while(r-l>1){
            int m=l+(r-l)/2;
            if(chk(m,a)) ans=m,l=m;
            else r=m;
        }
        if(ans>=n*m) return 1000000000;
        return ans;
    }
};