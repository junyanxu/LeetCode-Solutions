class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target){
      unordered_map<int, int> us;
      for(int i=0; i< nums.size(); i++){
          if(!us.count(target-nums[i]))
            us[nums[i]] = i;
          else
            return vector<int>({i, us[target-nums[i]]});
      }
      return vector<int>();
  }
};
