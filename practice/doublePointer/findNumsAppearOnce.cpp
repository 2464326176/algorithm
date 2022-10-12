/*
 * @Author: yh
 * @Date: 2022-10-01 14:36:12
 * @LastEditTime: 2022-10-01 14:41:56
 * @Description: 
 * @FilePath: \algorithm\practice\doublePointer\findNumsAppearOnce.cpp
 */


#include <algorithm>
#include <unordered_map>
#include <vector>

std::vector<int> FindNumsAppearOnce(const std::vector<int> &array) {
    std::unordered_map<int, int> mp;
    std::vector<int> res;

    for (int i = 0; i < array.size(); ++i) {
        mp[array[i]]++;
    }

    for (int i = 0; i < array.size(); ++i) {
        if (mp[array[i]] == 1) {
            res.push_back(array[i]);
        }
    }

    std::sort(res.begin(), res.end());

    return res;
}

int main() {

    return 0;
}