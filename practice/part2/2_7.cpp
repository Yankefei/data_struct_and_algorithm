#include <iostream>
#include "rand.h"
#include "timer_guard.h"
#include "util.h"

void func1(int n)
{
    assert(n > 0);
    tools::Rand<> rander;
    int* ptr = new int[n];
    memset(ptr, 0, sizeof(int) * n);

    {
        tools::TimerGuard t1(__FUNCTION__ + std::string("_") + std::to_string(n));
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


int main()
{
    func1(250);

    return 0;
}