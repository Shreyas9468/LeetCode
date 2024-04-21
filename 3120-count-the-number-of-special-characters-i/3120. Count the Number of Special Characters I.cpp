class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int>l(26,0);
        vector<int>u(26,0);
        for(int i=0;i<word.length();i++){
            if(word[i]>='a'&&word[i]<='z'){
                l[word[i]-'a'] = 1;
            }
            else{
                u[word[i]-'A']=1;
            }
        }
        int cnt =0;
        for(int i =0;i<26;i++){
            if(l[i]==1 && u[i]==1){
                cnt++;
            }
        }
        return cnt;
    }
};