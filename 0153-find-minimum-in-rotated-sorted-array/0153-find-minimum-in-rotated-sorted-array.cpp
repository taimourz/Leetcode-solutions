class Solution {
public:
    int findMin(vector<int>& nums) {
       int l = 0;
       int r = nums.size() - 1;
       int minimum = INT_MAX;
       while(l <= r){
            int mid = l + (r - l) / 2;
            minimum = min(nums[mid], minimum);
            if(nums[mid] >= nums[l] && nums[l] > nums[r]){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
            
       }

       return minimum;
    }
};


/*
[3,4,5,1,2]
 l
         r 
     
     mid
*/