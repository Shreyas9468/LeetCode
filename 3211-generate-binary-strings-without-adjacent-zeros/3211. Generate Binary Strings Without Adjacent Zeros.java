import java.util.*;

class Solution {
    List<String> list = new ArrayList<String>();
    public void solve(String sb , int n ,int l){
        if(n==0){
            list.add(sb);
            return;
        }
        if(l==1){
            solve(sb+("0") , n-1 , 0);
            solve(sb+("1") , n-1 , 1);
        }
        else{
            solve(sb+("1") , n-1 , 1);
        }
    }
    public List<String> validStrings(int n) {
       // StringBuilder sb = new StringBuilder();
        solve("0" , n-1 , 0);
       // sb = new StringBuilder("");

        solve("1" , n-1 , 1);
        return list;
    }
}