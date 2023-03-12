/*
 * @Author: yh
 * @Date: 2022/9/10 23:14
 * @Description: 
 * @FilePath: findGreatestSumOfSubArray.cpp
 */
#include <iostream>
#include <vector>

using namespace std;

// [1,-2,3,10,-4,7,2,-5]
int FindGreatestSumOfSubArray(vector<int> array) {
    vector<int> dp(array.size(), INT_MIN);
    dp[0] = array[0];
    int retMaxSum = dp[0];
    for(size_t i = 1; i < array.size(); ++i) {
        dp[i] = std::max(array[i], array[i] + dp[i - 1]);
        retMaxSum = std::max(retMaxSum, dp[i]);
    }
    return retMaxSum;
}


int main() {
    vector<int> vec{-1, 1, 2, 1};
    cout << FindGreatestSumOfSubArray(vec);

    return 0;
}