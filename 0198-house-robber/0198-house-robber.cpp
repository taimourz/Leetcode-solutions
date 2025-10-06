class Solution {
public:
    int helper(int n, vector<int>& nums, vector<int>& dp){
        if(n < 0) return 0;
        if(dp[n] != -1) return dp[n];
        if(n==0) return nums[n];

        int skip_current = helper(n-1, nums, dp);
        int rob_current = nums[n] + helper(n-2, nums, dp);
        dp[n] = max(skip_current, rob_current);
        return dp[n];
    }
    int rob(vector<int>& nums) {
       int n = nums.size() - 1;
       vector<int> dp(n + 1, -1);
       return helper(n, nums, dp);
    }
};
