class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return fkl(nums, (int)nums.size()-k+1, 0, nums.size()-1);
    }

    int fkl(vector<int> &nums, int k, int l, int r){
        int pivot = nums[r];
        int j = l-1;
        for(int i=l ; i<=r; i++){
            if(nums[i] <= pivot){
                j++;
                swap(nums[i], nums[j]);
            }
        }
        if(j-l+1 == k){
            return pivot;
        }
        else if(j-l+1 < k){
            return fkl(nums, k-(j-l+1), j+1, r);
        }
        else{
            return fkl(nums, k, l, j-1);
        }
    }
};
