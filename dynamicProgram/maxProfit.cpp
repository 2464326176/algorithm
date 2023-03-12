/*
 * @Author: yh
 * @Date: 2022/9/6 23:15
 * @Description: 
 * @FilePath: maxProfit.cpp
 */
#include <iostream>
#include <vector>

/**
假设你有一个数组prices，长度为n，其中prices[i]是股票在第i天的价格，请根据这个价格数组，返回买卖股票能获得的最大收益
1.你可以买入一次股票和卖出一次股票，并非每天都可以买入或卖出一次，总共只能买入和卖出一次，且买入必须在卖出的前面的某一天
2.如果不能获取到任何利润，请返回0
3.假设买入卖出均无手续费*/
int maxProfit1(std::vector<int> &prices) {
    size_t n = prices.size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(2, 0));
    dp[0][0] = 0; // 不持股
    dp[0][1] = -prices[0]; // 持股
    for (int i = 1; i < n; ++i) {
        dp[i][0] = std::max(dp[i - 1][1] + prices[i], dp[i - 1][0]);
        dp[i][1] = std::max(-prices[i], dp[i - 1][1]);
    }
    return dp[n - 1][0];
}
/*假设你有一个数组prices，长度为n，其中prices[i]是某只股票在第i天的价格，请根据这个价格数组，返回买卖股票能获得的最大收益
1. 你可以多次买卖该只股票，但是再次购买前必须卖出之前的股票
2. 如果不能获取收益，请返回0
3. 假设买入卖出均无手续费*/
int maxProfit2(std::vector<int> &prices) {
    size_t n = prices.size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(2, 0));
    dp[0][0] = 0; // 不持股
    dp[0][1] = -prices[0]; // 持股
    for (int i = 1; i < n; ++i) {
        dp[i][0] = std::max(dp[i - 1][1] + prices[i], dp[i - 1][0]);
        dp[i][1] = std::max(dp[i - 1][0] - prices[i], dp[i - 1][1]);
    }
    return dp[n - 1][0];
}

/*
假设你有一个数组prices，长度为n，其中prices[i]是某只股票在第i天的价格，请根据这个价格数组，返回买卖股票能获得的最大收益
1. 你最多可以对该股票有两笔交易操作，一笔交易代表着一次买入与一次卖出，但是再次购买前必须卖出之前的股票
2. 如果不能获取收益，请返回0
3. 假设买入卖出均无手续费
dp[i][0]表示到第i天为止没有买过股票的最大收益
dp[i][1]表示到第i天为止买过一次股票还没有卖出的最大收益
dp[i][2]表示到第i天为止买过一次也卖出过一次股票的最大收益
dp[i][3]表示到第i天为止买过两次只卖出过一次股票的最大收益
dp[i][4]表示到第i天为止买过两次同时也买出过两次股票的最大收益
 */
int maxProfit(std::vector<int> &prices) {
    size_t n = prices.size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(5, -10000));
    dp[0][0] = 0; // 不持股
    dp[0][1] = -prices[0]; // 持股
    for (int i = 1; i < n; ++i) {
        dp[i][0] = dp[i - 1][0];
        dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        dp[i][2] = std::max(dp[i - 1][1] + prices[i], dp[i - 1][2]);
        dp[i][3] = std::max(dp[i - 1][2] - prices[i], dp[i - 1][3]);
        dp[i][4] = std::max(dp[i - 1][3] + prices[i], dp[i - 1][4]);
    }
    return std::max(dp[n - 1][2], std::max(0, dp[n - 1][4]));
}

int main() {
    std::vector<int> vt{8, 9, 3, 5, 1, 3};
    std::cout << maxProfit(vt) << std::endl;
    return 0;
}
