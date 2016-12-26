class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        combinationSum(res, vector<int>(), candidates, 0, target);
        return res;
    }

    void combinationSum(vector<vector<int>>&res, vector<int> curr, vector<int>& candidates, int start, int target){
        if(target < 0){return;}
        if(target == 0){res.push_back(curr);}
        else{
            for(int i=start; i<candidates.size(); i++){
                if(i>start && candidates[i] == candidates[i-1])
                    continue;
                else{
                    vector<int> temp = curr;
                    temp.push_back(candidates[i]);
                    combinationSum(res, temp, candidates, i+1, target-candidates[i]);
                }
            }
        }
    }
};
