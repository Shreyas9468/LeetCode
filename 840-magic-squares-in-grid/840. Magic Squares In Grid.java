class Solution {

    static boolean helper(int arr[][], int a, int b, int c , int d){

        int ax[] = new int[9];

        for(int i=a; i<=c; i++){
            for(int j=b; j<=d; j++){
                if(arr[i][j]<10 && arr[i][j]>0)
                ax[arr[i][j]-1]++;
            }
        }

        for(int i=0; i<9; i++){
            if(ax[i]==0) return false;
        }

        int sum = arr[a][b]+arr[a][b+1]+arr[a][b+2];

        for(int i=a; i<=c; i++){
            int s = arr[i][b]+arr[i][b+1]+arr[i][b+2];
            if(s!=sum) {
                return false;
            }
        }

        for(int j=b; j<=d; j++){
            int s = arr[a][j]+arr[a+1][j]+arr[a+2][j];
            if(s!=sum) {
                return false;
            }
        }

        if(arr[a][b]+arr[a+1][b+1]+arr[a+2][b+2]!=sum) {
            return false;
        }
        if(arr[a][b+2]+arr[a+1][b+1]+arr[a+2][b]!=sum) {
            return false;
        }

        return true;
    }

    public int numMagicSquaresInside(int[][] arr) {

        int n = arr.length;
        int m = arr[0].length;
        int ans = 0;

        for(int i=0; i<n-2; i++){
            for(int j=0; j<m-2; j++){
                if(helper(arr,i,j,i+2,j+2)) ans++;
            }
        }    
        return ans;
    }
}