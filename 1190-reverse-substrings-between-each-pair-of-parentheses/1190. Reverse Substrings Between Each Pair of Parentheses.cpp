class Solution {
public:
    string reverseParentheses(string s) {

        stack<char> st;
        string ans="";
        for(char ch :s){
           
             if(ch==')'){
                string temp ="";
                while(!st.empty() && st.top()!='('){
                    temp+=st.top();
                    st.pop();
                }
                st.pop();
               // reverse(temp.begin(),temp.end());
                for(char ch1 :temp){
                    st.push(ch1);
                }

            }
            else{
                st.push(ch);
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();

        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};