class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            int current = nums[i];
            int left = i + 1;
            int right = nums.size() - 1;

            if(i > 0 && nums[i] == nums[i-1]) continue;
            
            while(left < right){
                int current_sum = current + nums[left] + nums[right];
                if(current_sum < 0) left++;
                else if(current_sum > 0) right--;
                else{
                    ans.push_back({current, nums[left], nums[right]}); 
                    left++;
                    right--;                    
                    while(left < right && nums[left-1]  == nums[left]) left++;
                    while(left < right && nums[right+1] == nums[right]) right--;
                }
            }
        }
        return ans;
    }
};