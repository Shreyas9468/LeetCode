class Solution {
public:
    int maxDistance(vector<int>& p, int m) {
        sort(p.begin(),p.end());
        int s = 1;
        int e = p[(int)p.size()-1] - p[0];
        int ans =1;
        while(s<=e){
            int mid = s+ (e-s)/2;

            if(isvalid(p,m,mid)){
                ans = mid;
            //    cout<<mid<<endl;
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return ans;

    }

    bool isvalid(vector<int>&p , int m , int f){
        int prev = p[0];
        int i =1;m--;
        while(i<p.size()){
            
            if(p[i] - prev >= f){
                m-=1;
                prev = p[i];
            }
            if(m==0){
                return true;
            }
            i++;
        }
        return false;
    }
};