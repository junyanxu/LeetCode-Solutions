class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int start;
        int end;
        if(nums.size() < 3){return 0;}
        int myTarget=nums[0]+nums[1]+nums[2];
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            else{
                start = i+1;
                end = nums.size()-1;
                while(start < end){
                    if(abs(nums[start] + nums[end] + nums[i] -  target) < abs(myTarget-target))
                        myTarget = nums[start] + nums[end] + nums[i];
                    if(start > i+1 && nums[start] == nums[start-1])
                        start++;
                    else if(nums[start] + nums[end] + nums[i] > target){
                        end--;
                    }
                    else if(nums[start] + nums[end] + nums[i] < target){
                        start++;
                    }
                    else{
                        myTarget = target;
                        return myTarget;
                    }
                }
            }
        }
        return myTarget;
    }
};
