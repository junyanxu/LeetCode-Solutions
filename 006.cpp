class Solution {
public:
    string convert(string s, int numRows) {
        string res="";
        if(numRows == 1){return s;}
        for(int j=1; j<= numRows; j++){
            for(int i=0; i<s.length(); i+= 2*numRows-2){
                if(j!= numRows && i+j-1 < s.length()){
                    res.push_back(s[i+j-1]);
                }
                if(j!=numRows && j!=1 && i+2*numRows-j-1<s.length()){
                    res.push_back(s[i+2*numRows-j-1]);
                }
                if(j==numRows && i+2*numRows-j-1<s.length()){
                    res.push_back(s[i+j-1]);
                }
            }
        }
        return res;
    }
};
