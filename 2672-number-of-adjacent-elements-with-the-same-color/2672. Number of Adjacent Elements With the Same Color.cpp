class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& q) {
        
        vector<int> res(q.size());
        vector<int> arr(n,0);
        
        int cnt=0;
        res[0]=0;
        arr[q[0][0]]=q[0][1];
        for(int i=1;i<q.size();i++)
        {
            if(arr[q[i][0]]==0)
            {
                if(q[i][0]-1>=0 &&  arr[q[i][0]-1]==q[i][1]) cnt++;
                if(q[i][0]+1 <n &&  arr[q[i][0]+1]==q[i][1]) cnt++;
              
              
            }
            else 
            {
                if(q[i][0]-1>=0 &&  arr[q[i][0]]==arr[q[i][0]-1]) cnt--;
                 if(q[i][0]+1 <n && arr[q[i][0]]==arr[q[i][0]+1]) cnt--;  
                                         
                 if(q[i][0]-1>=0 &&  arr[q[i][0]-1]==q[i][1]) cnt++;
                 if(q[i][0]+1 <n &&  arr[q[i][0]+1]==q[i][1]) cnt++;
                                         
              
            }
              arr[q[i][0]]=q[i][1];
                res[i]=cnt;
                
        }
        return res;                                 
                                        
    }
};