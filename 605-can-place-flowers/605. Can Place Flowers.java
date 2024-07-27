class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        int x=0;
        int f = flowerbed.length;
        if (f==1){
            if(n==0){
               return true;
            }
            if(flowerbed[f-1]==0){
                x++;
            } 

            if(n==x){
                return true;
            }else{
                return false;
            }
        }
        if(n==0){
            return true;
        }
        for(int i=0; i<f; i++){
            if(flowerbed[i]==0){
                if(i==0){
                   if(flowerbed[i+1]==0){
                        x++;
                        flowerbed[i]=1;
                    }

                    if(n==x){
                        return true;
                    }
                } else if(i==f-1){
                    if(flowerbed[f-2]==0){
                      x++;
                      flowerbed[i]=1;
                    }

                    if(n==x){
                        return true;
                    }
                } else{
                    if(flowerbed[i+1]==0 && flowerbed[i-1]==0){
                        x++;
                        flowerbed[i]=1;
                    }

                    if(n==x){
                        return true;
                    }
                }
            }
        }

        if(n==x){
            return true;
        }else{
            return false;
        }
    }
}