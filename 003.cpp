class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> um;
        int start =0, curLen = 0, maxLen = 0;
        for(int i=0;i<s.length(); i++){
            if(um.count(s[i])){
                while(start <= um[s[i]]){
                    um.erase(s[start]);
                    start++;
                }
            }
            um[s[i]] = i;
            curLen = i-start+1;
            maxLen = max(curLen, maxLen);
        }
        return maxLen;
    }
};
