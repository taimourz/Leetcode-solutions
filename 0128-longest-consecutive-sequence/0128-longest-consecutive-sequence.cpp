class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       set<int> numsSet(nums.begin(), nums.end());
       int max_len = 0;
       for(int num : numsSet){ // [0,3,7,2,5,8,4,6,0,1]
            int curr_len = 0;
           if(!numsSet.count(num-1)){
                while(numsSet.count(num)){
                    curr_len += 1;
                    num++;
                }
            max_len = max(max_len, curr_len);
           }
       }

       return max_len;
    }
};

