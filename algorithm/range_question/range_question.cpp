#include "stream.h"

#include <map>

using namespace tools;

struct Range
{
    Range() = default;
    Range(int a, int b) : start(a), end(b) {}
    int start{0};
    int end{0};
};

Range array_r[5];

//理解区间问题的本质是先理解map排序后的增量代表的含义

// 求多个区间最大重合数
int get_max_range_num(Range array[], int array_num)
{
    //给区间排序
    std::map<int, int> rang_map;
    //只需要统计每一个区间左右两个端点的信息即可, rang_map记录的是端点的增量
    for (int i = 0; i < array_num; i++)
    {
        rang_map[array[i].start] ++;
        rang_map[array[i].end] --;
    }


    int res = 0;
    int n = 0;
    for (auto & e : rang_map)
    {
        stream << e.first << "**"<< e.second << " ";
        n += e.second;
        res = n > res ? n : res;
    }
    stream << std::endl;
    return res;
}

// 求多个区间并集的最大长度
int get_max_range_len(Range array[], int array_num)
{
    //给区间排序
    std::map<int, int> rang_map;
    //只需要统计每一个区间左右两个端点的信息即可, rang_map记录的是端点的增量
    for (int i = 0; i < array_num; i++)
    {
        rang_map[array[i].start] ++;
        rang_map[array[i].end] --;
    }

    int max_len = 0;
    int len = 0;
    int n = 0;
    int begin = rang_map.begin()->first;
    int end = 0;
    bool clear = false;
    for (auto & e : rang_map)
    {
        stream << e.first << "**"<< e.second << " ";
        n += e.second;  // n 可以为正也可以为负数
        // 开始统计一段新的区间
        if (n > 0 && clear)
        {
            begin = e.first;
            clear = false;
        }

        // 区间结束
        if (n == 0 && !clear)
        {
            end = e.first;
            len = end - begin;
            stream << "len: "<< len << " "<< std::endl;
            if (len > max_len)
                max_len = len;
            
            begin = 0;
            clear = true;
        }
    }

    stream << std::endl;
    return max_len;
}

int main()
{
    array_r[0] = Range(-2, 1);
    array_r[3] = Range(-4, -1);
    array_r[1] = Range(-3, 0);
    array_r[2] = Range(-2, -1);
    array_r[4] = Range(2, 3);
    array_r[5] = Range(5, 11);

    stream << "range_num: "<< get_max_range_num(array_r, 6) << std::endl;

    stream << "range_num: "<< get_max_range_len(array_r, 6) << std::endl;

    return 0;
}