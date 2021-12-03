#include <cassert>
#include "sort_header.h"

void replace_one_element(int array[], int length, int val)
{
    int i = 0;
    for (; i < length; i++)
    {
        if (array[i] >= val)
            continue;

        if (i == length - 1)
        {
            break;
        }

        //memcpy 本身就无法处理地址重叠的问题
        //int move_count = length - i;
        //memcpy(array + i, array + i + 1, move_count -1);
        int j = length - 1;
        while(j > i)
        {
            array[j] = array[j - 1]; 
            j --;
        }
        break;
    }
    array[i] = val;
}

void practice_1_1(int array[], int length, int array_out[], int out_length)
{
    assert(length >= out_length);
    memcpy(array_out, array, sizeof(int) * out_length);
    sort::bubble_sort_negative(array_out, out_length);
    if (length == out_length) return;

    int *array_left = array + out_length;
    int *array_final = array + length;
    for (; array_left != array_final; array_left ++)
    {
        if (*array_left  <= array_out[out_length -1]) continue;

        replace_one_element(array_out, out_length, *array_left);
    }
}