/*

11. Container With Most Water

*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;
        int left = 0; int right = height.size()-1;
        while(left < right){
            area = max(area, (right-left)* min(height[right], height[left]));
            if(height[right] > height[left]){
                left++;
            }
            else{
                right--;
            }
        }
        return area;
    }
};
