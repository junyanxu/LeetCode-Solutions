

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Trim start end spaces
//

class Solution {
public:

    bool isInt(string s){
        cout << "Int " << s << endl;
        if(s.length() == 0){return false;}
        int digitcount = 0;
        for(int i=0; i<s.length(); i++){
            if((s[i]-'0' < 0 || s[i]-'0'> 9) &&(s[i]!= '-'&& s[i]!='+'))
                return false;
            else if(s[i]-'0' >= 0 && s[i]-'0' <=9)
                digitcount++;
            else
                if((s[i] == '-' || s[i] == '+') && (i!=0))
                    return false;
        }
        if (digitcount == 0) {
            return false;
        }
        return true;
    }

    bool isDecimal(string s){
        cout << "Decimal " << s << endl;
        if(s.length() == 0){return false;}
        int count = 0;
        int digitcount = 0;
        for(int i=0; i<s.length(); i++){
            if((s[i]-'0' < 0 || s[i]-'0'>9) && (s[i]!= '-' && s[i]!='+' && s[i]!='.'))
                return false;
            else if(s[i]-'0' >= 0 && s[i]-'0' <=9)
                digitcount++;
            else if(s[i]=='.'){
                count ++;
            }
            else
                if((s[i] == '-' || s[i] == '+') && (i!=0))
                    return false;
        }
        if (digitcount == 0) {
            return false;
        }
        if(count > 1)
            return false;
        else
            return true;
    }

    bool isNumber(string s) {
        int start = 0;
        int end = (int)s.length()-1;
        while (s[start] == ' ') {
            start++;
        }
        while(s[end] == ' '){
            end--;
        }
        s = s.substr(start, end+1-start);
        cout << s << endl;
        int epos = -1;
        for(int i=0; i<s.length(); i++){
            if(s[i] == 'e' && epos == -1 ){
                epos = i;
            }
            else if(s[i] == 'e' && epos != -1){
                return false;
            }
        }
        if(epos == -1){
            return isDecimal(s);
        }
        else{
            return isDecimal(string(s.begin(), s.begin()+epos)) && isInt(string(s.begin()+epos+1, s.end()));
        }
    }

};
