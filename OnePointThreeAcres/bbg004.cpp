/*

Given an array, find second maximum element
这题之前考虑过，一看就知道扫一遍就是，但还装逼下，说最笨方法是扫两边，然后开始优化，
说用两个变量，一个是first max，一个second max。从左往右，边走边更新。想法很简单，
然后他让我写。傻逼的collabedit，当时就选不了Python， 让我等会才能下手
此题说简单，但要考虑各种case，各位看下case就明白
［1，2，3］ —》 2
［1］ －》 1
［1，1］ －》1
［1，2，3，3］ －》2
就是若没有第二大就给最大，若有多个同等最大，还是都当最大，在给出第二大的. Waral 鍗

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
