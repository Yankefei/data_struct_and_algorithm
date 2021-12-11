#include <iostream>

#include <memory>

#include "rand.h"
#include "timer_guard.h"


int64_t sum1(int n, int x)
{
    int64_t sum = 1;
    for (int i = 1; i <= n ; i++)
        sum *= x;

    return sum;
}

int64_t sum2(int n, int64_t x)
{
    if (n == 0) return 1;
    if (n == 1) return x;
    
    if (n % 2 == 0)
    {
        return sum2( n / 2, x * x);  // x ^ 2 表示按位异或，不是幂
    }
    else
    {
        return sum2( n / 2, x * x) * x;
    }
}

int64_t func_sum1(int n, int x)
{
    int64_t sum = 0;
    for (int j = 0; j < n; j++)
        sum += (j + 1) * sum1(j, x);

    return sum;
}

int64_t func_sum2(int n, int x)
{
    int64_t sum = 0;
    // 1 + 2*x + 3*x^2 + 4 * x^3 ...
    for (int j = 0; j < n; j++)
        sum += (j + 1) * sum2(j, x);

    return sum;
}

// 2_10  Horner 法则
int64_t func_sum3(int n, int x)
{
    int64_t sum = 0;
    for (int j = n; j > 0; j--)
        sum = x * sum  +  j;

    return sum;
}

int main()
{
// 154320987654321
// Tag: sum1                , diff_nas: 89362, As micro: 89
// 154320987654321
// Tag: sum2                , diff_nas: 3769, As micro: 3
// 154320987654321
// Tag: sum3                , diff_nas: 2689, As micro: 2

    {
        tools::TimerGuard guard("sum1");
        std::cout << func_sum1(14, 10) << std::endl;
    }

    {
        tools::TimerGuard guard("sum2");
        std::cout << func_sum2(14, 10) << std::endl;
    }

    {
        tools::TimerGuard guard("sum3");
        std::cout << func_sum3(14, 10) << std::endl;
    }

    return 0;
}
