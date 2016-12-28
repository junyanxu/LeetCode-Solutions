class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.length()==0)
            return 0;
        int i = (int)s.length()-1;
        while(s[i]==' ' && i>-1){i--;}
        int end = i;
        while(s[i]!=' ' && i>-1){i--;}
        return end-i;
    }
};
