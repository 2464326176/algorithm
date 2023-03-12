/*
 * @Author: yh
 * @Date: 2022/9/10 14:12
 * @Description: 
 * @FilePath: longIncreaseSubsequence.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getLongIncreaseSubsequence(std::vector<int> &arr) {
    std::vector<int> dp(arr.size(), 1);
    int res = 0;

    for (int i = 1; i < arr.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                res = std::max(res, dp[i]);
            }
        }
    }

    return res;
}

int main() {
    vector<int> v({6,3,1,5,2,3,7});
    cout << getLongIncreaseSubsequence(v);
    return 0;
}
