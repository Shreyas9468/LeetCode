class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        // Your implementation for minimumOperationsToMakeKPeriodic function goes here
        // Return the result
    int n = word.length();
        int ans= 0;
        map<string ,int> mp;
        //cout<<str<<endl;
        for(int i=0;i<word.length();i+=k){
            string s = word.substr(i,k);
            //cout<<s<<" ";
            mp[s]++;
            ans = max(ans, mp[s]);
        }
        n/=k;
        return n -ans;  

       // cout<<endl;
        //return ans; // Placeholder return value
    }
};