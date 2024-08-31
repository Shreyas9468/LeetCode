class Solution {
    public int generateKey(int num1, int num2, int num3) {
        StringBuilder n1 = new StringBuilder(String.valueOf(num1));
        StringBuilder n2 = new StringBuilder(String.valueOf(num2));
        StringBuilder n3   = new StringBuilder(String.valueOf(num3));
       while(n1.length()<4){
           n1.insert(0,'0');
       }
        while(n2.length()<4){
            n2.insert(0,'0');
        }
        while(n3.length()<4){
            n3.insert(0,'0');
        }
        int k1 = Math.min(n1.charAt(0)-'0' , Math.min(n2.charAt(0)-'0' ,n3.charAt(0)-'0'));
        int k2 = Math.min(n1.charAt(1)-'0' , Math.min(n2.charAt(1)-'0' ,n3.charAt(1)-'0'));
        int k3 = Math.min(n1.charAt(2)-'0' , Math.min(n2.charAt(2)-'0' ,n3.charAt(2)-'0'));
        int k4 = Math.min(n1.charAt(3)-'0' , Math.min(n2.charAt(3)-'0' ,n3.charAt(3)-'0'));
        int val = k1 *1000 + k2 * 100 + k3 * 10 + k4 ;
        return val;

    }
}