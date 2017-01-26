class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0){
            return 0;
        }
        vector<vector<int>> h(matrix.size(), vector<int>(matrix[0].size(), -1));
        for(int i=0; i<matrix[0].size(); i++){
            h[0][i] = matrix[0][i] - '0';
        }
        for(int i=1; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                h[i][j] = (matrix[i][j] == '0'? 0: h[i-1][j] + 1);
            }
        }
        int area = -1;
        for(auto x : h){
            area = max(largestHist(x), area);
        }
        return area;
    }

    int largestHist(vector<int>&nums){
        cout << endl;
        nums.push_back(0);
        stack<int> s;
        int tmp;
        int area = -1;
        for(int i=0; i<nums.size(); i++){
            if(s.empty() || nums[s.top()] < nums[i])
                s.push(i); // Push index not value
            else{
                tmp=s.top();
                s.pop();
                if(!s.empty())
                    area = max(area, nums[tmp]*(i-s.top()-1));
                else
                    area = max(area, nums[tmp]*(i));
                i--;
            }
        }
        nums.pop_back();
        return area;
    }
};
