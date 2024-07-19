class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l=0,r=0,o=0;
        
        for(auto it :moves){
            if(it=='L') l++;
            else if(it=='R') r++;
            else o++;
        }
        int maxdix = max(abs(r-l+o),abs(l-r+o));
        return maxdix;
    }
};