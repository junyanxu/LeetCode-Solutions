class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        per(res, vector<int>(), nums);
        return res;
    }

    void per(vector<vector<int>> &res, vector<int> curr, vector<int> un){
        if(un.size() == 0){
            res.push_back(curr);
        }
        else{
            for(int i=0;i<un.size();i++){
                if(i-1>=0 && un[i] == un[i-1]){
                    continue;
                }
                else{
                    vector<int> temp = curr;
                    vector<int> temp_un = un;
                    temp_un.erase(temp_un.begin()+i);
                    temp.push_back(un[i]);
                    per(res, temp, temp_un);
                }
            }
        }
    }
};
