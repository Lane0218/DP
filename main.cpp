#include "utils.h"
#include "algorithm.h"

int main(int argc, char *argv[])
{
    // 初始化变量
    int num = 0;        // 物品个数
    int max_weight = 0; // 背包容量
    int repeat = 1;     // 同一规模下，重复运行次数

    // 解析参数
    int state = parse_args(argc, argv, num, max_weight, repeat);
    // 如果解析参数失败或输入了帮助指令，直接返回
    if (state == 0 || state == 1)
        return state;
    
    // 小规模测试部分
    // -----------------------Begin--------------------------
    
    // 打印参数
    cout << "Number of items: " << num << endl;
    cout << "Weight limit: " << max_weight << endl;
    cout << "Repeat times: " << repeat << endl;

    vector<int> weights(num + 5);
    vector<int> values(num + 5);
    vector<int> cnt(num + 5);
    // 生成一组随机样本
    generate_samples(num, max_weight, weights, values, cnt);
    // 分别运行四种算法，输出结果
    cout << knapsack_v1(num, max_weight, weights, values) << endl;
    cout << knapsack_v2(num, max_weight, weights, values) << endl;
    cout << knapsack_v3(num, max_weight, weights, values) << endl;
    cout << knapsack_v4(num, max_weight, weights, values, cnt) << endl;
    // 分别运行四种算法的插桩版本，输出操作统计结果
    cout << knapsack_v1_insert(num, max_weight, weights, values) << endl;
    cout << knapsack_v2_insert(num, max_weight, weights, values) << endl;
    cout << knapsack_v3_insert(num, max_weight, weights, values) << endl;
    cout << knapsack_v4_insert(num, max_weight, weights, values, cnt) << endl;

    // ------------------------End---------------------------

    // 大规模自动运行部分
    // -----------------------Begin--------------------------

    // // 输出问题规模
    // cout << num << "\t";
    // // 初始化时间和操作统计数组，便于后续求运行时间和操作数的平均值
    // vector<double> sum_times(4, 0.0);
    // vector<long long> operations(4, 0);
    // // 重复运行repeat次，每次均重新生成一组随机样本
    // for (int i = 0; i < repeat; i++)
    // {
    //     vector<int> weights(num + 5);
    //     vector<int> values(num + 5);
    //     vector<int> cnt(num + 5);
    //     // 生成一组随机样本
    //     generate_samples(num, max_weight, weights, values, cnt);
    //     // 分别运行四种算法，统计运行时间，保存在sum_times数组中
    //     calculate_time(num, max_weight, weights, values, cnt, sum_times);
    //     // 分别运行四种算法，统计关键操作次数，保存在operations数组中
    //     calculate_operation(num, max_weight, weights, values, cnt, operations);
    // }
    // // 根据sum_times和operations数组，输出平均运行时间和平均操作次数
    // print_output(repeat, sum_times, operations);

    // ------------------------End---------------------------

    return 0;
}