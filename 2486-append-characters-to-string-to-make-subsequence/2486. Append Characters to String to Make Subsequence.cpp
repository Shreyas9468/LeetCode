class Solution {
public:
    int appendCharacters(string s, string t) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        int j=0;
        int n1 = s.length();
        int n2 = t.length();
        for(int i=0;i<n1;i++){
            if(s[i]==t[j]){
                j++;
            }
        }
        return (n2)-j;
    }
};