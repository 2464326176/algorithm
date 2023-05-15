/*
 * @Author: yh
 * @Date: 2022-08-30 23:16:16
 * @LastEditTime: 2022-08-31 00:41:47
 * @Description:
 * @FilePath: \algorithm\practice\string\isUnique.cpp
 */
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  bool isUnique(string astr) {
      int iBit = 0;
      for (int i = 0; i < astr.size(); ++i) {
          int bit = astr[i] - 'a';
          printf("[%d %d]\n", iBit, 1 << bit);
          if (iBit & 1 << bit) {
              return false;
          } else {
              iBit |= 1 << bit;
          }
      }
      return true;
  }
};

int main(int argc, char **argv) {
    Solution st;
    cout << st.isUnique("lptcode");

    for (int i = 0; i < 128; ++i) {
        printf("%c\n", i);
    }
    return 0;
}