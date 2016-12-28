class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        per(res, vector<int>(), nums);
        return res;
    }

    void per(vector<vector<int>>&res, vector<int>curr, vector<int> un){
        if(un.size() == 0){
            res.push_back(curr);
        }
        else{
            for(int i=0; i<un.size(); i++){
                vector<int> temp = curr;
                vector<int> temp_un = un;
                temp.push_back(un[i]);
                temp_un.erase(temp_un.begin()+i);
                per(res, temp, temp_un);
            }
        }
    }
};
