class Solution {
public:
    int lengthOfLastWord(string s) {
      long long   int count_space=0;
      long long   int count_char=0;
      long long   int k=0; long long int j=0;
       stack<char> sta;

       sta.push('4');
       for(auto i: s)
       {
           sta.push(i);
       }
       while(true)
       {
           if(sta.top()==' '&&count_char>0)
           {
               break;
           }
           else if(sta.top()=='4')
           {
               break;
           }
           else if(sta.top()!=' ')
           {
               count_char++;sta.pop();
           }
           else {
               sta.pop();
           }
       }
       return count_char;
    }
};