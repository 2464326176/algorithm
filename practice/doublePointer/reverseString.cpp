/*
 * @Author: yh
 * @Date: 2022-09-03 20:27:53
 * @LastEditTime: 2022-09-04 01:10:07
 * @Description: 
 * @FilePath: \algorithm\leetCode\doublePointer\reverseString.cpp
 */
#include <array>
#include <iostream>
#include <string>

std::string reverseString(std::string str) {
    if (str.empty()) {
        return str;
    }

    int leftPos = 0;
    int rightPos = str.length() - 1;
    while (leftPos < rightPos) {
        std::swap(str[leftPos], str[rightPos]);
        ++leftPos;
        --rightPos;
    }

    return str;
}

int main() {
    std::string str("abcdef");
    std::cout << reverseString(str);
    return 0;
}