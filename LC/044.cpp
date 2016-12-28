// mark的作用是把i扯回来 i,j 一起先向前试探，如果没有成功则将j返回之前状态，同时
// i返回一起跳时候的位置加一。mark时时记录有星情况下一起跳时候i的位置

class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0;
        int j = 0;
        int star = -1;
        int mark = -1;
        bool back = false;
        while(i < s.length()){
            if(s[i]==p[j] || p[j]=='?'){
                i++;
                j++;
            }
            else if(j < p.length() && p[j] == '*'){
                star = j;
                j++;
                mark = i;
            }
            else if(star != -1){
                j = star + 1;
                i = ++mark;
            }
            else{
                return false;
            }
        }
        while(j < p.length() && p[j] == '*')
            j++;
        if(i==s.length() && j==p.length())
            return true;
        return j == p.length();
    }
};
