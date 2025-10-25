class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int l = 0;
        int r = height.size() - 1;
        long long max_area = INT_MIN;
        while(l<r){
            if(height[l] > height[r]){
                long long area = (r-l) * height[r];
                max_area = max(area, max_area);                
                r--;
            }else{
                long long area = (r-l) * height[l];
                max_area = max(area, max_area);                  
                l++;
            }

        }
        return max_area;


    }
};