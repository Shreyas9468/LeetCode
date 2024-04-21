class Solution {
public:
    int numberOfSpecialChars(string word) {
        map<char,int>mp;
        for(int i=0;i<word.length();i++){
            if(word[i]>='a'&&word[i]<='z'){
                if(mp.find(word[i])!=mp.end()){
                    mp[word[i]] = max(mp[word[i]],i);
                }
                else{
                    mp[word[i]] =i;
                }
            }
            else{
                if(mp.find(word[i])==mp.end()){
                    mp[word[i]] = i;
                } 
            }

        }
        int cnt =0;
        // for(auto it :mp){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        for(int i=0;i<26;i++){
            char chl = 'a'+i;
            char chu = 'A'+i;
            if(mp.find(chl)!=mp.end()  && mp.find(chu)!=mp.end()){
                if(mp[chl]<mp[chu]){
                    cnt++;
                }
            }  
        }
        return cnt;

    }
};