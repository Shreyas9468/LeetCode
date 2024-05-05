class Solution {
public:
    int minAnagramLength(string s) {
       
        map<char, int> mp;
        for (auto it : s) {
            mp[it]++;
        }
        int v = 0;
        for(auto it : mp){
            v = __gcd(v, it.second);
           // cout<<v<<endl;
        }
         return s.length() / v;
    }


};