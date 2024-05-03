class Solution {
public:
    int compareVersion(string version1, string version2) {
        string num1="";
        string num2 = "";
        vector<int>v1;
        vector< int>v2;

        for(auto it :version1 ){
            if(it!='.'){
                num1.push_back(it);
            }
            else{
                v1.push_back(stoi(num1));
                num1="";
            }
        }
        v1.push_back(stol(num1));
        num1="";
        for(auto it :version2 ){
            if(it!='.'){
                num2.push_back(it);
            }
            else{
                v2.push_back(stoi(num2));
                num2="";
            }
        }
        v2.push_back(stol(num2));
        num2="";
        while(v1.size()!=v2.size()){
            if(v1.size()<v2.size()){
                v1.push_back(0);
            }
            else{
                v2.push_back(0);
            }
        }
        for(int i =0;i<v1.size();i++){
            if(v1[i]<v2[i]){
                return -1;
            }
            else if(v1[i]>v2[i]){
                return 1;
            }
        }

        return 0;

    }
};