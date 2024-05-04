const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int ans=0;
        int n= people.size();
        sort(people.begin(),people.end());
        vector<int>st;
        for(int i=0;i<n;i++){
            if(people[i]>=limit){
                ans++;
            }
            else{
                st.push_back(people[i]);
            }

        }
        
        int i=0,j=st.size()-1;
        while(i<=j){
           if(st[i]+st[j] <= limit){
            i++;
            j--;
           }
           else{
            j--;
           }
           ans++;
           
        }
        return ans;


        // for(int i=0;i<people.size();i+=2){
        //     if(i==people.size()-1){
        //         if(people[i]>limit){
        //             ans+=2;
        //         }
        //         else{
        //             ans++;
        //         }
        //     }
        //     else{
        //         int currsum = people[i]+people[i+1];
        //         if(currsum>limit){
        //             ans+=2;
        //         }
        //         else{
        //             ans++;
        //         }
        //     }
        // }
        // return ans;
    }
};