class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        for(int i = 1; i < nums.size(); i++){
            int prev = nums[i-1];
            int l = i;
            while(l<nums.size()){
                if(prev == 0 && nums[l] != 0){
                    cout<<endl;
                    swap(nums[i-1], nums[l]);
                    break;
                }
                l++;
            }
        }
    }
};