#include <iostream>
#include <vector>
#include <string.h>
class Solution {
public:
  int lengthOfLongestSubstring(std::string s) {
      if (s.empty()) {
          return 0;
      }
      int ret = 0;
      int left = 0;
      std::string str;
      for (int i = 0; i < s.size(); ++i) {
          while (str.find(s[i]) != -1) {
              str.erase(str.begin());
              ++left;
          }
          ret = std::max(ret, (i - left + 1));
          str.push_back(s[i]);
      }
      return ret;
  }
};

int main() {
    Solution s;
    std::cout << s.lengthOfLongestSubstring("abcabcbb");

    return 0;
}