class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        int minlen = INT_MAX;
        bool flag;
        char common;
        if(strs.size() == 0){return string("");}
        for(auto x: strs){minlen = min(minlen, (int)x.length());}
        cout << minlen << endl;
        for(int i=0; i<minlen; i++){
            flag = true;
            common = 0;
            for(auto x: strs){
                if(common == 0){
                    common = x[i];
                }
                else{
                    if(common != x[i]){
                        cout << x[i] << " "<<"sdf" << endl;
                        flag = false;
                        break;
                    }
                }
            }
            if(flag){
                res.push_back(common);
            }
            else{
                break;
            }
        }
        return res;
    }
};
