class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        um[0] = -1;
        int max_len = 0;
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum+= nums[i];
            if(um.count(sum)){

            }
            else{
                um[sum] = i;
            }
            if(um.count(sum-k)){
                max_len = max(max_len, i-um[sum-k]);
            }
        }
        return max_len;
    }
};
