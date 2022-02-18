#include "stream.h"

//#include <bits/stdc++.h>
#include <cmath>
#include <cstring>
#include <map>
#include <algorithm>

using namespace tools;

int array_f[20] = {-1};

// 自顶向下: 备忘录法
int F(int i)
{
    int t;
    if (array_f[i] != -1) return array_f[i];
    if (i == 0) return 0;
    if (i == 1) return 1;
    if (i > 1) t = F(i -1) + F(i -2);
    return array_f[i] = t;
    // array_f[i-1] = F(i-1);
    // return F(i -1) + F(i -2);
}

struct Item
{
    Item(int a, int b) : size(a), val(b) {}
    int size{0};
    int val{0};
};

Item array_k[5] = {{3, 4}, {4, 5}, {7, 10}, {8, 11}, {9, 13}};

// knapsack
// 初级的背包问题，重复计算的部分是：
int knapsack(int cap)
{
    int i, space, max = 0, t;
    for (i = 0; i < 5; i++)
    {
        // 算出剩余的空间
        space = cap - array_k[i].size;
        if (space >= 0)
        {
            t = array_k[i].val + knapsack(space);
            if (t  > max)
                max = t;
        }
    }
    return max;
}

// 记录背包中剩余空间的最大价值量
int remain_space_array[101];

// 优化后的背包问题
int knapsack2(int cap)
{
    int i, space, max = 0, t;
    for (i = 0; i < 5; i++)
    {
        space = cap - array_k[i].size;
        if (space >= 0)
        {
            if (remain_space_array[space] == -1)
                remain_space_array[space] = knapsack2(space);

            t = array_k[i].val + remain_space_array[space];
            if (t > max)
                max = t;
        }
    }
    return max;
}

// 优化后的背包问题2
int knapspack3(int cap)
{
    if (remain_space_array[cap] != -1) return remain_space_array[cap];
    int i, space, max = 0, t;
    for (i = 0; i < 5; i++)
    {
        space = cap - array_k[i].size;
        if (space >= 0)
        {
            t = array_k[i].val + knapspack3(space);
            if (t > max)
                max = t;
        }
    }

    remain_space_array[cap] = max;
    return max;
}

// RMQ算法 区间查询最值问题

// dp[i][j] 表示从i开始，长度为2^j区间内的最大值
// 动态转移方程:
// dp[i][j]=max(dp[i][j-1],dp[i+2^(j-1)][j-1]);  分别求前后两段的最大值
// 因为 2 * 2^(j-1) = 2^j

// int num[20] = {222, 16, 884, 104, 740, 789, 498, 523, 525, 950,
//                582, 198, 35, 571, 940, 965, 116, 922, 864, 407};

int num[20];

int k = log2(20) + 1;  // j的最大范围
int dp[21][21];


// 生成20个元素数组的动态规划数组：
// 提前将num数组中的数据比较结果放在dp[i][j]中
void dp_array_init()
{
    // 先填充一列信息, i 从0开始
    for (int i = 0; i < 20; i++)
    {
        dp[i][0] = num[i];
    }

    for (int j = 1; j <= k; j ++)
    {
        for (int i = 0; i < 20; i++)
        {
            if (i + (1 << j) >= 20)
                continue;
            // 给 << 运算符增加括号保护
            dp[i][j] = std::max(dp[i][j - 1], dp[i + (1 << (j-1))][j - 1]);
        }
    }

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            stream << dp[i][j] << " ";
        }
        stream << std::endl;
    }
    stream << std::endl;
}

// 另外一种写法
void dp_array_init2()
{
    int k = log2(20);
    for (int i = 0; i < 20; i++)
        dp[i][0] = num[i];

    for(int j=1;j<=k;j++)
        for(int i=0;i+(1<<j)-1<=20;i++)
            dp[i][j] = std::max(dp[i][j-1],dp[i+(1<<j-1)][j-1]);
}

// l r 是数组的下标
int rmq(int l, int r)
{
    // 这里将一个长度任意地区间转变为两个2次幂的区间的叠加
    // 查询区间[l,r]之间的最大值时，令k=log(r-l+1)，那么区间[l,r]之间的
    // 最大值=(dp[l][k]+dp[r-2^k+1][k]);这相当与取了两个较大区间的并集
    int k = log2(r-l + 1);
    return std::max(dp[l][k], dp[r-(1<<k)+1][k]);
}

int main()
{
    for (int i = 0; i < 20; i++)
        num[i] = i + 1;

    dp_array_init();
    //dp_array_init2();

    stream << rmq(19, 19) << std::endl;
    return 0;
}


#if 0

int main()
{
    for (int i = 0; i < 20; i++)
    {
        array_f[i] = -1;
    }
    stream << std::endl;
    stream << F(19) << std::endl;
    for (int i = 0; i < 20; i++)
        stream << array_f[i] << " ";
    stream << std::endl;


    //stream << "max: " << knapsack(100) << std::endl;


    for (int i = 0; i < 101; i++)
    {
        remain_space_array[i] = -1;
    }
    stream << "max: " << knapspack3(100) << std::endl;

    for (int i = 0; i < 101; i++)
    {
        stream << remain_space_array[i] << " ";
    }
    stream << std::endl;
}


#endif