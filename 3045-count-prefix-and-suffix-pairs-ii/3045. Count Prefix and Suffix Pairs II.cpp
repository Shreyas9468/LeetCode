class Solution {
public:
        long long countPrefixSuffixPairs(vector<string>& words) {
        map<string, long long> mp;
        map<int, int> freq;
        long long ans = 0;
        for (int i = 0; i < words.size(); i++) freq[words[i].length()]++;
        for (int i = words.size()-1; i >= 0; i--) {
            string k = words[i]; k += words[i];
            ans += mp[k];
            for (auto m : freq) {
                int j = m.first;
                if(j > words[i].length()) continue;
                string s = "";
                for(int k = 0; k < j; k++) s += words[i][k];
                for(int k = words[i].length()-j; k < words[i].length(); k++) s += words[i][k];
                mp[s]++;
            }
        }
        return ans;
    }
};