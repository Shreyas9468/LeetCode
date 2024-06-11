import java.util.*;

class Solution {
    public List<List<Integer>> findDifference(int[] nums1, int[] nums2) {
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> lis1 =  new ArrayList<>();
        List<Integer> lis2 = new ArrayList<>();
        HashSet<Integer> set = new HashSet<>();
        HashSet<Integer> set2 = new HashSet<>();
        HashSet<Integer> set3 = new HashSet<>();
        for(int i =0;i<nums1.length;i++){
            set.add(nums1[i]);
        }
        for(int i =0;i<nums2.length;i++){
            set2.add(nums2[i]);
        }

        for(int  it : set){
            if(set2.contains(it)){
               set3.add(it);
            }

        }
       for(int it : set){
           if(!set3.contains(it)){
               lis1.add(it);
           }
       }
       for(int it : set2){
           if(!set3.contains(it)){
               lis2.add(it);
           }
       }


       result.add(lis1);
       result.add(lis2);
       return result;

    }
}