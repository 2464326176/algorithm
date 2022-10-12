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
 * ����һ��û���ظ����ֵ����ݼ��ϣ����ҳ����������Ӽ����������ݼ���[1, 2]��4���Ӽ����ֱ���[]��[1]��[2]��[1, 2]��
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
        currentSubSets.pop_back(); // ����
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
        currentSubSets.pop_back(); // ����
    }
}

/**
 * ����n��k���������1��n��ѡȡk��������ɵ�������ϡ����磬���n����3��k����2�������3����ϣ��ֱ�ʱ[1, 2]��[1, 3]��[2, 3]��
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
        //findCombineSumSets(nums, target - nums[index], index, currentSubSets, resultSubSets); // �ظ�
        findCombineSumSets(nums, target - nums[index], index, currentSubSets, resultSubSets); // ���ظ�
        currentSubSets.pop_back(); // ����
    }
}

/**
 * ����һ��û���ظ����ֵ����������ϣ����ҳ�����Ԫ��֮�͵���ĳ������ֵ��������ϡ�
 * ͬһ�����ֿ���������г�������Ρ����磬������������[2, 3, 5]��Ԫ��֮�͵���8��������������ֱ���[2, 2, 2, 2]��[2, 3, 3]��[3, 5]��
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
        //findCombineSumSets(nums, target - nums[index], index, currentSubSets, resultSubSets); // �ظ�
        findCombineSumSets2(nums, target - nums[index], index + 1, currentSubSets, resultSubSets); // ���ظ�
        currentSubSets.pop_back(); // ����
    }
}

/**
 * ����һ���������ظ����ֵ��������ϣ����ҳ�����Ԫ��֮�͵���ĳ������ֵ��������ϡ�
 * ����ﲻ�ð����ظ�����ϡ����磬������������[2, 2, 2, 4, 3, 3]��Ԫ��֮�͵���8��������������ֱ���[2, 2, 4]��[2, 3, 3]��
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


