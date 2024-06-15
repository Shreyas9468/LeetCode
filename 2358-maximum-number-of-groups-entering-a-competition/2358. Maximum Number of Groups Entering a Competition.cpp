class Solution {
public:
    int maximumGroups(vector<int>& grades) {
      int cnt=0;
     // sort(grades.begin(),grades.end());
     int req = 1;
     int n = grades.size();
      for(int i = 0;i<grades.size();){
        if(n-i >= req){
            cnt++;
        }
        i+=req;
        req++;

      }  
      return cnt;
    }
};