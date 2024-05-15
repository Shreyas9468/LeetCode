class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        // taking the count of left side is ALL SETBIT
        int moves=0;

        //right most setBit
        int right = 0; 

        for(int i=0; i<flips.size(); i++){
            right = max(right, flips[i]);
            if(right == i+1){
                moves++;
            }
        }
        return moves;
    }
};