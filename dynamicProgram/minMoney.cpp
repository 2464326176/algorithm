/*
 * @Author: yh
 * @Date: 2022/9/10 1:37
 * @Description: 
 * @FilePath: minMoney.cpp
 */
#include <iostream>
#include <vector>

using namespace std;

int minMoney(vector<int> array, int aim) {
    if(aim < 1) {
        return 0;
    }
    vector<int> dp(aim + 1, aim + 1);
    dp[0] = 0;
    for(int i = 1; i <= aim; ++i) {
        for(int j = 0; j < array.size(); ++j) {
            if(array[j] <= i) {
                dp[i] = std::min(dp[i], dp[i - array[j]] + 1);
            }
        }
    }
    return dp[aim] > aim ? -1 : dp[aim];
}

int main() {




    return 0;
}


