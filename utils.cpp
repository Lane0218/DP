#include "utils.h"
#include "algorithm.h"
// 打印帮助信息
void printHelp()
{
    cout << "Usage: DP [options]" << endl;
    cout << "Options:" << endl;
    cout << "  -h, -help       Display this help message and exit." << endl;
    cout << "  -n, -num        Specify the number of items." << endl;
    cout << "  -w, -weight     Specify the weight limit of the backpack." << endl;
    cout << "  -r, -repeat     Specify the number of times to repeat the same scale." << endl;
}
// 处理命令行参数
int parse_args(int argc, char *argv[], int &num, int &max_weight, int &repeat)
{
    // 返回0代表用户输入了帮助指令，返回1代表解析失败，返回2代表解析成功
    // 在main函数中可以根据返回值来做不同的处理，若返回0或1，则退出程序，若返回2，则继续执行算法

    // 遍历参数
    for (int i = 1; i < argc; i++)
    {
        string arg = argv[i];

        if (arg == "-h" || arg == "-help")
        {
            // 如果请求了帮助，则不再处理其他参数，直接结束程序
            printHelp();
            return 0;
        }
        else if (arg == "-n" || arg == "-num")
        {
            if (i + 1 < argc)
                num = stoi(argv[++i]); // 将字符串转换为整数
            else
            {
                cerr << "Error: -n option requires an argument." << endl;
                return 1;
            }
        }
        else if (arg == "-w" || arg == "-weight")
        {
            if (i + 1 < argc)
                max_weight = stoi(argv[++i]); // 将字符串转换为整数
            else
            {
                cerr << "Error: -w option requires an argument." << endl;
                return 1;
            }
        }
        else if (arg == "-r" || arg == "-repeat")
        {
            if (i + 1 < argc)
                repeat = stoi(argv[++i]); // 将字符串转换为整数
            else
            {
                cerr << "Error: -r option requires an argument." << endl;
                return 1;
            }
        }
    }
    return 2;
}

// 生成测试样本
void generate_samples(int num, int max_weight, vector<int> &weights, vector<int> &values, vector<int> &cnt)
{
    default_random_engine e(time(nullptr));
    // 随机数分布对象
    uniform_int_distribution<signed> u(2, max_weight / 1.5);

    // 生成weight值，保存到weights
    for (int i = 1; i <= num; i++)
        weights[i] = u(e);

    // 生成value值，保存到values
    for (int i = 1; i <= num; i++)
        values[i] = u(e);

    // 生成cnt值，保存到cnt
    for (int i = 1; i <= num; i++)
        cnt[i] = u(e) / 2;

    // 用于固定测试样例，便于debug
    // weights={0,9,4,4,9};
    // values={0,10,6,13,3};
    // cnt={0,2,2,1,1};

    // 用于打印随机生成的样本，便于debug
    // cout << "weights: ";
    // for(int i=0;i<=num;i++)
    //     cout << weights[i] << ",";

    // cout << "\nvalues: ";
    // for(int i=0;i<=num;i++)
    //     cout << values[i] << ",";

    // cout << "\ncnt: ";
    // for(int i=0;i<=num;i++)
    //     cout << cnt[i] << ",";
    // cout << "\n";
}

// 运行并统计运行时间
void calculate_time(int num, int max_weight, vector<int> &weights, vector<int> &values, vector<int> &cnt, vector<double> &sum_times)
{
    clock_t start_time, end_time;

    start_time = clock();
    knapsack_v1(num, max_weight, weights, values);
    end_time = clock();
    sum_times[0] += (double)(end_time - start_time) / CLOCKS_PER_SEC;

    start_time = clock();
    knapsack_v2(num, max_weight, weights, values);
    end_time = clock();
    sum_times[1] += (double)(end_time - start_time) / CLOCKS_PER_SEC;

    start_time = clock();
    knapsack_v3(num, max_weight, weights, values);
    end_time = clock();
    sum_times[2] += (double)(end_time - start_time) / CLOCKS_PER_SEC;

    start_time = clock();
    knapsack_v4(num, max_weight, weights, values, cnt);
    end_time = clock();
    sum_times[3] += (double)(end_time - start_time) / CLOCKS_PER_SEC;
}

// 运行并统计关键操作次数
void calculate_operation(int num, int max_weight, vector<int> &weights, vector<int> &values, vector<int> &cnt, vector<long long> &operations)
{
    operations[0] += knapsack_v1_insert(num, max_weight, weights, values);
    operations[1] += knapsack_v2_insert(num, max_weight, weights, values);
    operations[2] += knapsack_v3_insert(num, max_weight, weights, values);
    operations[3] += knapsack_v4_insert(num, max_weight, weights, values, cnt);
}

// 打印运行时间和关键操作次数的平均值
void print_output(int repeat, vector<double> &sum_times, vector<long long> &operations)
{
    // cout << "Average time:\n";
    for (int i = 0; i < 4; i++)
        cout << sum_times[i] / repeat << "\t";

    // cout << "Average operations:\n";
    for (int i = 0; i < 4; i++)
        cout << double(operations[i]) / repeat << "\t";
    cout << "\n";
}