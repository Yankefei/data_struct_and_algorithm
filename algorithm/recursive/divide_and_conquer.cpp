#include "stream.h"

using namespace tools;

int max_num(int array[], int l, int r)
{
    int u, v; int m = (l+r)/2;
    if (l == r) return array[l];
    u = max_num(array, l, m);
    v = max_num(array, m + 1, r);
    return u > v ? u : v;
}

/*仅做示例*/
void mark(int m, int h)
{
    for(int i = 0; i < h; i ++)
        stream << "  ";
    stream << "*" << std::endl;
}

// 制作直尺
void ruler(int l, int r, int h)
{
    int m = (l + r) / 2;
    if (h > 0)
    {
        ruler(l, m, h -1);
        mark(m, h);
        ruler(m, r, h -1);
    }
}

int main()
{
    int array[20] = {
                222, 16, 884, 104, 740, 789, 498, 523, 525, 950,
        582, 198, 35, 571, 940, 965, 116, 922, 864, 407
    };
    stream << "max: " << max_num(array, 0, 19) << std::endl;


    ruler(0, 20, 4);
}