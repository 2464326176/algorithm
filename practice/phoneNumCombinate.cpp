//**************************
// Author:  yh
// Time:    2022/5/6
//**************************
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

class Solution {
public:
  vector<string> letterCombinations(string digits) {
      vector<string> keyWords, ret;
      queue<string> queue;
      vector<string> words{
          "abc",
          "def",
          "ghi",
          "jkl",
          "mno",
          "pqrs",
          "tuv",
          "wxyz"
      };

      for (auto &str: words) {
          cout << str << " ";
      }

      for (auto &num: digits) {
          keyWords.push_back(words[num - '0']);
      }

      for (auto &word: keyWords[0]) {
          queue.push(string(1, word));
      }

      for (int i = 0; i < keyWords.size() - 1; ++i) {
          for (int j = 0; j < keyWords[i].size(); ++j) {
              string ch = queue.front();
              queue.pop();
              for (int k = 0; k < keyWords[i + 1].size(); ++k) {
                  string tmp = ch + keyWords[i + 1][k];
                  queue.push(tmp);
              }
          }
      }

      while (queue.empty()) {
          ret.push_back(queue.front());
          queue.pop();
      }

      for (auto &str: ret) {
          cout << str << " ";
      }

      return ret;
  }
};

int main() {
    string s1("23");
    Solution s;
    s.letterCombinations(s1);
    return 0;
}