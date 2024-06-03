class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>v;
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
            {
                int check=0;
                if(nums1[i]==nums2[j])
                {
                    for(int k=j+1;k<nums2.size();k++)
                    {
                        if(nums2[k]>nums1[i])
                        {
                            v.push_back(nums2[k]);check=1;
                            break;
                        }
                    }
                    if(check) break;
                    else {
                        v.push_back(-1);break;
                    }
                }
            }
        }
        return v;
    }
};