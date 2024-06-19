class Solution {
public:
    int isans(vector<int>& b, int m, int k, int d) {
        int cnt = 0;
        int tb = 0;
        //    cout<<m<<endl;
        for (auto it : b) {
            if (it <= d) {
                cnt++;
            } else {
                //  cout<<cnt<<endl;
                int f = cnt / k;

                tb += f;

                //   cout<<d<<" "<<tb<<endl;
                if (tb >= m) {
                    // cout<<d<<endl;
                    return d;
                }
                cnt = 0;
            }
        }
        int f = cnt / k;

        tb += f;

    
        if (tb >= m) {
           
            return d;
        }
       
        return 0;
    }

    int minDays(vector<int>& b, int m, int k) {
        int mind = INT_MAX;
        int maxd = INT_MIN;
        if (b.size() < (m*1ll * k*1ll))
            return -1;
        for (auto it : b) {
            mind = min(it, mind);
            maxd = max(it, maxd);
        }
        // cout<<mind<<maxd<<endl;
        int mid =-1;
        while(mind <= maxd){
            mid = (mind) + (maxd-mind)/2;
            if(isans(b,m,k,mid)){
                maxd = mid-1;
            }
            else{
                mind = mid+1;
            }
        }
        return mind ;
    }
};