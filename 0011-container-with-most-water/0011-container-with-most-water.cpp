class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int max_area = INT_MIN;
        while(l < r){
            int breath = r - l;
            int heightt = min(height[l], height[r]);
            int area = breath * heightt;
            max_area = max(area, max_area);
            if(height[r] < height[l]) r--;
            else if(height[r] > height[l]) l++;
            else l++;
        }
        return max_area;
    }
};

/*
two pointers
move pointer with small height b/c we want to maximize the area.
imp thing to note x-axis starts from 0
*/


