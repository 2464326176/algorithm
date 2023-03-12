//**************************
// Author:  yh
// Time:    2022/5/9
//**************************

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
  string trans(string s, int n) {
      stack<string> vStr;
      string str;

      for (int i = 0; i < n; ++i) {
          if (s[i] != ' ') {
              char ch = islower(s[i]) ? toupper(s[i]) : tolower(s[i]);
              str.push_back(ch);
          } else if (s[i] == ' ') {
              vStr.push(str);
              str.clear();
          }
      }
      vStr.push(str);
      str.clear();

      while (!vStr.empty()) {
          str.append(vStr.top());
          str.push_back(' ');
          vStr.pop();
      }
      str.erase(str.size() - 1);
      return str;
  }

  /**
  *
  * @param strs string字符串vector
  * @return string字符串
  */
  string longestCommonPrefix(vector<string> &strs) {
      int size = strs.size();

      if (size == 0) {
          return "";
      }

      for (int i = 0; i < strs[0].size(); ++i) {
          char ch = strs[0][i];
          for (int j = 1; j < size; ++j) {
              /*if ((i == strs[0].size())
                      || ((i < strs[j].size()) && (strs[0][i] != strs[j][i]))
                      || (i >= strs[j].size())) {*/
              if ((i == strs[0].size())
                  || (strs[0][i] != strs[j][i])) {
                  return strs[0].substr(0, i);
              }
          }
      }
      return strs[0];
  }

/**
 * 验证IP地址
 * @param IP string字符串 一个IP地址字符串
 * @return string字符串
 */
  vector<string> split(string IP, string spliter) {
      vector<string> vStr;
      int i;
      while ((i = IP.find(spliter)) && (i != IP.npos)) {
          vStr.push_back(IP.substr(0, i));
          IP = IP.substr(i + 1);
      }
      vStr.push_back(IP);
      return vStr;
  }

  bool isIpv4(string &IP) {
      vector<string> vStr = split(IP, ".");

      if (vStr.size() != 4) {
          return false;
      }

      for (int i = 0; i < vStr.size(); ++i) {
          if ((vStr[i].size() == 0)
              || (vStr[i].size() < 0)
              || (vStr[i].size() > 3)
              || ((vStr[i][0] == '0') && (vStr[i].size() != 1))) {
              return false;
          }

          for (int j = 0; j < vStr[i].size(); ++j) {
              if (!isdigit(vStr[i][j])) {
                  return false;
              }
          }

          int num = stoi(vStr[i]);
          if (num < 0 || num > 255) {
              return false;
          }
      }
      return true;
  }

  bool isIpv6(string &IP) {
      vector<string> vStr = split(IP, ":");

      if (vStr.size() != 8) {
          return false;
      }

      for (int i = 0; i < vStr.size(); ++i) {
          if ((vStr[i].size() == 0)
              || (vStr[i].size() > 4)) {
              return false;
          }

          for (int j = 0; j < vStr[i].size(); ++j) {
              if (!(isdigit(vStr[i][j]) || (vStr[i][j] >= 'a' && vStr[i][j] <= 'f') ||
                  (vStr[i][j] >= 'A' && vStr[i][j] <= 'F'))) {
                  return false;
              }
          }
      }
      return true;
  }

  //IPv4,   IPv6,   Neither
  string solve(string IP) {
      if (IP.empty()) {
          return "Neither";
      } else if (isIpv6(IP)) {
          return "IPv6";
      } else if (isIpv4(IP)) {
          return "IPv4";
      }
      return "Neither";
  }

  /**
* 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
* 计算两个数之和
* @param s string字符串 表示第一个整数
* @param t string字符串 表示第二个整数
* @return string字符串
*/
  string solve(string s, string t) {
      if (s.empty()) {
          return t;
      }

      if (t.empty()) {
          return s;
      }

      if (s.length() < t.length()) {
          swap(s, t);
      }

      int carry = 0;

      for (int i = s.length() - 1; i >= 0; --i) {
          int temp = s[i] - '0' + carry;
          int j = i - s.length() + t.length();

          if (j >= 0) {
              temp += t[j] - '0';
          }

          carry = temp / 10;
          s[i] = (temp % 10) + '0';
      }

      if (carry == 1) {
          s = "1" + s;
      }
      return s;
  }
};

int main() {
    Solution s;
    vector<string> vStr{
        "aaaa",
        "aa",
        "a"
    };
    string str("thIs woRLD");
    //printf("%s \n", s.trans(str, str.size()).c_str());
    //printf("%s \n", s.longestCommonPrefix(vStr).c_str());
    printf("%s \n", s.solve(string("2001:0db8:85a3:0:0:8A2E:0370:7334")).c_str());
    printf("%s \n", s.solve(string("201:209:211:0:0:7:6:5")).c_str());
    printf("%s \n", s.solve(string("1.1.1.")).c_str());
    printf("%s \n", s.solve(string("1.1.1.11")).c_str());

    return 0;
}
