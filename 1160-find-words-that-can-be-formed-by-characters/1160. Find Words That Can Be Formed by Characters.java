import java.util.*;

import static java.util.Arrays.sort;

public class Solution {
    public boolean isSolution(String s , String s1){
        int i = 0;
        int j = 0;
      //  System.out.println(s);
      //  System.out.println(s1);
        while(i<s.length()&&j<s1.length()){
            if(s.charAt(i)==s1.charAt(j)){
                j++;
            }
            i++;
        }
        return j == s1.length();
    }
    public int countCharacters(String[] words, String chars) {
        int cnt = 0;
        char[] temp = chars.toCharArray();
         sort(temp);
         String s = new String(temp);
      //  System.out.println(s);
        for(int i = 0;i<words.length;i++){
            //System.out.println(words[i]);
            char [] temp2 = words[i].toCharArray();
            
            sort(temp2);
            String s1 = new String(temp2);
           // System.out.println(s1);
                    if(isSolution(s,s1)){
                   // System.out.println("Found " + words[i]);
                    cnt += words[i].length();
                }

        }
        return cnt;
    }
}
