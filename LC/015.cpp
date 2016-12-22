/*
多把此方法和combination sum的去重作比较
*/


class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      vector<vector<int>> res;
      int start;
      int end;
      for(int i=0; i<nums.size(); i++){
          if(i>0 && nums[i] == nums[i-1]){
              continue;
          }
          start = i+1;
          end = nums.size()-1;
          while(start<end){
              if(start>i+1 && nums[start]==nums[start-1])
                start++;
              else if(nums[start] + nums[end] < -nums[i]){
                  start++;
              }
              else if(nums[start]+nums[end] > -nums[i]){
                  end--;
              }
              else{
                  res.push_back(vector<int>({nums[i], nums[start], nums[end]}));
                  start++;
              }
          }
      }
      return res;
  }
};
