class Solution {
public:
    int getLucky(string s, int k) {
        
        vector<int> v;
        int num,sum=0,tsum=0;
        for(int i=0;i<s.length();i++)
        {                                       // -->(1)
            num =  int(s[i]-96);
            if(num>=10)
            {
                while(num>0)
                {
                    v.push_back(num%10);
                    num/=10;
                }
            }
            else
                v.push_back(num);
        }
        for(int i=0;i<v.size();i++)
            sum+=v[i];                          // -->(2)

        while(k>1)
        {                                       // -->(3)
            tsum=0;
            while(sum>0)
            {                                   // -->(4)
                tsum+=sum%10;
                sum/=10;
            }
            sum=tsum;
            k--;
        }
        return sum;                             // -->(5)
    }
};