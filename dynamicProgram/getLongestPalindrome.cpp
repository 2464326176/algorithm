/*
 * @Author: yh
 * @Date: 2022/9/10 23:36
 * @Description: 
 * @FilePath: getLongestPalindrome.cpp
 */
// 对于长度为n的一个字符串A（仅包含数字，大小写英文字母），请设计一个高效算法，计算其中最长回文子串的长度。
// "ababc"=>3
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int getPalindromeLength(string str, int begin, int end) {
    while (begin >= 0 && end < str.length() && str[begin] == str[end]) {
        begin--;
        end++;
    }

    return end - begin - 1;
}

int getLongestPalindrome(string str) {
    int maxLeng = 1;

    for (int i = 0; i < str.size() - 1; ++i) {
        maxLeng = std::max(maxLeng, std::max(getPalindromeLength(str, i, i), getPalindromeLength(str, i, i + 1)));
    }

    return maxLeng;
}

int main() {
    cout << getLongestPalindrome("baabccc");
    return 0;
}
