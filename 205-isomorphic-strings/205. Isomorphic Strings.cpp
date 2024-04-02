class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> mps, mpt;

        for(int i = 0; i < s.length(); i++) {
            if(mps.find(s[i]) != mps.end()) {
                if(mps[s[i]] != t[i]) {
                    return false;
                }
            }
            else {
                mps[s[i]] = t[i];
            }
            if(mpt.find(t[i]) != mpt.end()) {
                if(mpt[t[i]] != s[i]) {
                    return false;
                }
            }
            else {
                mpt[t[i]] = s[i];
            }
        }
        return true;
    }
};
