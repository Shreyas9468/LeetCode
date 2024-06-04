class Solution {
public:
    string digitSum(string s, int k) {
        while(s.length()>k)
        {
          string opr = "";
          for(int i=0;i<s.length();i+=k)
          {
            string ans = s.substr(i,k);
            int st_sum=0;
            for(int j=0;j<ans.length();j++)
            {
                st_sum +=ans[j]-'0';
            }
            ans  = to_string(st_sum);
            opr +=ans;
          }
          s =opr;
        }
        return s;
    }
};