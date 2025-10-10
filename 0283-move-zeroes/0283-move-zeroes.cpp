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
                    // for(int n : nums) cout<<n<<", ";                    
                    break;
                }else{
                    right++;
                }
            }
            // cout<<endl;
        }






        // if(nums.size() == 1) return;
        // int lastZeroIndex = 0;
        // int right = 1;
        // while(right < nums.size()){
        //     if(nums[lastZeroIndex] == 0){
        //         int temp = nums[lastZeroIndex];
        //         nums[right] = nums[lastZeroIndex];
        //         nums[lastZeroIndex] = temp;
        //         right++;
        //         lastZeroIndex++;
        //         for(int n : nums) cout<<n<<", ";
        //     }
        //     else{
        //         right++;
        //     }
        //     cout<<endl;
        // }

    }
};


