class Solution {
public:
    string triangleType(vector<int>& nums) {
        // we want the largest side at the end for a + b > c, c should be largest so sort
        sort(nums.begin(), nums.end());
        
        // if a + b <= c then triangle cannot be formed 
        if(nums[0] + nums[1] <= nums[2]) return "none";
        
        // if a == b & a = c then equilateral
        if(nums[0] == nums[1] && nums[0] == nums[2]) return "equilateral";
        
        // if a != b & b != c & c != a then scalene
        if(nums[0] != nums[1] && nums[0] != nums[2] && nums[2] != nums[1]) return "scalene";
        
        // else isosceles
        return "isosceles";
    }
};