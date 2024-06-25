#define ll long long
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> vx;
        vector<int> vy;
        set<int> se;
        int i = 0;
        int val = pow(x, i);
        if (x == 1) {
            vx.push_back(1);
        } else {
            while (val <= bound) {
                vx.push_back(val);
                i++;
                val = pow(x, i);
            }
        }
        i = 0;
        val = pow(y, i);
        if(y==1){
            vy.push_back(1);
        }
        else{
             while (val <= bound) {
            vy.push_back(val);
            i++;
            val = pow(y, i);
        }
        }
        for (int i = 0; i < vx.size(); i++) {
            for (int j = 0; j < vy.size(); j++) {
                int ans = vx[i] + vy[j];
                if (ans <= bound) {
                    se.insert(ans);
                } else {
                    break;
                }
            }
        }
        vector<int> v(se.begin(), se.end());
        return v;
    }
};