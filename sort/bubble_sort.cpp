#include "sort_header.h"

namespace sort
{

void bubble_sort_positive(int array[], int length)
{
    bool change = true;
    for (int i = length - 1; i > 0 && change; --i)
    {
        change = false;
        for (int j = 0; j < i; ++j)
        {
            if (array[j] > array[j + 1])
            {
                std::swap(*(array + j), *(array + j + 1));
                change = true;
            }
        }
    }
}

void bubble_sort_negative(int array[], int length)
{
    bool change = true;
    for (int i = 0; i < length && change; ++i)
    {
        change = false;
        for (int j = length - 1; j > i; --j)
        {
            if (array[j] > array[j - 1])
            {
                std::swap(*(array + j), *(array + j - 1));
                change = true;
            }
        }
    }
}

}