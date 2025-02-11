#include"algorithm.h"

// 完全背包问题（二维数组实现，基于第一种递推公式）
int knapsack_v1(int num, int max_weight, vector<int>& weights, vector<int>& values)
{
    vector<vector<int>> F(num+5,vector<int>(max_weight+5,0));
    vector<vector<int>> I(num+5,vector<int>(max_weight+5,0));

    // 初始化I数组
    for(int j=weights[1];j<=max_weight;j++)
        I[1][j]=1;

    for(int i=1;i<=num;i++)
    {
        for(int j=1;j<weights[i];j++)
        {
            F[i][j]=F[i-1][j];
            I[i][j]=I[i-1][j];
        }
        for(int j=weights[i];j<=max_weight;j++)
        {
            if(F[i-1][j]<F[i][j-weights[i]]+values[i])
            {
                F[i][j]=F[i][j-weights[i]]+values[i];
                I[i][j]=i;
            }
            else
            {
                F[i][j]=F[i-1][j];
                I[i][j]=I[i-1][j];
            }
        }
    }

    // 追踪问题的解
    vector<int> x(num+5,0);
    int i=num,j=max_weight;
    while(I[i][j])
    {
        while(I[i][j]==i)
        {
            j-=weights[i];
            x[i]++;
        }
        i=I[i][j];
    }

    // 输出背包问题结果
    // for(int i=1;i<=num;i++)
    //     cout<<x[i]<<"\t";
    // cout << "\n";

    return F[num][max_weight];
}

// 完全背包问题（二维数组实现，基于第二种递推公式）
int knapsack_v2(int num, int max_weight, vector<int>& weights, vector<int>& values)
{
    vector<vector<int>> F(num+5,vector<int>(max_weight+5,0));
    vector<vector<int>> I(num+5,vector<int>(max_weight+5,0));

    for(int j=weights[1];j<=max_weight;j++)
        I[1][j]=1;

    for(int i=1;i<=num;i++)
    {
        for(int j=1;j<=max_weight;j++)
        {
            F[i][j]=F[i-1][j];
            I[i][j]=I[i-1][j];
            for(int k=1;k<=j/weights[i];k++)
            {
                if(F[i][j]<F[i-1][j-k*weights[i]]+k*values[i])
                {
                    F[i][j]=F[i-1][j-k*weights[i]]+k*values[i];
                    I[i][j]=i;
                }
            }
        }
    }

    // 追踪问题的解
    vector<int> x(num+5,0);
    int i=num,j=max_weight;
    while(I[i][j])
    {
        while(I[i][j]==i)
        {
            j-=weights[i];
            x[i]++;
        }
        i=I[i][j];
    }

    // 输出背包问题结果
    // for(int i=1;i<=num;i++)
    //     cout<<x[i]<<"\t";
    // cout << "\n";

    return F[num][max_weight];
}
// 完全背包问题（一维数组实现，基于第一种递推公式）
int knapsack_v3(int num, int max_weight, vector<int>& weights, vector<int>& values)
{
    vector<int> F(max_weight+5,0);
    vector<int> I(max_weight+5,0);

    for(int j=weights[1];j<=max_weight;j++)
        I[j]=1;
    
    for(int j=1;j<=max_weight;j++)
    {
        for(int i=1;i<=num;i++)
        {
            if(j<weights[i])
                continue; 
            else
            {
                if(F[j]<F[j-weights[i]]+values[i])
                {
                    F[j]=F[j-weights[i]]+values[i];
                    I[j]=i;
                }
            }
        }
    }

    // 追踪问题的解
    vector<int> x(num+5,0);
    int j=max_weight;
    while(I[j])
    {
        x[I[j]]++;
        j-=weights[I[j]];
    }
    
    // 输出背包问题结果
    // for(int i=1;i<=num;i++)
    //     cout<<x[i]<<"\t";
    // cout << "\n";

    return F[max_weight];
}

// 多重背包问题（附加题）
int knapsack_v4(int num, int max_weight, vector<int>& weights, vector<int>& values,vector<int>& cnt)
{
    vector<int> F(max_weight+5,0);

    for (int i = 1; i <= num; i++) 
    {
        for (int j = max_weight; j >= weights[i]; j--) 
        {
            // 多遍历一层物品数量
            for (int k = 1; k * weights[i] <= j && k <= cnt[i]; k++) 
            {
                if(F[j]<F[j - k * weights[i]] + k * values[i])
                {
                    F[j]=F[j - k * weights[i]] + k * values[i];
                }
            }
        }
    }

    return F[max_weight];
}

