/*
 * @Author: yh
 * @Date: 2022/9/6 22:26
 * @Description:
 * @FilePath: \algorithm\dynamicProgram\minCostClimbingStairs.cpp
 */
#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

// 自上而下的求解方式
int minCost1(std::vector<int> &cost, size_t i) {
    if (i < 2) {
        return cost[i];
    }
    return std::min(minCost1(cost, i - 1), minCost1(cost, i - 2)) + cost[i];
}

int minCostClimbingStairs1(std::vector<int> &cost) {
    size_t size = cost.size();
    return std::min(minCost1(cost, size - 1), minCost1(cost, size - 2));
}

void minCost2(std::vector<int> &cost, std::vector<int> &dp, size_t i) {
    if (i < 2) {
        dp[i] = cost[i];
    } else if (dp[i] == 0) {
        minCost2(cost, dp, i - 1);
        minCost2(cost, dp, i - 2);
        dp[i] = std::min(dp[i - 1], dp[i - 2]) + cost[i];
    }
}

int minCostClimbingStairs2(std::vector<int> &cost) {
    size_t size = cost.size();
    std::vector<int> dp(size, 0);
    minCost2(cost, dp, size - 1);
    return std::min(dp[size - 1], dp[size - 2]);
}

/*int minCostClimbingStairs2(std::vector<int> &cost) {
    int n = cost.size() + 1;
    std::vector<int> dp(n, 0);
    for (int i = 2; i <= cost.size(); ++i) {
        dp[i] = std::min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }
    return dp[cost.size()];
}*/

// 自下而上的求解方式
// O(N), O(N)
int minCostClimbingStairs3(std::vector<int> &cost) {
    size_t size = cost.size();
    std::vector<int> dp(cost);
    for (int i = 2; i < size; ++i) {
        dp[i] = std::min(dp[i - 1], dp[i - 2]) + cost[i];
    }
    return std::min(dp[size - 1], dp[size - 2]);
}

// O(N), O(1)
int minCostClimbingStairs4(std::vector<int> &cost) {
    size_t size = cost.size();
    std::array<int, 2> dp{cost[0], cost[1]};
    for (int i = 2; i < size; ++i) {
        dp[i % 2] = std::min(dp[0], dp[1]) + cost[i];
    }
    return std::min(dp[0], dp[1]);
}

int main() {
    std::vector<int> vt({1, 100, 1, 1, 100, 1, 100, 1, 100, 1, 100, 1, 100});
    std::cout << minCostClimbingStairs1(vt) << std::endl;
    std::cout << minCostClimbingStairs2(vt) << std::endl;
    std::cout << minCostClimbingStairs3(vt) << std::endl;
    std::cout << minCostClimbingStairs4(vt) << std::endl;
    return 0;
}
