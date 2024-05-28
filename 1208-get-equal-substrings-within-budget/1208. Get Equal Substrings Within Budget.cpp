class Solution {
public:
    int equalSubstring(string s, string t, int maxcost) {
        int i = 0;
        int n = s.length();
        int sum = 0;
        int j = 0;
        int length = 0;
        while(j<n){
            sum += abs(s[j] -t[j]);
           while(sum>maxcost && i<=j){
            sum -= abs(s[i] - t[i]);
            i++;
           }
           length = max(length , (j-i+1));
           j++;



        }
        return length;
    }
};