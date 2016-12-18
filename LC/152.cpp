class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n= nums.size();
        if(n<=0) return 0;
        int ret, curMax, curMin;
        ret = curMax = curMin = nums[0];
        for(int i=1; i<n; i++) {
            int temp = curMax;
            curMax = max(max(curMax*nums[i], curMin*nums[i]),nums[i]);
            curMin = min(min(temp*nums[i], curMin*nums[i]),nums[i]);
            ret = max(ret, curMax);
        }
        return ret;
    }
};
