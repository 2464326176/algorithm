/*
 * @Author: yh
 * @Date: 2022/11/14 0:24
 * @Description: 
 * @FilePath: maxProduct.cpp
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int maxProduct(vector<string> words) {
    int length = words.size();
    vector<vector<bool>> flags(length, vector<bool>(26, false));
    for (int i = 0; i < length; ++i) {
        for (char c : words[i]) {
            flags[i][c - 'a'] = true;
        }
    }

    int ret = 0;
    for (int i =0; i < length; ++i) {
        for (int j = i + 1; j < length; ++j) {
            int k = 0;
            for (; k < 26; ++k) {
                if (flags[i][k] && flags[j][k]) {
                    break;
                }
            }

            if (k == 26) {
                int prod = words[i].length() * words[j].length();
                ret = max(prod, ret);
            }
        }
    }

    return ret;
}


int main() {
    vector<string> vc = {"abcw", "foo", "bar", "fxyz","abcdef"};
    cout << maxProduct(vc) << endl;
    return 0;
}