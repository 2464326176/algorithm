/*
 * @Author: yh
 * @Date: 2022/11/13 15:09
 * @Description: 
 * @FilePath: intStringAdd.cpp
 */

#include <iostream>
#include <string>

using namespace std;

string addBinary(string a, string b) {
    string ret;
    int i = a.size() - 1;
    int j = b.size() - 1;
    int carryBit = 0;
    while (i >= 0 || j >= 0) {
        int digitA = i >= 0 ? a[i--] - '0' : 0;
        int digitB = j >= 0 ? b[j--] - '0' : 0;
        int sum = digitA + digitB + carryBit;
        carryBit = sum >= 2 ? 1 : 0;
        sum = sum >= 2 ? sum -2 : sum;
        ret.insert(ret.begin(), sum + '0');
    }

    if (carryBit == 1) {
        ret.insert(ret.begin(), '1');
    }

    return ret;
}

int main() {
    printf("%s \n", addBinary("11", "111").c_str());


    return 0;
}