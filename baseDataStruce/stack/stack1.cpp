//**************************
// Author:  yh
// Time:    2022/5/18
//**************************
#include <iostream>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

// 10进制->8进制
//Decimal
//Octal
//Hexadecimal
//Binary
string conversion(int num, int decimal) {
    stack<int> st;
    while (num) {
        st.push(num % decimal);
        num = num / decimal;
    }

    string ret;
    while (!st.empty()) {
        ret += st.top() + '0';
        st.pop();
    }
    return ret;
}

int reConversion(int num, int decimal) {
    int i = 0;
    int ret = 0;
    while (num) {
        ret += int(std::pow(decimal, i++)) * (num % 10);
        num = num / 10;
    }
    return ret;
}

// #代表前一个字符无效 @代表当前行字符均无效
void getInputString() {
    stack<char> cSt;
    char ch = getchar();
    while (ch != '\n') {
        switch (ch) {
        case '#' :cSt.pop();
            break;
        case '@' :stack<char>().swap(cSt);
            break;

        default:cSt.push(ch);
            break;
        }
        ch = getchar();
    }

    string ret;
    while (!cSt.empty()) {
        ret += cSt.top();
        cSt.pop();
    }
    printf("%s\n", ret.c_str());
}

typedef struct coordinate {
  int i;
  int y;
};

//1, 5, 1, 1, 0,
//1, 0, 1, 0, 1,
//0, 0, 0, 0, 1,
//0, 1, 1, 0, 1,
//1, 0, 0, 0, 0,
void mazePath(int (*mazePath)[5]) {
    stack<coordinate> coordinate;
    int x = 4, y = 4;

    do {

    } while ();

    return;
}

int main() {
//    printf("100->2: %s\n", conversion(100, 2).c_str());
//    printf("100->8: %s\n", conversion(100, 8).c_str());
//    printf("100->10: %s\n", conversion(100, 10).c_str());
//    printf("100->16: %s\n", conversion(100, 16).c_str());
//    printf("1100100 2: %d\n", reConversion(1100100, 2));
//    printf("144 8: %d\n", reConversion(144, 8));
//    printf("100 10: %d\n", reConversion(100, 10));
//    printf("64 16: %d\n", reConversion(64, 16));

    //getInputString();

    int intMazePath[][5] = {
        1, 5, 1, 1, 0,
        1, 0, 1, 0, 1,
        0, 0, 0, 0, 1,
        0, 1, 1, 0, 1,
        1, 0, 0, 0, 0,
    };

    mazePath(intMazePath);
    return 0;
}
