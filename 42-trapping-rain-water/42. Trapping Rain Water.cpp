class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        // Initialize arrays to store maximum heights to the left and right of each element.
        vector<int> left(n), right(n);
        
        // Initialize variables to track maximum heights encountered while traversing.
        int maxleftheight = 0;
        int maxrightheight = 0;
        
        // Calculate the maximum heights to the left of each element.
        for (int i = 0; i < n; i++) {
            maxleftheight = max(maxleftheight, height[i]);
            left[i] = maxleftheight;
        }
        
        // Calculate the maximum heights to the right of each element.
        for (int i = n - 1; i >= 0; i--) {
            maxrightheight = max(maxrightheight, height[i]);
            right[i] = maxrightheight;
        }
        for(auto it : left){
            cout<<it<<" ";
        }
        cout<<endl;
        for(auto it : right){
            cout<<it<<" ";
        }
        cout<<endl;
        // Calculate the total trapped water.
        int watertrapped = 0;
        for (int i = 0; i < n; i++) {
            // The maximum height for trapped water is the minimum of left and right max heights.
            int maxheight = min(left[i], right[i]);
            
            // Calculate the amount of trapped water at the current position.
            watertrapped = watertrapped + (maxheight - height[i]);
        }
        
        // Return the total trapped water.
        return watertrapped;
    }
};