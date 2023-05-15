/*
 * @Author: yh
 * @Date: 2023-03-26 19:23:42
 * @LastEditTime: 2023-03-26 21:33:50
 * @Description:
 * @FilePath: \algorithm\baseDataStruce\graph\graph.h
 */
#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;
#ifdef __cplusplus
extern "C++" {
template <typename _CountofType, size_t _SizeOfArray> char (*__countof_helper(_CountofType (&_Array)[_SizeOfArray]))[_SizeOfArray];

#define __crt_countof(_Array) (sizeof(*__countof_helper(_Array)) + 0)
}
#else
#define __crt_countof(_Array) (sizeof(_Array) / sizeof(_Array[0]))
#endif

#ifndef _countof
#define _countof __crt_countof
#endif

// 所有路径
//一个有向无环图由n个结点（标号从0到n-1，n≥2）组成，请找出所有从结点0到结点n-1的所有路径。图用一个数组graph表示，数组的graph[i]包含所有从结点i能直接到达的结点。例如，输入数组graph为[[1,2],
//[3], [3], []]，则输出两条从结点0到结点3的路径，分别为0→1→3和0→2→3，
// vector<string> allPathsSourceTarget(int (*graph)[2]) {
//     vector<string> allPaths;

// }

// void dfsAllPaths(int (*graph)[2], int (*graph)[2], vector<string> &allPaths) {

// }

/**
 * 输入一个有整数组成的矩阵，请找出最长递增路径的长度。矩阵中的路径可以沿着上、下、左、右四个方向前行。
 * 例如，图15.10中矩阵的最长递增路径的长度为4，其中一条最长的递增路径为3→4→5→8。
 */

int longestIncPath(const vector<vector<int>> &matrix);
int dfs(const vector<vector<int>> &matrix, vector<vector<int>> &matLengths, int i, int j);

/**
 * 海洋岛屿地图可以用由0、1组成的二维数组表示，水平或者竖直方向相连的一组1表示一个岛屿。
 * 请计算最大的岛屿的面积（即岛屿中1的数目）。例如，在图15.5中有4个岛屿，其中最大的岛屿的面积为5。
 */
struct Coordinate {
    int x;
    int y;
};
int getAreaByDfs1(const vector<vector<int>> &grid, vector<vector<bool>> &visited, int i, int j);
int getAreaByDfs2(const vector<vector<int>> &grid, vector<vector<bool>> &visited, int i, int j);
int getAreaByBfs(const vector<vector<int>> &grid, vector<vector<bool>> &visited, int i, int j);
int maxAreaOfIsland(vector<vector<int>> grid);

/**
 * 输入一个无序的整数数组，请计算最长的连续数值序列的长度。例如，输入数组[10, 5, 9, 2, 4, 3]
 * 则最长的连续数值序列是[2, 3, 4, 5]，因此输出4。
 */

int bfs(set<int> &setNums, int num);

int longestConsecutive(vector<int> nums);

/**
 * n门课程的编号从0到n-1。输入一个数组prerequisites，它的每个元素prerequisites[i]表示两门课程的先修顺序。
 * 如果prerequisites[i]=[ai, bi]，那么我们必须先修完可以bi才能修ai。请根据总课程数n和表示先修顺序的prerequisites得出一个可行的修课序列。
 * 如果有多个可行的修课序列，则输出任意序列。如果没有可行的修课序列，则输出空序列。
 * 例如，总共有4门课程，先修顺序prerequisites为[[1, 0], [2, 0], [3, 1], [3, 2]]，一个可行的修课序列是0→2→1→3。
 * @return
 */
vector<int> findOrder(int numCourses, vector<vector<int>> prerequisites);

/**
 * 假设一个班上有n个同学。同学之间有些是朋友，有些不是。朋友关系是可以传递的。比如A是B的直接朋友，B是C的直接朋友，那么A是C的间接朋友。
 * 我们定义朋友圈就是一组直接或间接朋友的同学。输入一个n×n的矩阵M表示班上的朋友关系，如果M[i][j]=1,那么同学i和同学j是直接朋友。
 * 请计算该班朋友圈的数目？ 例如输入数组[[1, 1, 0], [1, 1, 0], [0, 0, 1]]，则表明同学0和同学1是朋友，他们组成一个朋友圈。
 * 同学2一个人组成一个朋友圈。因此朋友圈的数目是2。
 */

void findCircle(int (*m)[3], vector<bool> &visited, int i);
int findCircleNum(int (*m)[3], int length);
int findFather(vector<int> fathers, int i);
bool unionSet(vector<int> fathers, int i, int j);
int findCircleNum1(int (*m)[3], int length);