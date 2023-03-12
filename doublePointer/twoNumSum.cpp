/*
 * @Author: yh
 * @Date: 2023-02-04 09:39:25
 * @LastEditTime: 2023-02-04 12:23:02
 * @Description:
 * @FilePath: \algorithm\practice\doublePointer\twoNumSum.cpp
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> twoNumSum(const vector<int> &numbers, int target) {
    int i = 0;
    int j = numbers.size() - 1;
    std::sort(numbers.begin(), numbers.end());

    vector<vector<int>> result;
    /*while (i < j && target != numbers[i] + numbers[j]) {
        if (numbers[i] + numbers[j] < target) {
            ++i;
        } else {
            --j;
        }
    }
    return {i, j};*/

    while (i < j) {
        if (target == numbers[i] + numbers[j]) {
            result.emplace_back(vector<int>{{i, j}});
        } else if (numbers[i] + numbers[j] < target) {
            ++i;
        } else {
            --j;
        }
    }
    return result;
}

int main() {
    vector<int> numbers{
        6, 7, 8, 9, 3, 4, 5, 1, 2,
    };
    vector<vector<int>> result = twoNumSum(numbers, 8);
    for (auto &items : result) {
        for (auto &item : items) {
            cout << item << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}