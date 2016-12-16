/*
   给你一个长度为n的数组作为输入, 给你一个现有功能random(i,j) 随机生成从i到j的某个值.
   希望你写一个功能, 从array里面等概率挑出三个数(就要三个,不是参数), 这三个数只要求index不同
   且等概率, 不要求值不同.
*/
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <climits>
#include <stdexcept>
#include <random>

using namespace std;

default_random_engine generator;


int random(int a, int b){
  uniform_int_distribution<int> distribution(a,b);
  return distribution(generator);
}

class Solution{
public:
  vector<int>GetRandomThree(vector<int> nums){
    if(nums.size() <  3)
      throw invalid_argument("Input length is less than 3\n");
    else{
      for(int i=0; i<3; i++){
        swap(nums[i], nums[random(i, nums.size())]);
      }
      return vector<int>(nums.begin(), nums.begin()+3);
    }
  }
};
