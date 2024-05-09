class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int limit= blocks.size()-k+1;
        int recolor_bb=INT_MAX;
        for(int i=0;i<limit;i++)
        {
            int curr_step=0;
            int m=i;
            for(int j=0;j<k;j++)
            {
                if(blocks[m]=='W')
                {
                    curr_step++;
                }
                m++;
            }
            recolor_bb=min(recolor_bb,curr_step);
            m=0;
        }
        return recolor_bb;
    }
};