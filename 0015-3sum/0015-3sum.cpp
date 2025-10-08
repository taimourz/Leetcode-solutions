class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            int right = nums.size() - 1;
            int sum;
            int left = i + 1;
            int current = nums[i];
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            while(left < right){
                sum = current + nums[left] + nums[right];
                if(sum == 0){
                    ans.push_back({current, nums[left], nums[right]});
                    while(left < right && nums[left+1] == nums[left]) left++;
                    while(left < right && nums[right-1] == nums[right]) right--;
                    left++;
                    right--;
                } 
                else if(sum < 0) left++;
                else right--;
            }
        }
        return ans;
    }
};