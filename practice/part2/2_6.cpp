#include <iostream>

#include "timer_guard.h"


uint32_t Func1(uint32_t n)
{
    uint32_t sum = 0;
    for (uint32_t i = 0; i < n; i++)
        sum ++;

    return sum;
}

uint32_t Func2(uint32_t n)
{
    uint32_t sum = 0;
    for (uint32_t i = 0; i < n; i++)
        for (uint32_t j = 0; j < n; j++)
            sum ++;

    return sum;
}

uint32_t Func3(uint32_t n)
{
    uint32_t sum = 0;
    for (uint32_t i = 0; i < n; i++)
        for (uint32_t j = 0; j < n * n; j++)
            sum ++;

    return sum;
}

uint32_t Func4(uint32_t n)
{
    uint32_t sum = 0;
    for (uint32_t i = 0; i < n; i++)
        for (uint32_t j = 0; j < i; j++)
            sum ++;

    return sum;
}

uint32_t Func5(uint32_t n)
{
    uint32_t sum = 0;
    for (uint32_t i = 0; i < n; i++)
        for (uint32_t j = 0; j < i * i; j++)
            for (uint32_t k = 0; k < j; k++)
                sum ++;

    return sum;
}

uint32_t Func6(uint32_t n)
{
    uint32_t sum = 0;
    for (uint32_t i = 0; i < n; i++)
        for (uint32_t j = 0; j < i * i; j++)
            if (j % i == 0)
                for (uint32_t k = 0; k < j; k++)
                    sum ++;

    return sum;
}

int main()
{
// O (N^4)
// Tag: func6_50            , diff_nas: 2623068, As micro: 2623, As milli: 2
// Tag: func6_100           , diff_nas: 32230792, As micro: 32230, As milli: 32
// Tag: func6_200           , diff_nas: 442907766, As micro: 442907, As milli: 442
/*
    {
        tools::TimerGuard t3("func6_50");
        Func6(50);
    }
    {
        tools::TimerGuard t3("func6_100");
        Func6(100);
    }
    {
        tools::TimerGuard t3("func6_200");
        Func6(200);
    }
*/

// O(N^5)
// Tag: func5_10            , diff_nas: 21428, As micro: 21
// Tag: func5_20            , diff_nas: 676265, As micro: 676
// Tag: func5_40            , diff_nas: 26922063, As micro: 26922, As milli: 26
/*
    {
        tools::TimerGuard t3("func5_10");
        Func5(10);
    }
    {
        tools::TimerGuard t3("func5_20");
        Func5(20);
    }
    {
        tools::TimerGuard t3("func5_40");
        Func5(40);
    }
*/

// O(N^2)
// Tag: func4_100           , diff_nas: 12518, As micro: 12
// Tag: func4_1000          , diff_nas: 1252568, As micro: 1252, As milli: 1
// Tag: func4_10000         , diff_nas: 147770311, As micro: 147770, As milli: 147
/*
    {
        tools::TimerGuard t3("func4_100");
        Func4(100);
    }
    {
        tools::TimerGuard t3("func4_1000");
        Func4(1000);
    }
    {
        tools::TimerGuard t3("func4_10000");
        Func4(10000);
    }
*/

// O(N^3)
// Tag: func3_10            , diff_nas: 5650, As micro: 5
// Tag: func3_100           , diff_nas: 3907553, As micro: 3907, As milli: 3
// Tag: func3_1000          , diff_nas: 4281444241, As micro: 4281444, As milli: 4281, As sec: 4
/*
    {
        tools::TimerGuard t3("func3_10");
        Func3(10);
    }

    {
        tools::TimerGuard t3("func3_100");
        Func3(100);
    }

    {
        tools::TimerGuard t3("func3_1000");
        Func3(1000);
    }
*/
// O(N^2)
// Tag: func2_100           , diff_nas: 26085, As micro: 26
// Tag: func2_1000          , diff_nas: 3334660, As micro: 3334, As milli: 3
// Tag: func2_10000         , diff_nas: 226723123, As micro: 226723, As milli: 226
/*
    {
        tools::TimerGuard t1("func2_100");
        Func2(100);
    }

    {
        tools::TimerGuard t1("func2_1000");
        Func2(1000);
    }

    {
        tools::TimerGuard t1("func2_10000");
        Func2(10000);
    }
*/
// O(N)
// Tag: func1_10000         , diff_nas: 23306, As micro: 23
// Tag: func1_100000        , diff_nas: 218443, As micro: 218
// Tag: func1_1000000       , diff_nas: 2835675, As micro: 2835, As milli: 2
/*
    {
        tools::TimerGuard t1("func1_10000");
        Func1(10000);
    }

    {
        tools::TimerGuard t1("func1_100000");
        Func1(100000);
    }

    {
        tools::TimerGuard t1("func1_1000000");
        Func1(1000000);
    }
*/
    return 0;
}