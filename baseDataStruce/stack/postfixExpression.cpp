/*
 * @Author: yh
 * @Date: 2022-11-27 19:13:18
 * @LastEditTime: 2022-11-27 19:38:40
 * @Description:
 * @FilePath: \algorithm\practice\stack\postfixExpression.cpp
 */
#include <cctype>
#include <iostream>
#include <stack>
#include <string>


using std::stack;
using std::string;

int dealPostfixExp(std::string tokens) {
    auto calculate = [](int num1, int num2, char operatorStr) {
        int ret{};
        switch (operatorStr) {
        case '+':
            ret = num1 + num2;
            break;
        case '-':
            ret = num1 - num2;
            break;
        case '*':
            ret = num1 * num2;
            break;
        case '/':
            ret = num1 / num2;
            break;
        default:
            break;
        }

        return ret;
    };

    stack<int> st;
    for (const auto &token : tokens) {
        if (std::isdigit(token)) {
            st.emplace(token - '0');
        } else {
            int num1 = st.top();
            st.pop();
            int num2 = st.top();
            st.pop();
            int ret = calculate(num1, num2, token);
            st.emplace(ret);
        }
    }

    return st.empty() ? 0 : st.top();
}

int main() {
    string postfixExp = "213*+";
    printf("postfixExp: %s, result:%d", postfixExp.c_str(), dealPostfixExp(postfixExp));
    return 0;
}