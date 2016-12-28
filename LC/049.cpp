class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> unmap;
        for (size_t i = 0; i < strs.size(); i++) {
            string TempString = string(strs[i]);
            sort(TempString.begin(), TempString.end());
            if(unmap.find(TempString) != unmap.end())
            {
                unmap[TempString].push_back(strs[i]);
            }
            else
            {
                unmap[TempString] = vector<string>();
                unmap[TempString].push_back(strs[i]);
            }
        }
        vector<vector<string>>result;
        for(auto i : unmap)
        {
            result.push_back(i.second);
        };
        return(result);
    }
};
