class Solution {
public:
    bool canJump(vector<int>& nums) {
        int njump = 0;
        int curr_max = 0;
        int last_max = 0;
        int i = 0;
        while(curr_max < nums.size()-1){
            last_max = curr_max;
            for(; i<= last_max; i++){
                curr_max = max(curr_max, i+nums[i]);
            }
            njump++;
            if(curr_max == last_max)
                return false;
        }
        return true;
    }
};
