class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int y = -1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=0){
                y++;
                swap(nums[i], nums[y]);
            }
        }
    }
};
