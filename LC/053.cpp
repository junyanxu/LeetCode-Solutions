class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> curr_max(nums.size(), nums[0]);
        int glob_max = nums[0];
        for(int i=1; i<nums.size(); i++){
            curr_max[i] = curr_max[i-1] > 0 ?curr_max[i-1] + nums[i]:nums[i];
            glob_max = max(curr_max[i], glob_max);
        }
        return glob_max;
    }
};
