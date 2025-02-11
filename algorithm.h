#include <iostream>
#include <vector>

using namespace std;

// 完全背包问题（二维数组实现，基于第一种递推公式）
int knapsack_v1(int num, int max_weight, vector<int>& weights, vector<int>& values);
// 完全背包问题（二维数组实现，基于第二种递推公式）
int knapsack_v2(int num, int max_weight, vector<int>& weights, vector<int>& values);
// 完全背包问题（一维数组实现，基于第一种递推公式）
int knapsack_v3(int num, int max_weight, vector<int>& weights, vector<int>& values);
// 多重背包问题（附加题）
int knapsack_v4(int num, int max_weight, vector<int>& weights, vector<int>& values,vector<int>& cnt);

// 完全背包问题（二维数组实现，基于第一种递推公式，插桩版本）
long long knapsack_v1_insert(int num, int max_weight, vector<int>& weights, vector<int>& values);
// 完全背包问题（二维数组实现，基于第二种递推公式，插桩版本）
long long knapsack_v2_insert(int num, int max_weight, vector<int>& weights, vector<int>& values);
// 完全背包问题（一维数组实现，基于第一种递推公式，插桩版本）
long long knapsack_v3_insert(int num, int max_weight, vector<int>& weights, vector<int>& values);
// 多重背包问题（附加题，插桩版本）
long long knapsack_v4_insert(int num, int max_weight, vector<int>& weights, vector<int>& values,vector<int>& cnt);