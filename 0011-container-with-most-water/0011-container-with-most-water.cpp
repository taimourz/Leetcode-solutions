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
two pointers obviously.
we need to move the pointer which is smaller otherwise water overflows
also keep track of max area. 
what is length breath. breath (smaller) length (j - i)

*/


