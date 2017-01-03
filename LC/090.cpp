class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        comb(res, curr, 0, nums);
        return res;
    }

    void comb(vector<vector<int>>&res, vector<int>&curr, int start, vector<int>&nums){
        res.push_back(curr);
        for(int i=start; i<nums.size(); i++){
            curr.push_back(nums[i]);
            comb(res, curr, i+1, nums);
            curr.pop_back();
        }
    }
};
