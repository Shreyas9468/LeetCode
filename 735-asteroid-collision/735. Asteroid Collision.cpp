class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(auto it :asteroids ){
            if(st.empty()){
                st.push(it);
            }
            else{
                
                int top = st.top();
                bool isvalid = (it>=0 && top >=0) || (it<=0 && top<=0);
                if(top <0||(isvalid)){
                    st.push(it);
                }
                else{
                    int size = abs(it);
                    while(!st.empty()&&size>  abs(top)&&!isvalid){
                        st.pop();
                        if(!st.empty()){
                            top = st.top();
                            isvalid = (it>=0 && top >=0) || (it<=0 && top<=0);
                        }
                        else{
                            break;
                        }
                    }

                    if(st.empty()){
                        st.push(it);
                    }
                    else if(isvalid){
                        st.push(it);
                    }
                    else{
                        top = st.top();
                        if(abs(it) == abs(top)){
                            st.pop();
                        }
                    }
                    
                }

                
            }
        }
        vector<int> abs;
        while(!st.empty()){
            int top = st.top();
            st.pop();
            abs.push_back(top);
        }
        reverse(abs.begin(),abs.end());
        return abs;
    }
};