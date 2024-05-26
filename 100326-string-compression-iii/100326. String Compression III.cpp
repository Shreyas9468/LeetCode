class Solution {
public:
    string compressedString(string word) {
        stack<char>st;
        string ans ="";
        int i=0;
        while(i<word.length()){
            int cnt =0;
            int j =i;
            while(word[i] == word[j] && cnt<9){
                cnt++;
                j++;
            }
            i =j;
           // cout<<cnt<<endl;
            ans.push_back(cnt+'0');
            ans.push_back(word[i-1]);
        }
        return ans;
    }
};