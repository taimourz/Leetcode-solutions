class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1; // 5
        vector<int> ans;
        while(l <= r){ 
            int mid = l + ((r - l)/2);  // 4
            if(nums[mid] == target){ // 7
                l = mid;
                r = mid;
                while(r < nums.size() - 1 && nums[r+1] == target) r++;
                while(l > 0 && nums[l-1] == target) l--;
                return {l, r};
            }else if(nums[mid] < target){
                l = mid + 1; // l = 3
            }else{
                r = mid - 1;

            }
        }
        return {-1, -1};
        
    }
};


/*

0 + (5 - 0) = 2

3 + ((5-3)/2) = 3 + 1 = 4


*/