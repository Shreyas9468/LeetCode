//So our approach should be something in which we can update in the same array. As we can observe here that the maximum integers in the piles are those where we need to apply the operations to get the minimum values. We can only apply operations for K times and on each element we can apply operations as many as we want.
class Solution {
    public int minStoneSum(int[] piles, int k) {
      
         while(k > 0){ //until k > 0 we are gonna apply the operations on the maximum integers inside the piles array. Why we apply on maximum ? because if we need minimum sum of the array we need to decrease the values of the maximum value elements inside the array . that's why we are targeting the maximum value integers inside the piles array
             Arrays.sort(piles); //Sort the array so that all the higher value elements comes at the end of the array
             for(int i =  piles.length - 1 ; i >= piles.length / 2 ; i--){
// Now observe here one thing , we get maximum values only after the half of the array if the array is already sorted. Like if u have the array like [4,5,7,8]. and we need to apply 2 operations here then our target area should be after arr.length / 2. I hope u understand the loop now
                  if(k==0){
                     break; //this is the breakpoint 
                 }
                 float value = piles[i]/2f; // get the values after applying operations on the maximum value elements of piles. We store it in piles . I will tell u why below.
                 piles[i] = (int)Math.ceil(value); // Math.ceil() function always rounds up and returns the smaller integer greater than or equal to a given number.
                 k--; //decrement the k . Now here k might reach zero as well because its decrementing so we need a breakpoint to break the loop.
             }
         }
         int sum = 0;
         for(int val : piles){
             sum += val;  // Please dont tell me u dont have idea what is this.
         } 
       return sum; //your ans
    }
}