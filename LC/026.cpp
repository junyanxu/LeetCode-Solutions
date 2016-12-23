class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j=-1;
        for(int i=0; i<nums.size(); i++){
            if(j==-1 || nums[i]!= nums[j]){
                j++;
                swap(nums[i], nums[j]);
            }
        }
        return j+1;
    }
};
