class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> res;
        unordered_map<string, int> us;
        for(auto x: L){
            if(us.count(x))
                us[x]++;
            else
                us[x] = 1;
        }
        int wordsLen = L[0].length();
        int totalLen = wordsLen * L.size();
        if(S.length() < totalLen){return res;}
        for(int i=0; i<S.length()-totalLen+1; i++){
            if(check(S.substr(i, totalLen), us, wordsLen, L.size()))
                res.push_back(i);
        }
        return res;
    }

    bool check(string s, unordered_map<string, int> us, int &wordsLen, int total){
        int count = 0;
        for(int i=0; i<s.length(); i+= wordsLen){
            if(us.count(s.substr(i, wordsLen)) && us[s.substr(i, wordsLen)] > 0){
                us[s.substr(i, wordsLen)] --;
                count++;
            }
        }
        return count == total;
    }
};
