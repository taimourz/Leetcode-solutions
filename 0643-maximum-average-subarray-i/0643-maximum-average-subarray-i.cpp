class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        double curr_sum = 0;
        for(int i = 0; i < k; i++){
            curr_sum += nums[i];
        }
        double max_sum = curr_sum;
        
        for(int i = k; i < nums.size() ; i++){ // [1,12,-5,-6,50,3]
            curr_sum = curr_sum - nums[i-k] + nums[i]; // 2 - 1
            max_sum = max(curr_sum, max_sum);
        }
        
        return max_sum/k;
    }
};


/*
[1,12,-5,-6,50,3], k = 4

make 2 pointers. i and j
make j go up to j, so [1 12 -5 -6]

[12 -5 -6 50]



*/