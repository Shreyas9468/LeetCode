#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        map<int, int> mp; 
        map<int, int> mp1; 
        vector<int> res;

        for (const auto& it : queries) {
            int x = it[0];
            int y = it[1];

            
            if (mp1.find(x) != mp1.end()) {
                int yd = mp1[x];
                mp[yd]--;
                if (mp[yd] == 0) {
                    mp.erase(yd); 
                }
            }

            
            mp1[x] = y;
            mp[y]++;

            
            res.push_back(mp.size());
        }

        return res;
    }
};
