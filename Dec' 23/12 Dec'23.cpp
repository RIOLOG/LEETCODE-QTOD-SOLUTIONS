class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        //sorting:
        sort(nums.begin(), nums.end(), greater<int>());
        return (nums[0]-1) * (nums[1]-1);
        
    }
};