class Solution {
    public List<Integer> powerfulIntegers(int x, int y, int bound) {
        int a = (int)(Math.log(bound)/Math.log(x));
        int b = (int)(Math.log(bound)/Math.log(y));

        if(a==Integer.MAX_VALUE) a = 0;
        if(b==Integer.MAX_VALUE) b = 0;

        List<Integer> arr = new ArrayList<>();
        HashSet<Integer> hp = new HashSet<>();

        for(int i=0; i<=a; i++){
            for(int j=0; j<=b; j++){
                int k = (int)(Math.pow(x,i)+Math.pow(y,j));
                if(k>bound) break;
                else{
                    hp.add(k);
                }
            }
        }

        for(var k : hp){
            arr.add(k);
        }
        return arr;
    }
}