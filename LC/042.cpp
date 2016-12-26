class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0)
            return 0;
        vector<int> left_max(height.size(), INT_MIN);
        vector<int> right_max(height.size(), INT_MIN);
        for(int i=0; i<height.size()-1; i++){
            left_max[i+1] = max(left_max[i], height[i]);
            right_max[height.size()-2-i] = max(right_max[height.size()-1-i], height[height.size()-1-i]);
        }
        int vol = 0;
        for(int i=1;i<height.size()-1; i++){
            vol = vol + max(0, min(left_max[i] - height[i], right_max[i]-height[i]));
        }
        return vol;
    }
};
