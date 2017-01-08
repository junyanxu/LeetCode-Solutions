class Solution {
public:
    int calculate(string s) {
        int res;
        vector<int> sign(2, 1);
        for(int i=0; i<s.length(); i++){
            if(s[i] -'0' > -1){
                int num = 0;
                while(s[i] -'0' > -1){
                    num *= 10;
                    num += s[i]-'0';
                    i++;
                }
                res += num*sign.back();
                sign.pop_back();
                i--;
            }
            else if(s[i] == '+' || s[i] == '-'){
                sign.push_back((s[i] == '+'? 1 :-1)*sign.back());
            }
            else if(s[i] == '('){
                sign.push_back(sign.back());
            }
            else if(s[i] == ')'){
                sign.pop_back();
            }
        }
        return res;
    }
};
