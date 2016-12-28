class Solution {
public:
    int jump(vector<int>& nums) {
        int i=0;
        int curr_max = 0;
        int njumps=0;
        int last_max;
        while(curr_max < nums.size()-1){
            last_max = curr_max;
            for(; i<= last_max; i++)
                curr_max = max(curr_max, i+nums[i]);
            njumps++;
            if(curr_max == last_max)
                return 0;
        }
        return njumps;
    }
};
