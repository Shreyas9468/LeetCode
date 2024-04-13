class Solution {
public:
    int scoreOfString(string s) {
        int sum =0;
        for(int i=0;i<s.length()-1;i++){
            int a = s[i] - 'a';
            int b = s[i+1] - 'a';

            sum += abs(a-b);
        }
        return sum;
    }
};