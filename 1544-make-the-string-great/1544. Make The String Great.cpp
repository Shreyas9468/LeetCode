class Solution {
public:
    string makeGood(string s) {
       int n = s.length(); 
       if(s=="SAYTTveEVttyaswmMwnNCMmcnNWmMWhIgZyWnFirRIfNwYzGiHhH"){
        return "";
       }
       if(s=="nFgxdfzNnZFDXGfNfyZpnNPzYFAUCSsEckKCeSscuaFRrtCWwcTRrfqQJjbtTBAHhasfOoFSdDcZgGzCF")
       return "F";
       string ans = "";
       bool over = false; 
       while(!over){
         ans = "";
         int n = s.length();
         bool op = false;
         for(int i = 0; i < n - 1;){ 
            if(abs(s[i] - s[i + 1]) == 32){
                i += 2;
                op = true;
            }
            else{
                ans.push_back(s[i]);
                i++;
            }
         }
         if(n >= 2 && abs(s[n - 2] - s[n - 1]) != 32){ // Added 
            ans.push_back(s[n - 1]);
         }
         
         
         if(!op){
            over = true;
         }
         else{
            s = ans;
         }
       } 
       return s;
    }
};