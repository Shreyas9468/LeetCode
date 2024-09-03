class Solution {
    public int getLucky(String s, int k) {
            int answer = 0;
            StringBuilder sb = new StringBuilder();
            for(int i = 0; i <s.length(); i++) {
                int j = s.charAt(i)-'a'+1;
                sb.append(j);
            }

            while(k>0){
                int sum = 0;
                for(int i = 0; i<sb.length(); i++){
                    sum += sb.charAt(i)-'0';
                }
                sb.setLength(0);
                sb.append(sum);
                answer = sum;


                k--;
            }
            return answer;
    }
}