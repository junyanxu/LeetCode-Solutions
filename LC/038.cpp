class Solution {
public:
    string countAndSay(int n) {
        if(n == 0){
            return "";
        }
        else{
            string a = "1";
            for(int i=1; i<n; i++)
                a = process(a);
                return a;
        }
    }

    string process(string n){
        char last = n[0];
        int count = 1;
        string res="";
        for(int i=1; i< n.length(); i++){
            if(n[i] != last){
                res.push_back(count+'0');
                res.push_back(last);
                last = n[i];
                count = 1;
            }
            else{
                count++;
            }
        }
        res.push_back(count+'0');
        res.push_back(last);
        cout << res << endl;
        return res;
    }
};
