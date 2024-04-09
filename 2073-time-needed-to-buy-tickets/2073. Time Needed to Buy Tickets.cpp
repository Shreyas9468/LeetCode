#include <vector>
using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int>q;
        for(int it =0;it<tickets.size();it++ ){
            q.push(it);
        }

        int time= 0;
        while(!q.empty()){
            int i=q.front();
            q.pop();
            time ++;
            tickets[i]--;
            if(tickets[i]==0 && i==k){
                return time;
            }
            if(tickets[i]>0){
                q.push(i);
            }
        }
        return time;
    }
};
