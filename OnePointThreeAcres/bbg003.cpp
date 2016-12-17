/*

白人小哥，来就问下简历的，然后就上题。两道在collabedit实现，写完要跑testcase
give a string, find number of unique substring (given string could be extremely
long, contained duplicate alphabet a-z)

*/

#include <iostream>
#include <vector>
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
int numOfSubstring(string s){
  vector<string> suffix;
  int num=0;
  for(int i=0; i<s.length(); i++){
    suffix.push_back(s.substr(i, s.length()-i));
  }
  sort(suffix.begin(), suffix.end());
  suffix.insert(suffix.begin(), "");
  for(int i=1; i<suffix.size(); i++){
    cout << suffix[i] << endl;
    num+= (suffix[i].length() - calc(suffix[i-1], suffix[i]));
  }
  return num;
}

int calc(string a, string b){
  int count = 0;
  for(int i=0; i<a.length(); i++){
    if(a[i] == b[i])
      count++;
    else
      break;
  }
  return count;
}
};

int main(){
  Solution s;
  cout << s.numOfSubstring("asda") << endl;
}
