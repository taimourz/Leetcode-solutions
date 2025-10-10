class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        for(int i = 0; i < nums.size(); i++){
            int current = nums[i];
            int right = i + 1;
            while(right < nums.size()){
                if(current == 0 && nums[right] != 0){
                    int temp = nums[right];
                    nums[right] = nums[i];
                    nums[i] = temp;
                    break;
                }else{
                    right++;
                }
            }
        }
    }
};


