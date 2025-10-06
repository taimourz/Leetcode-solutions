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

/*
- draw the recursion tree to understand the logic.
- a lot of repeated logic, so create a dp array is needed for memoization
- recursive function would need size of array with other required fields.
- base case when size is 0 means we have arrive at the end of the tree. 
- moreover, if we go out of bounds then just 0. 
- 2 possibilities, rob current or skip. 
- if current is robber then n-2 b/c we can't rob the very next house as its n-1 and adjacent.
- if skip the current, then we can rob the n-1.
- out of the above 2 options we will pick the one where robbing gives max solution.
- also remember: account for repeated calculations
- return
*/
