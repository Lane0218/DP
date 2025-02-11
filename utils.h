#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <cmath>
#include <cstdlib>

using namespace std;

// 打印帮助信息
void printHelp();
// 处理命令行参数
int parse_args(int argc, char* argv[], int& num, int& max_weight, int& repeat);
// 生成测试样本
void generate_samples(int num, int max_weight, vector<int>& weights, vector<int>& values,vector<int>& cnt);
// 运行并统计运行时间
void calculate_time(int num, int max_weight,vector<int>& weights, vector<int>& values,vector<int>& cnt,vector<double>& sum_times);
// 运行并统计关键操作次数
void calculate_operation(int num, int max_weight,vector<int>& weights, vector<int>& values,vector<int>& cnt,vector<long long>& operations);
// 打印运行时间和关键操作次数的平均值
void print_output(int repeat,vector<double>& sum_times,vector<long long>& operations);