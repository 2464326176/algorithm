/*
 * @Author: yh
 * @Date: 2022-10-01 12:28:21
 * @LastEditTime: 2022-10-01 13:56:10
 * @Description:  给定一个无重复元素的整数数组nums，请你找出其中没有出现的最小的正整数
 * 进阶： 空间复杂度 O(1)O(1)，时间复杂度 O(n)O(n)
 * @FilePath: \algorithm\practice\hash\minNumDisappeared.cpp
 */

#include <unordered_map>
#include <vector>
int minNumDiaappeared(const std::vector<int>& nums) {
    int n = nums.size();

    std::unordered_map<int, int> mp;

    for (int i = 0; i < n; ++i) {
        mp[nums[i]]++;
    }

    int res = 1;
    while (mp.find(res) != mp.end()) {
        res++;
    }
    return res;
}


int main() {




    return 0;
}