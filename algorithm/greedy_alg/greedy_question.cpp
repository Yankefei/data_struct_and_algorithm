#include "stream.h"

using namespace tools;

// 贪心算法
// 加油站问题
int gas_station(int gas[],  int cost[], int len)
{
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        sum += (gas[i] - cost[i]);
    }

    if (sum < 0)
        return -1;
    // 如果sum最终大于等于0，那么一定是有答案的

    // 贪心算法本质，下面这条结论可以得到证明：
    // 如果选择站点 i 作为起点「恰好」无法走到站点 j
    // 那么 i 和 j 中间的任意站点 k 都不可能作为起点。
    int remain = 0;
    int start = 0;
    for (int i = 0; i < len; i++)
    {
        remain += gas[i] - cost[i];
        if (remain < 0)
        {
            start = i + 1;
            remain = 0;
        }
    }
    return start;
}

int main()
{
    int gas[5]  = {1,2,3,4,5};
    int cost[5] = {3,4,5,1,2};

    stream << gas_station(gas, cost, 5) << std::endl;

    return 0;
}