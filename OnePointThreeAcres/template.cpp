/*

Description here

*/

#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <climits>
#include <stdexcept>
#include <random>

using namespace std;

class Solution{
public:
  int getSecondMax(vector<int>& nums){
    int max1 = *max_element(nums.begin(), nums.end());
    int max2 = INT_MIN;
    for(int i=0; i<nums.size(); i++){
      if(nums[i] < max1){
        max2 = max(max2, nums[i]);
      }
    }
    if(max2 == INT_MIN){
      return max1;
    }
    else{
      return max2;
    }
  }
};

int main(){
  Solution s;
  vector<int> a1({1,2,3});
  vector<int> a2({1});
  vector<int> a3({1,1});
  vector<int> a4({1,2,3,3});
  cout << s.getSecondMax(a1) << endl;
  cout << s.getSecondMax(a2) << endl;
  cout << s.getSecondMax(a3) << endl;
  cout << s.getSecondMax(a4) << endl;
}


};
