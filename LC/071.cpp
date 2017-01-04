class Solution {
public:
    string simplifyPath(string path) {
        vector<string>res;
        path.insert(path.begin(), '/');
        path.push_back('/');
        string temp;
        int last = 0;
        for(int i=1; i<path.length(); i++){
            if(path[i] == '/'){
                temp = path.substr(last+1, i-last-1);
                if(temp == ".."){
                    if(res.size() > 0)
                        res.pop_back();
                }
                else if(temp != "." && !temp.empty()){
                    res.push_back(temp);
                }
                else{
                }
                last = i;
            }
        }
        string simple="/";
        for(int i=0; i<res.size(); i++){
            simple.append(res[i]+"/");
        }
        if(res.size()!=0)
            simple.pop_back();
        return simple;
    }
};
