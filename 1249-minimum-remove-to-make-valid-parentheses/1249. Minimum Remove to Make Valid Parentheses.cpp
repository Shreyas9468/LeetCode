class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int count =0;
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                count++;
                st.push(s[i]);
            }
            else if(s[i]==')' ){
               if(count>0){
                count--;
                st.push(s[i]);
               }
            }
            else {
                st.push(s[i]);
            }

        }
        string ans = "";
        while(!st.empty()){
            char ch= st.top();
            ans.push_back(ch);
            st.pop();
        }
        
        
         reverse(ans.begin(),ans.end());
         cout<<ans<<endl;
         cout<<count<<endl;
      //  return "";
        if(count == 0){
          // reverse(ans.begin(),ans.end());
            return ans;
        }
        else{
            int i=ans.length()-1;
            string fans = "";
            while(count >0){
                if(ans[i]=='('){
                    ans[i]='.';
                    count--;
                }
                i--;
                    
            }
            for(auto it : ans){
                if(it !='.'){
                    fans.push_back(it);                }
            }
            cout<<fans<<endl;
       //  reverse(fans.begin(),fans.end());
        return fans;
        }
        return "";
    }
};