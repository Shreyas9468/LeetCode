class Solution {
public:

    int topv(int k ,int j , vector<vector<int>>&v , vector<vector<bool>>&vis){
        int cnt = 0;
        for(int i = k-1;i>=0;i--){
            if(v[i][j]==1 || v[i][j]==-1) break;
            if(!vis[i][j]){
                vis[i][j]= true;
                cnt++;
            }
            
        }
        return cnt;
    }

    int bootomv(int k ,int j , vector<vector<int>>&v , vector<vector<bool>>&vis){
        int cnt = 0;
      //  cout<<v.size()<<"this"<<endl;
        for(int i = k+1;i<v.size();i++){
            if(v[i][j]==1 || v[i][j]==-1) break;
            if(!vis[i][j]){
                vis[i][j]= true;
                cnt++;
            }
        }
        return cnt;
    }

     int leftsidev(int i ,int k , vector<vector<int>>&v , vector<vector<bool>>&vis){
        int n = v[i].size();
        int cnt = 0;
        for(int j = k+1;j<n;j++){
            if(v[i][j]==1 || v[i][j]==-1) break;
            if(!vis[i][j]){
                vis[i][j]= true;
                cnt++;
            }
        }
        return cnt;
    }

    int rightsidev(int i ,int k , vector<vector<int>>&v , vector<vector<bool>>&vis){
        int n = v[i].size();
        int cnt = 0;
        for(int j = k-1;j>=0;j--){
            if(v[i][j]==1 || v[i][j]==-1) break;
            if(!vis[i][j]){
                vis[i][j]= true;
                cnt++;
            }
        }
        return cnt;
    }


    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        long long int total = m*n;
        vector<vector<int>>v(m,vector<int>(n,0));
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        for(auto it:guards ){
            int i = it[0];
            int j = it[1];
            v[i][j] = -1;
            

        }
        for(auto it:walls ){
            int i = it[0];
            int j = it[1];
            v[i][j] = 1;
            

        }
        // for(int i = 0;i<m;i++){
        //     for(int j =0;j<n;j++){
        //         cout<<v[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        total -= (guards.size() + walls.size());
        //cout<<total<<endl;
        for(int i= 0;i<m;i++){
            for(int j =0;j<n;j++){
                
                if(v[i][j] == 0){
                    continue;
                }
                else if(v[i][j]==1){
                    continue;
                }
                else{
                    
                    int top = topv( i ,  j , v , vis);
                    //cout<<total<<" "<<top<<endl;
                    int bootom = bootomv( i ,  j , v , vis);
                    //cout<<total<<" "<<bootom<<endl;
                    int leftside = leftsidev( i ,  j , v , vis);
                    //cout<<total<<" "<<leftside<<endl;
                    int rightside = rightsidev( i ,  j , v , vis);
                    
                    total -= (top + bootom + leftside + rightside);
                }
            }
            
        }
        return total;

    }
};