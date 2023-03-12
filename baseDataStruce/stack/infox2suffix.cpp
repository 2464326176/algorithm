/*
 * @Author: yh
 * @Date: 2022-08-30 00:17:15
 * @LastEditTime: 2022-09-03 00:04:51
 * @Description: 
 * @FilePath: \algorithm\practice\stack\infox2suffix.cpp
 */
#include <ctype.h>
#include <iostream>
#include <stack>
#include <string>

int solve(string s) {


}

char getPriority(char a, char b) {
    if (a == '(' && b == ')') {
        return '=';
    } else if (a == '(' || b == '(' || ((a == '+' || a == '-') && (b == '*' || b == '/'))) {
        return '<';
    }
    return '>';
}

int main() {
    // 2   9   6   3   /  +  5  -  *  4  +     
    std::string str("2*(9+6/3-5)+4");
    std::stack<char> sk;
    for (int i = 0; i < str.size(); i++) {
        if (isdigit(str[i])) {
            std::cout << str[i];
        } else {
            while (true) {
                if (sk.empty() || getPriority(sk.top(), str[i]) == '<') {
                    sk.push(str[i]);
                    break;
                } else if (getPriority(sk.top(), str[i]) == '>' || (!sk.empty() && i == str.size())) {
                    std::cout << sk.top();
                    sk.pop();
                } else {
                    //std::cout << sk.top();
                    sk.pop();
                    break;
                }
            }
        }
    }

    while (!sk.empty()) {
        std::cout << sk.top();
        sk.pop();
    }
    return 0;
}