class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       
       int global_max = nums[0];
       int currentSum = nums[0];
       for(int i = 1; i < nums.size(); i++){
            currentSum = max(nums[i], currentSum + nums[i]);
            global_max = max(global_max, currentSum);
       }
       return global_max;
       
    }
};
