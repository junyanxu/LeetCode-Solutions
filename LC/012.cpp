class Solution {
public:
    string intToRoman(int num) {
        vector<string> dict  = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        vector<int> var({1000,900,500,400,100,90,50,40,10,9,5,4,1});
        string res="";
        while(num > 0){
            for(int i=0; i<var.size(); i++){
                if(num>=var[i]){
                    res.append(dict[i]);
                    num -= var[i];
                    break;
                }
            }
        }
        return res;
    }
};
