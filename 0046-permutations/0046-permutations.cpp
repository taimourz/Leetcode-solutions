class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size() == 1){
            vector<vector<int>> temp;
            temp.push_back({nums[0]});
            return temp;
        }
        for(int i = 0; i < nums.size(); i++){
            int n = nums[i];

            vector<int> remainingElements;
            for(int j = 0; j < nums.size(); j++){
                if(i != j){
                    remainingElements.push_back(nums[j]);
                }
            }
            vector<vector<int>> temp = permute(remainingElements);
            for(int i = 0; i < temp.size(); i++){
                temp[i].push_back(n);
                ans.push_back(temp[i]);
            }
        }
        return ans;


    }
};