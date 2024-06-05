class Solution {
public:
    bool isPalindrome(long long int x) {
     long long int n=x;long long int sum=0;  while(n!=0) {
            sum=10*sum+n%10;
            n=n/10;
        }
        if(x<0) return false;
        else {
            if(sum==x)
            {
                return true;
            }
            else return false;
        }
        
    }
};