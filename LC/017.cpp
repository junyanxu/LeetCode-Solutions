class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> um;
        um['0'] = " ";
        um['1'] = "";
        um['2'] = "abc";
        um['3'] = "def";
        um['4'] = "ghi";
        um['5'] = "jkl";
        um['6'] = "mno";
        um['7'] = "pqrs";
        um['8'] = "tuv";
        um['9'] = "wxyz";
        vector<string> v;
        if(digits.length()==0){return v;}
        dfs(v, digits, "", um);
        return v;
    }

    void dfs(vector<string> &v, string &digits, string curr, unordered_map<char, string>&um){
        if(digits.length()==curr.length())
            v.push_back(curr);
        else{
            int now=curr.length();
            for(auto x: um[digits[now]]){
                string temp = curr;
                temp.push_back(x);
                dfs(v, digits, temp, um);
            }
        }
    }
};
