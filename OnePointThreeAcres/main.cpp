#include "bbg001.cpp"
#include<iostream>

using namespace std;

int main(){
  Solution s;
  auto res = s.GetRandomThree(vector<int>({1,2,3,4,5,6,7,8}));
  for(auto x: res){
    std::cout << x << std::endl;
  }
}
