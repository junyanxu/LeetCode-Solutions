class Solution {
public:
    int longestValidParentheses(string s) {
        int curr = 0;
        vector<int> v(s.length(), 0);
        for(int i=1; i<s.length(); i++){
            if(s[i] == ')'){
                if(s[i-1] == '('){
                    if(i-2 >=0)
                        v[i] = v[i-2]+2;
                    else
                        v[i] = 2;
                }
                if(s[i-1] == ')'){
                    if(s[i - 1 - v[i-1]] == '(')
                        v[i] = v[i-1] + 2+v[i - 2 - v[i-1]];
                    else
                        v[i] = 0;
                }
            }
            else{
                v[i] = 0;
            }
        curr = (v[i] > curr? v[i]: curr);
        }

        for(auto x: v){cout << x << " ";}
        cout << endl;
        return curr;
    }
};
