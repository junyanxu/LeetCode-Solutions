class Solution {
public:
    void sortColors(vector<int>& nums) {
        int j = -1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] < 1){
                j++;
                swap(nums[i], nums[j]);
            }
        }
        j = nums.size();
        for(int i = nums.size()-1; i>=0; i--){
            if(nums[i]>1){
                j--;
                swap(nums[i], nums[j]);
            }
        }
    }
};
