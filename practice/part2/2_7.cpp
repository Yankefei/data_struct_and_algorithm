#include <iostream>

#include <memory>

#include "rand.h"
#include "timer_guard.h"
#include "timer_shared.h"
#include "util.h"

void func1(int n, tools::TimerShared* timer_ptr)
{
    assert(n > 0);
    tools::Rand<> rander;
    int* ptr = new int[n];
    memset(ptr, 0, sizeof(int) * n);

    {
        //tools::TimerGuard t1(__FUNCTION__ + std::string("_") + std::to_string(n));
        tools::TimerShared temp(*timer_ptr);
        rander.ChangeRange(1, n);
        bool cont = true;
        for (int i = 0; i < n;)
        {
            cont = true;
            int ele = rander();
            for (int j = 0; j < i; j++)
            {
                if (ptr[j] == ele)
                {
                    cont = false;
                    break;
                }
            }

            if (cont)
            {
                ptr[i] = ele;
                i ++;
            }
        }
    }
    // tools::Util::Print(ptr, n);
    // std::sort(ptr, ptr + n, std::less<int>());
    // tools::Util::Print(ptr, n);
    delete[] ptr;
}

void func2(int n, tools::TimerShared* timer_ptr)
{
    assert(n > 0);
    tools::Rand<> rander;
    int* ptr = new int[n];
    int* used_ptr = new int[n];
    memset(ptr, 0, sizeof(int) * n);
    memset(used_ptr, 0, sizeof(int)* n);

    {
        //tools::TimerGuard t1(__FUNCTION__ + std::string("_") + std::to_string(n));
        tools::TimerShared temp(*timer_ptr);
        rander.ChangeRange(1, n);
        for (int i = 0; i < n;)
        {
            int ele = rander();
            if (used_ptr[ele-1])
                continue;

            ptr[i] = ele;
            used_ptr[ele -1] = 1;
            i ++;
        }
    }
    delete[] ptr;
    delete[] used_ptr;
}

void func3(int n, tools::TimerShared* timer_ptr)
{
    assert(n > 0);
    tools::Rand<> rander;
    int* ptr = new int[n];

    {
        //tools::TimerGuard t1(__FUNCTION__ + std::string("_") + std::to_string(n));
        tools::TimerShared temp(*timer_ptr);

        for (int i = 0; i < n; i ++)
            ptr[i] = i + 1;

        for (int i = 1; i < n; i ++)
        {
            rander.ChangeRange(0, i);
            std::swap(ptr[i], ptr[rander()]);
        }
    }
    delete[] ptr;
}

int main()
{
/*
O(N^2)
Tag: func1_250           , times: 10, diff_nas: 857252, As micro: 857
Tag: func1_500           , times: 10, diff_nas: 4757841, As micro: 4757, As milli: 4
Tag: func1_1000          , times: 10, diff_nas: 16678762, As micro: 16678, As milli: 16
Tag: func1_2000          , times: 10, diff_nas: 60059477, As micro: 60059, As milli: 60
O(N)
Tag: func2_2500          , times: 10, diff_nas: 1692065, As micro: 1692, As milli: 1
Tag: func2_5000          , times: 10, diff_nas: 3927032, As micro: 3927, As milli: 3
Tag: func2_10000         , times: 10, diff_nas: 8348997, As micro: 8348, As milli: 8
Tag: func2_20000         , times: 10, diff_nas: 16188021, As micro: 16188, As milli: 16
Tag: func2_40000         , times: 10, diff_nas: 31464289, As micro: 31464, As milli: 31
O(N), 基础时间很低
Tag: func3_10000         , times: 10, diff_nas: 1082517, As micro: 1082, As milli: 1
Tag: func3_20000         , times: 10, diff_nas: 1965999, As micro: 1965, As milli: 1
Tag: func3_40000         , times: 10, diff_nas: 4791639, As micro: 4791, As milli: 4
Tag: func3_80000         , times: 10, diff_nas: 10258324, As micro: 10258, As milli: 10
Tag: func3_160000        , times: 10, diff_nas: 16997041, As micro: 16997, As milli: 16
Tag: func3_320000        , times: 10, diff_nas: 35079700, As micro: 35079, As milli: 35
Tag: func3_640000        , times: 10, diff_nas: 91780155, As micro: 91780, As milli: 91
*/
    for (int i = 250, j = 4; j > 0; j--, i *= 2)
    {
        tools::TimerShared timer("func1_" + std::to_string(i));
        for (int n = 0; n < 10; n ++)
        {
            func1(i, &timer);
        }
    }

    for (int i = 2500, j = 5; j > 0; j--, i *= 2)
    {
        tools::TimerShared timer("func2_" + std::to_string(i));
        for (int n = 0; n < 10; n ++)
        {
            func2(i, &timer);
        }
    }

    for (int i = 10000, j = 7; j > 0; j--, i *= 2)
    {
        tools::TimerShared timer("func3_" + std::to_string(i));
        for (int n = 0; n < 10; n ++)
        {
            func3(i, &timer);
        }
    }

    return 0;
}