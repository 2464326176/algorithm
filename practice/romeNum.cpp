//
// Created by 24643 on 2021/10/7.
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct hashMap {
  int key;
  string value;
} hashMap;
class Solution {
public:
  string intToRoman(int num) {
      vector<hashMap> hashString = {
          {1000, "M"},
          {900, "CM"},
          {500, "D"},
          {400, "CD"},
          {100, "C"},
          {90, "XC"},
          {50, "L"},
          {40, "XL"},
          {10, "X"},
          {9, "IX"},
          {5, "V"},
          {4, "IV"},
          {1, "I"}
      };

      int i = 0;
      string ret;
      while (num) {
          int count = num / hashString[i].key;
          while (count) {
              ret += hashString[i].value;
              --count;
          }
          num %= hashString[i].key;
          ++i;
      }
      return ret;
  }
};

int main() {
    Solution s;
    cout << s.intToRoman(7) << endl;

    return 0;
}