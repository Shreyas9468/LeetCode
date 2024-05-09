class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end(),greater<int>());
        int count=0;
        long long int sum=0;
        for(int i=0;i<happiness.size();i++){
            if(k==0){
                break;
            }
            k--;
            if(happiness[i]>0){
             if(happiness[i]-count < 0){
                 happiness[i]=0;
             }
                else{
                    happiness[i] = happiness[i]-count;
                }
            }
            sum+=happiness[i];
            count++;
            
        }
        return sum;
    }
};