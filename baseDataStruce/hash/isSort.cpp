/*
 * @Author: yh
 * @Date: 2022-11-15 01:59:20
 * @LastEditTime: 2022-11-15 23:39:41
 * @Description:
 * @FilePath: \algorithm\practice\hash\isSort.cpp
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;

bool isSort(string word1, string word2, vector<int> orderArray) {
    int i = 0;
    for (; i < word1.size() && i < word2.size(); ++i) {
        char ch1 = word1[i];
        char ch2 = word2[i];
        if (orderArray[ch1 - 'a'] < orderArray[ch2 - 'a']) {
            return true;
        }

        if (orderArray[ch1 - 'a'] > orderArray[ch2 - 'a']) {
            return false;
        }
    }

    return i == word1.size();
}

bool isSort(vector<string> worlds, string order) {
    vector<int> orderArray(order.size(), 0);

    for (int i = 0; i < orderArray.size(); ++i) {
        orderArray[order[i] - 'a'] = i;
    }

    for (int i = 0; i < worlds.size() - 1; ++i) {
        if (!isSort(worlds[i], worlds[i + 1], orderArray)) {
            return false;
        }
    }

    return true;
}

int main() {
    vector<string> vc{"abc", "offer", "is", "coming"};
    std::cout << isSort(vc, "zyxwvutsrqponmlkjihgfedcba") << std::endl;

    return 0; 
}