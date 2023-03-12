/*
 * @Author: yh
 * @Date: 2022/10/13 23:26
 * @Description: 
 * @FilePath: \algorithm\practice\graph\graph.cpp
 */
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <array>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;
/**
 * 海洋岛屿地图可以用由0、1组成的二维数组表示，水平或者竖直方向相连的一组1表示一个岛屿。
 * 请计算最大的岛屿的面积（即岛屿中1的数目）。例如，在图15.5中有4个岛屿，其中最大的岛屿的面积为5。
 */
struct Coordinate {
    int x;
    int y;
};

int getArea(const vector<vector<int>> &grid, vector<vector<bool>> &visited, int i, int j) {
    visited[i][j] = true;
    queue<Coordinate> que;
    que.push({i, j});
    int area = 0;
    vector<vector<int>> dirs{
        {-1, 0},
        {1, 0},
        {0, 1},
        {0, -1},
    };
    while (!que.empty()) {
        Coordinate coordinate = que.front();
        que.pop();
        ++area;
        for (const auto &dirsIt: dirs) {
            int r = coordinate.x + dirsIt[0];
            int c = coordinate.y + dirsIt[1];
            if (r >= 0 && r < grid.size()
                && c >= 0 && c < grid[0].size()
                && grid[r][c] == 1 && !visited[r][c]) {
                que.push({r, c});
                visited[r][c] = true;
            }

        }
    }
    return area;
}

int maxAreaOfIsland(vector<vector<int>> grid) {
    int rows = grid.size();
    int cols = grid.size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    int maxArea = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                int area = getArea(grid, visited, i, j);
                maxArea = std::max(maxArea, area);
            }
        }
    }
    return maxArea;
}

/**
 * @brief 输入一个无序的整数数组，请计算最长的连续数值序列的长度。例如，输入数组[10, 5, 9, 2, 4, 3]，则最长的连续数值序列是[2, 3, 4, 5]，因此输出4。
 */

int bfs(set<int> &setNums, int num) {
    queue<int> que;
    que.push(num);
    setNums.erase(num);
    int length = 1;
    while (!que.empty()) {
        int num = que.front();
        que.pop();
        array<int, 2> neighbors{num - 1, num + 1};
        for (int neighbor: neighbors) {
            if (setNums.find(neighbor) != setNums.end()) {
                que.push(neighbor);
                setNums.erase(neighbor);
                length++;
            }
        }
    }
    return length;
}

int longestConsecutive(vector<int> nums) {
    set<int> setNums;
    for (const int &num: nums) {
        setNums.insert(num);
    }

    int longest = 0;
    while (!setNums.empty()) {
        auto itSetNums = setNums.begin();
        longest = max(longest, bfs(setNums, *itSetNums));
    }
    return longest;
}

/**
 * n门课程的编号从0到n-1。输入一个数组prerequisites，它的每个元素prerequisites[i]表示两门课程的先修顺序。
 * 如果prerequisites[i]=[ai, bi]，那么我们必须先修完可以bi才能修ai。请根据总课程数n和表示先修顺序的prerequisites得出一个可行的修课序列。
 * 如果有多个可行的修课序列，则输出任意序列。如果没有可行的修课序列，则输出空序列。
 * 例如，总共有4门课程，先修顺序prerequisites为[[1, 0], [2, 0], [3, 1], [3, 2]]，一个可行的修课序列是0→2→1→3。
 * @return
 */
vector<int> findOrder(int numCourses, vector<vector<int>> prerequisites) {
    vector<int> res;
    // 构造树
    unordered_multimap<int, int> graph;
    vector<int> inDegrees(numCourses, 0);
    for (auto &it: prerequisites) {
        graph.insert({it[1], it[0]});
        inDegrees[it[0]]++;
    }

    // 拓扑排序
    queue<int> que;
    for (int i = 0; i < numCourses; ++i) {
        // 入度为0， 进入
        if (inDegrees[i] == 0) {
            que.push(i);
        }
    }

    while (!que.empty()) {
        int course = que.front();
        que.pop();
        res.push_back(course);
        auto range = graph.equal_range(course);

        for_each(range.first, range.second, [&](unordered_multimap<int, int>::value_type &x) {
          inDegrees[x.second]--;
          if (inDegrees[x.second] == 0) {
              que.push(x.second);
          }
        });
        graph.erase(course);
    }

    return res;
}

/**
 * 假设一个班上有n个同学。同学之间有些是朋友，有些不是。朋友关系是可以传递的。比如A是B的直接朋友，B是C的直接朋友，那么A是C的间接朋友。
 * 我们定义朋友圈就是一组直接或间接朋友的同学。输入一个n×n的矩阵M表示班上的朋友关系，如果M[i][j]=1,那么同学i和同学j是直接朋友。
 * 请计算该班朋友圈的数目？ 例如输入数组[[1, 1, 0], [1, 1, 0], [0, 0, 1]]，则表明同学0和同学1是朋友，他们组成一个朋友圈。
 * 同学2一个人组成一个朋友圈。因此朋友圈的数目是2。
 */

void findCircle(int (*m)[3], vector<bool> &visited, int i) {
    queue<int> que;
    que.push(i);
    visited[i] = true;
    while (!que.empty()) {
        int target = que.front();
        que.pop();

        for (int k = 0; k < visited.size(); ++k) {
            if (m[target][k] == 1 && !visited[k]) {
                que.push(k);
                visited[k] = true;
            }
        }
    }
}

int findCircleNum(int (*m)[3], int length) {
    vector<bool> visited(length, false);

    int ret = 0;

    for (int i = 0; i < length; ++i) {
        if (!visited[i]) {
            findCircle(m, visited, i);
            ++ret;
        }
    }
    return ret;
}

int findFather(vector<int> fathers, int i) {
    if (fathers[i] != i) {
        fathers[i] = findFather(fathers, fathers[i]);
    }
    return fathers[i];
}

bool unionSet(vector<int> fathers, int i, int j) {
    int fatherOfI = findFather(fathers, i);
    int fatherOfJ = findFather(fathers, j);
    if (fatherOfI != fatherOfJ) {
        fathers[fatherOfI] = fatherOfJ;
        return true;
    }
    return false;
}

int findCircleNum1(int (*m)[3], int length) {
    vector<int> fathers;
    for (int i = 0; i < length; ++i) {
        fathers.push_back(i);
    }

    int ret = length;
    for (int i = 0; i < length; ++i) {
        for (int j = i + 1; j < length; ++j) {
            if (m[i][j] && unionSet(fathers, i, j)) {
                --ret;
            }
        }
    }
    return ret;
}


int main() {
//    vector<vector<int>> graph {
//        {1, 1, 0, 0, 1},
//        {1, 0, 0, 1, 0},
//        {1, 1, 0, 1, 0},
//        {0, 0, 1, 0, 0},
//    };
    //std::cout << maxAreaOfIsland(graph);

    //vector<int> nums{10, 5, 9, 2, 4, 3};
    //std::cout << longestConsecutive(nums);
//    vector<vector<int>> prerequisites{
//        {1, 0},
//        {2, 0},
//        {3, 1},
//        {4, 2},
//        {5, 3},
//        {5, 4}
//    };
//
//    for(auto &it : findOrder(6, prerequisites)) {
//        cout << it << " ";
//    }
    int m[][3]{
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };
    std::cout << findCircleNum1(m, 3);
    return 0;
}