class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int j=nums.size()-1;
        while(j>0 && nums[j-1]>=nums[j]){j--;}
        if(j==0){sort(nums.begin(), nums.end()); return;}
        int i=j;
        while(i < nums.size() && nums[i] > nums[j-1]){i++;}
        swap(nums[i-1], nums[j-1]);
        sort(nums.begin()+j, nums.end());
    }
};
