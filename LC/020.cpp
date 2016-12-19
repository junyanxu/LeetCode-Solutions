class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        char temp;
        for(int i=0; i<s.length(); i++){
            if(st.empty()){
                st.push(s[i]);
            }
            else{
                temp = st.top();
                if(temp == '}' || temp == ']' || temp == ')')
                    return false;
                else{
                    if((temp == '{' && s[i] == '}')||(temp == '[' && s[i] == ']' )||(temp == '(' && s[i] == ')' )){
                        cout << "yes" << endl;
                        st.pop();
                    }
                    else{
                        st.push(s[i]);
                    }
                }
            }
        }
        if(st.empty())
            return true;
        else
            return false;
    }
};
