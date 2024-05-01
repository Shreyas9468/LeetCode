class Solution {
public:
    int compress(vector<char>& chars) {
        char ch_prev = chars[0];
        int cnt = 1;
        string s = "";
        for (int i = 1; i < chars.size(); i++) {
            if (chars[i] == ch_prev) {
                cnt++;
            } else {
                cout << cnt << endl;
                s.push_back(ch_prev);
                if (cnt > 9) {
                    string num = to_string(cnt);
                    s += num;
                } else if(cnt>1){
                    s.push_back(cnt + '0');
                }
                cnt = 1;
            }
            ch_prev = chars[i];
        }
        s.push_back(ch_prev);
        if (cnt > 1) {
            if (cnt > 9) {
                string num = to_string(cnt);
                s += num;
            } else if(cnt>1) {
                s.push_back(cnt + '0');
            }
        }
        cout << s << endl;
        for (int i = 0; i < s.length(); i++) {
            chars[i] = s[i];
        }
        return s.length();
    }
};