class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> thash(255, 0);
        for(int i=0; i<t.length(); i++){
            thash[t[i]]++;
        }
        vector<int> shash(255, 0);
        int found = 0;
        int start = 0;
        int min_start=0;
        int min_len=INT_MAX;
        for(int i=0; i<s.length(); i++){
            cout << i << endl;
            if(shash[s[i]] < thash[s[i]])
                found++;
            shash[s[i]]++;
            if(found==t.length()){
                while(shash[s[start]]>thash[s[start]]){
                    shash[s[start]]--;
                    start++;
                }
                if(min_len > i-start+1){
                    min_start = start;
                    min_len = i-start+1;
                }
            }
        }
        return min_len == INT_MAX? "":s.substr(min_start, min_len);
    }
};
