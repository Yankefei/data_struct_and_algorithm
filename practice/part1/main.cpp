
#include <iostream>
#include "sort_header.h"

extern void practice_1_1(int array[], int length, int array_out[], int out_length);

#define K 10

int main()
{
    int array2[20] = {0};
    Util::CopyData(array2, g_array, sizeof(array2));
    Util::Print(array2, 20);
    int array3[K] = {0};
    practice_1_1(array2, 20, array3, K);
    Util::Print(array3, K);

    return 0;
}