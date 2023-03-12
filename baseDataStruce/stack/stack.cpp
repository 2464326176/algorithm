/*
 * @Author: yh
 * @Date: 2022/10/2 13:31
 * @Description: 
 * @FilePath: stack.cpp
 */
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

vector<int> deal(string str, int index) {
    stack<int> st;
    int num = 0;
    char op = '+';
    int i = 0;
    for (i = index; i < str.size(); ++i) {
        if (isdigit(str[i])) {
            num = num * 10 + str[i] - '0';
            if (i != str.size() - 1) {
                continue;
            }
        }

        if (str[i] == '(') {
            vector<int> res = deal(str, i + 1);
            num = res[0];
            i = res[0];
            if (i != str.size() - 1) {
                continue;
            }
        }

        switch (op) {
        case '+': {
            st.push(num);
            break;
        }
        case '-': {
            st.push(-num);
            break;
        }
        case '*': {
            int tmp = st.top();
            st.pop();
            st.push(tmp * num);
            break;
        }
        default : {
            num = 0;
            if (str[i] == ')') {
                break;
            } else {
                op = str[i];
            }
            break;
        }
        }
    }
    int sum = 0;
    while (!st.empty()) {
        sum += st.top();
        st.pop();
    }

    return vector<int>{sum, i};
}

/*
 * Õ»+µÝ¹é
 */
int solve(string s) {
    return deal(s, 0)[0];
}

int main() {
    cout << solve("3+2*3*4-1");

    return 0;
}
