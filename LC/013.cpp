class Solution {
public:
    int romanToInt(string s) {
        int res=0;
        unordered_map<char,int> um({{'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000}});
        for(int i =0; i<s.length(); i++){
            if(!um.count(s[i]))
                return -1;
            else{
                if(i!=0 && um[s[i]] > um[s[i-1]]){
                    res -= (2*um[s[i-1]]);
                }
                res += um[s[i]];
            }
        }
        return res;
    }
};
