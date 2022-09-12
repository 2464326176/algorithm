//
// Created by 24643 on 2021/10/13.
//
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
  bool checkInclusion(string s1, string s2) {
      string s3(s1.rbegin(), s1.rend());
      return ((s2.find(s1, 0) != string::npos) || (s2.find(s3, 0) != string::npos));
  }
};

int main() {
    string src("abc");
    string dest("bbbca");

    Solution s;
    cout << s.checkInclusion(src, dest) << endl;
    return 0;
}