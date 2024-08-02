class Solution {

    // Method 1

    static boolean helper1(int x, int y, int target){
        if((x+y)<target) return false;
        if(x==target || y==target || (x+y)==target) return true;

        return target%hcf(x,y)==0;
    }

    static int hcf(int a, int b){
        if(b==0) return a;
        else return hcf(b,a%b);
    }

    // Method 2

    static boolean helper2(int x, int y, int target){
        HashSet<Integer> hp = new HashSet<>();
        Queue<Integer> q = new LinkedList<>();
        q.add(0);
        hp.add(0);

        int dir[] = {-x,x,-y,y};

        while(q.size()!=0){
            int curr = q.remove();
            if(curr==target) return true;
            for(var a : dir){
                int total = curr+a;
                if(total<0 || total>(x+y)) continue;
                if(!hp.contains(total)){
                    q.add(total);
                    hp.add(total);
                }
            }
        }
        return false;
    }
    public boolean canMeasureWater(int x, int y, int target) {
        return helper1(x,y,target);
    }
}