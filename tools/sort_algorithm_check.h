#ifndef _TOOLS_SORT_ALGORITHM_CHECK_H_
#define _TOOLS_SORT_ALGORITHM_CHECK_H_

#include <random>
#include <chrono>
#include <functional>
#include <algorithm>
#include <cstring>

#include "util.h"

namespace tools
{

template<typename T>
using sort_alg_func = void(*)(T*, int);

template<typename T>
class SortAlgorithmChecker
{
public:
    SortAlgorithmChecker(int capacity, int times, bool positive_seq):
        seed_(std::chrono::high_resolution_clock::now().time_since_epoch().count()),
        capacity_(capacity),
        times_(times)
    {
        for (int i = 0; i < times_; i++)
        {
            T *orig_ptr = new T[capacity_];
            T *sort_ptr = new T[capacity_];
            for (int j = 0; j < capacity_; j++)
            {
                orig_ptr[j] = dist_(rand_generator_);
            }
            memcpy(sort_ptr, orig_ptr, capacity_ * sizeof(T));
            orig_array_v.emplace_back(orig_ptr);
            if (positive_seq)
                std::sort(sort_ptr, sort_ptr + capacity_, std::less<T>());
            else
                std::sort(sort_ptr, sort_ptr + capacity_, std::greater<T>());
            sort_array_v.emplace_back(sort_ptr);
        }
    }

    ~SortAlgorithmChecker()
    {
        for (auto& ptr : orig_array_v)
            delete[] ptr;
        for (auto& ptr : sort_array_v)
            delete[] ptr;
    }

    bool Check(sort_alg_func<T> func)
    {
        bool result = true;
        for (int i = 0; i < times_; i++)
        {
            T* array = new T[capacity_];
            memcpy(array, orig_array_v[i], capacity_ * sizeof(T));

            func(array, capacity_);

            T* sort_ptr = sort_array_v[i];
            for (int n = 0; n < capacity_; n++)
            {
                if (sort_ptr[n] != array[n])
                {
                    result = false;
                    Util::Print(orig_array_v[i], capacity_, "origin: ");
                    Util::Print(sort_ptr, capacity_, "sort: ");
                    Util::Print(array, capacity_, "fail result");
                    break;
                }
            }
            delete[] array;
            if (!result) break;
        }
        return result;
    }

private:
    uint32_t seed_;
    std::mt19937 rand_generator_{seed_};

    std::vector<T*> orig_array_v;
    std::vector<T*> sort_array_v;
    int capacity_;
    int times_;

    std::uniform_int_distribution<int> dist_{0, 1024};
};

}

#endif
