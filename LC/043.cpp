class Solution {
public:
    string multiply(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int carry=0;
        int buf;
        string res(num1.length()+num2.length(), '0');
        for(int i=0; i<num1.length(); i++){
            carry = 0;
            for(int j=0; j<num2.length(); j++){
                buf = (res[i+j]-'0')+ carry + (num1[i]-'0')*(num2[j]-'0');
                carry = buf/10;
                res[i+j] = buf%10+'0';
            }
            if(carry > 0){
                res[i+num2.length()] = carry + '0';
            }
            cout << res << endl;
        }
        int i=res.length()-1;
        while(i>0 && res[i]=='0'){
            res.erase(res.begin()+i);
            i--;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
