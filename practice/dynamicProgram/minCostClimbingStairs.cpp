/*
 * @Author: yh
 * @Date: 2022/9/6 22:26
 * @Description: 
 * @FilePath: minCostClimbingStairs.cpp
 */
#include <iostream>
#include <vector>

int minCostClimbingStairs(std::vector<int> &cost) {
    int n = cost.size() + 1;
    std::vector<int> dp(n, 0);
    for (int i = 2; i <= cost.size(); ++i) {
        dp[i] = std::min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }
    return dp[cost.size()];
}

int main() {
    std::vector<int> vt({2, 50, 2, 1});
    std::cout << minCostClimbingStairs(vt);

    return 0;
}
