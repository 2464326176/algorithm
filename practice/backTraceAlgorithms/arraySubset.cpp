/*
 * @Author: yh
 * @Date: 2022/10/12 0:11
 * @Description: 
 * @FilePath: arraySubset.cpp
 */
#include <iostream>
#include <vector>

using namespace std;

/**
 * 输入一个没有重复数字的数据集合，请找出它的所有子集。例如数据集合[1, 2]有4个子集，分别是[]、[1]、[2]和[1, 2]。
 */

void findSubSets(const vector<int> &nums, int index, vector<int> &currentSubSets, vector<vector<int>> &resultSubSets) {
    if (index == nums.size()) {
        if (!currentSubSets.size()) {
            resultSubSets.push_back(vector<int>());
        } else {
            resultSubSets.push_back(currentSubSets);
        }
    } else if (index < nums.size()) {
        findSubSets(nums, index + 1, currentSubSets, resultSubSets);
        currentSubSets.push_back(nums[index]);
        findSubSets(nums, index + 1, currentSubSets, resultSubSets);
        currentSubSets.pop_back(); // 回溯
    }
}

vector<vector<int>> subsets(vector<int> nums) {
    vector<vector<int>> resultSubSets;

    if(0 == nums.size()) {
        return resultSubSets;
    }
    vector<int> currentSubSets;
    findSubSets(nums, 0, currentSubSets, resultSubSets);
    return resultSubSets;
}

template<typename T>
void print(vector<vector<T>> elems) {
    cout << "size: " << elems.size() << " \n";
    for (const auto &it : elems) {
        for (const auto &iit : it) {
            cout << iit << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void findCombineSets(int n, int k, int index, vector<int> &currentSubSets, vector<vector<int>> &resultSubSets) {
    if (k == currentSubSets.size()) {
        resultSubSets.push_back(currentSubSets);
    } else if (index < n) {
        findCombineSets(n, k, index + 1, currentSubSets, resultSubSets);
        currentSubSets.push_back(index);
        findCombineSets(n, k, index + 1, currentSubSets, resultSubSets);
        currentSubSets.pop_back(); // 回溯
    }
}

/**
 * 输入n和k，请输出从1到n里选取k个数字组成的所有组合。例如，如果n等于3，k等于2，将组成3个组合，分别时[1, 2]、[1, 3]和[2, 3]。
 */
vector<vector<int>> combineSets(int n, int k) {
    vector<vector<int>> resultSubSets;

    if(n < k) {
        return resultSubSets;
    }
    vector<int> currentSubSets;
    findCombineSets(n, k, 0, currentSubSets, resultSubSets);
    return resultSubSets;
}

void findCombineSumSets(vector<int> nums, int target, int index, vector<int> &currentSubSets, vector<vector<int>> &resultSubSets) {
    if (0 == target) {
        resultSubSets.push_back(currentSubSets);
    } else if (index < nums.size() && target > 0) {
        findCombineSumSets(nums, target, index + 1, currentSubSets, resultSubSets);
        currentSubSets.push_back(nums[index]);
        //findCombineSumSets(nums, target - nums[index], index, currentSubSets, resultSubSets); // 重复
        findCombineSumSets(nums, target - nums[index], index, currentSubSets, resultSubSets); // 不重复
        currentSubSets.pop_back(); // 回溯
    }
}

/**
 * 给你一个没有重复数字的正整数集合，请找出所有元素之和等于某个给定值的所有组合。
 * 同一个数字可以在组合中出现任意次。例如，输入整数集合[2, 3, 5]，元素之和等于8的组合有三个，分别是[2, 2, 2, 2]、[2, 3, 3]和[3, 5]。
 */
vector<vector<int>> combineSumSets(vector<int> nums, int target) {
    vector<vector<int>> resultSubSets;

    vector<int> currentSubSets;
    findCombineSumSets(nums, target, 0, currentSubSets, resultSubSets);
    return resultSubSets;
}

int getNext(vector<int> nums, int index) {
    int next = index;
    while (next < nums.size() && nums[next] == nums[index]) {
        next++;
    }

    return next;
}

void findCombineSumSets2(vector<int> nums, int target, int index, vector<int> &currentSubSets, vector<vector<int>> &resultSubSets) {
    if (0 == target) {
        resultSubSets.push_back(currentSubSets);
    } else if (index < nums.size() && target > 0) {
        findCombineSumSets2(nums, target, getNext(nums, index), currentSubSets, resultSubSets);
        currentSubSets.push_back(nums[index]);
        //findCombineSumSets(nums, target - nums[index], index, currentSubSets, resultSubSets); // 重复
        findCombineSumSets2(nums, target - nums[index], index + 1, currentSubSets, resultSubSets); // 不重复
        currentSubSets.pop_back(); // 回溯
    }
}

/**
 * 给你一个可能有重复数字的整数集合，请找出所有元素之和等于某个给定值的所有组合。
 * 输出里不得包含重复的组合。例如，输入整数集合[2, 2, 2, 4, 3, 3]，元素之和等于8的组合有两个，分别是[2, 2, 4]和[2, 3, 3]。
 */
vector<vector<int>> combineSumSets2(vector<int> nums, int target) {
    vector<vector<int>> resultSubSets;

    vector<int> currentSubSets;
    findCombineSumSets2(nums, target, 0, currentSubSets, resultSubSets);
    return resultSubSets;
}
int main() {
    vector<int> nums{1, 2, 3};
    //print(subsets(nums));
    //print(combineSets(3, 2));
    //print(combineSumSets(nums, 6));
    print(combineSumSets2({2, 2, 2, 4, 3, 3}, 8));

    return 0;
}


