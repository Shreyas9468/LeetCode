class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>v;
        for(int i=0;i<nums.size();i++)
        {
            int check=0;
            int j;
            if(i==nums.size()-1)
            {
                j=0;
            }
            else j=i+1;
            for(;(j<nums.size());j++)
            {

                  if(nums[j]>nums[i])
                  {
                    v.push_back(nums[j]);check=1;break;
                  }
                  if(j==nums.size()-1)
                  {
                   
                  if(i==j) break;
                   j=0;
                     if(nums[j]>nums[i])
                  {
                    v.push_back(nums[j]);check=1;break;
                  }
                 // if(check) break;
                  }
                if(j==i) break;
            }
            if(check) continue;
            else {
                v.push_back(-1);}
        }
        return v;
    }
};