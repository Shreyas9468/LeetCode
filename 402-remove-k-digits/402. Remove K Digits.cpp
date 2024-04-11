class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        string ans = "";
        for(auto it : num){
            

            while(!st.empty() && st.top() > it && k>0){
                st.pop();
                k--;
            }
            st.push(it);
            
            
            
        }

        while(k>0 && !st.empty()){
            st.pop();
            k--;
        }
        if(st.empty()){
            return "0";
        }

        while(!st.empty()){
            char ch = st.top();
            st.pop();
            ans+=ch;
        }
        reverse(ans.begin(),ans.end());
        int i;
        for( i=0;i<ans.length();i++){
            if(ans[i]!='0'){
                break;
            }
        }
        return ans.substr(i) == "" ? "0":ans.substr(i);
    }
};