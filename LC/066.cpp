class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        int a = 1;
        for(int i=0; i<digits.size(); i++){
            a = a+digits[i];
            digits[i] = a%10;
            a = a/10;
        }
        if(a>0){digits.push_back(a);}
        return vector<int>(digits.rbegin(), digits.rend());
    }
};
