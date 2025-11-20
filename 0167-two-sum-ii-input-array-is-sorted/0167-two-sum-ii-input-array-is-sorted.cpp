class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;
        while(l < r){
            if(numbers[l] + numbers[r] == target) return {l+1, r+1};
            if(numbers[l] + numbers[r] < target) l++;
            if(numbers[l] + numbers[r] > target) r--;
        }
        return {};
    }
};

/*
index1 <= 1
index1 < index2 (no duplicates)
two pointer. will move based on target. 
if low then move increase left to increase it to target
if high then decrease it to make it lower


*/