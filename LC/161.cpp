class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        for(int i=0; i<min((int)s.size(), (int)t.size()); i++){
            if(s[i] != t[i]){
                if(s.size() > t.size())
                    return s.substr(i+1) == t.substr(i);
                else if(s.size() == t.size()){
                    cout << "sf" << endl;
                    return s.substr(i+1) == t.substr(i+1);
                }
                else
                    return s.substr(i) == t.substr(i+1);
            }
        }
        return abs((int)s.size() - (int)t.size()) == 1;
    }
};
