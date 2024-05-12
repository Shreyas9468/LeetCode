class Solution {
public:
    int findPermutationDifference(string s, string t) {
        vector<int>v(26,0);
        vector<int>v1(26,0);
        for(int i =0;i<s.length();i++){
            v[s[i]-'a'] = i;
            v1[t[i]-'a'] = i;
        }
        int sum =0;
        for(int i =0;i<26;i++){
            sum += (abs(v[i]-v1[i]));
        }
        return sum;
    }
};