// 完全背包问题（二维数组实现，基于第一种递推公式，插桩版本）
long long knapsack_v1_insert(int num, int max_weight, vector<int>& weights, vector<int>& values)
{
    vector<vector<int>> F(num+5,vector<int>(max_weight+5,0));
    vector<vector<int>> I(num+5,vector<int>(max_weight+5,0));

    // 统计访问数组的次数
    long long operation=0;

    operation++;
    for(int j=weights[1] ;j<=max_weight;j++)
        I[1][j]=1;

    for(int i=1;i<=num;i++)
    {
        for(int j=1;(operation=operation+1) && j<weights[i];j++)
        {
            F[i][j]=F[i-1][j];
            I[i][j]=I[i-1][j];
            operation+=2;
        }
        operation++;
        for(int j=weights[i];j<=max_weight;j++)
        {
            if((operation=operation+4) && F[i-1][j]<F[i][j-weights[i]]+values[i])
            {
                F[i][j]=F[i][j-weights[i]]+values[i];
                I[i][j]=i;
                operation+=3;
            }
            else
            {
                F[i][j]=F[i-1][j];
                I[i][j]=I[i-1][j];
                operation+=2;
            }
        }
    }

    // 追踪问题的解
    vector<int> x(num+5,0);
    int i=num,j=max_weight;
    while((operation=operation+1) && I[i][j])
    {
        while((operation=operation+1) && I[i][j]==i)
        {
            j-=weights[i];
            x[i]++;
            operation+=2;
        }
        i=I[i][j];
        operation++;
    }
    // 返回F[num][max_weight]结果时还有一次访存
    operation++;

    return operation;
}
// 完全背包问题（二维数组实现，基于第二种递推公式，插桩版本）
long long knapsack_v2_insert(int num, int max_weight, vector<int>& weights, vector<int>& values)
{
    vector<vector<int>> F(num+5,vector<int>(max_weight+5,0));
    vector<vector<int>> I(num+5,vector<int>(max_weight+5,0));

    long long operation=0;

    operation++;
    for(int j=weights[1];j<=max_weight;j++)
        I[1][j]=1;

    for(int i=1;i<=num;i++)
    {
        for(int j=1;j<=max_weight;j++)
        {
            F[i][j]=F[i-1][j];
            I[i][j]=I[i-1][j];
            operation+=2;
            for(int k=1;(operation=operation+1) && k<=j/weights[i];k++)
            {
                if((operation=operation+4) && F[i][j]<F[i-1][j-k*weights[i]]+k*values[i])
                {
                    F[i][j]=F[i-1][j-k*weights[i]]+k*values[i];
                    I[i][j]=i;
                    operation+=3;
                }
            }
        }
    }

    // 追踪问题的解
    vector<int> x(num+5,0);
    int i=num,j=max_weight;
    while((operation=operation+1) && I[i][j])
    {
        while((operation=operation+1) && I[i][j]==i)
        {
            j-=weights[i];
            x[i]++;
            operation+=2;
        }
        i=I[i][j];
        operation++;
    }
    // 返回F[num][max_weight]结果时还有一次访存
    operation++;

    return operation;
}
// 完全背包问题（一维数组实现，基于第一种递推公式，插桩版本）
long long knapsack_v3_insert(int num, int max_weight, vector<int>& weights, vector<int>& values)
{
    vector<int> F(max_weight+5,0);
    vector<int> I(max_weight+5,0);

    long long operation=0;

    operation++;
    for(int j=weights[1];j<=max_weight;j++)
        I[j]=1;
    
    for(int j=1;j<=max_weight;j++)
    {
        for(int i=1;i<=num;i++)
        {
            if((operation=operation+1) && j<weights[i])
                continue; 
            else
            {
                if((operation=operation+4) && F[j]<F[j-weights[i]]+values[i])
                {
                    F[j]=F[j-weights[i]]+values[i];
                    I[j]=i;
                    operation+=3;
                }
            }
        }
    }

    // 追踪问题的解
    vector<int> x(num+5,0);
    int j=max_weight;
    while((operation=operation+1) && I[j])
    {
        x[I[j]]++;
        j-=weights[I[j]];
        operation+=4;
    }
    
    // 返回F[max_weight]结果时还有一次访存
    operation++;

    return operation;
}

// 多重背包问题（附加题，插桩版本）
long long knapsack_v4_insert(int num, int max_weight, vector<int>& weights, vector<int>& values,vector<int>& cnt)
{
    vector<int> F(max_weight+5,0);

    long long operation=0;

    for (int i = 1; i <= num; i++) 
    {
        for (int j = max_weight;(operation=operation+1) && j >= weights[i]; j--) 
        {
            // 多遍历一层物品数量
            for (int k = 1;(operation=operation+2) && k * weights[i] <= j  && k <= cnt[i]; k++) 
            {
                if((operation=operation+4) && F[j]<F[j - k * weights[i]] + k * values[i])
                {
                    F[j]=F[j - k * weights[i]] + k * values[i];
                    operation+=3;
                }
            }
        }
    }
    
    // 返回F[max_weight]结果时还有一次访存
    operation++;
    return operation;
}