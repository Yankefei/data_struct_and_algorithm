
#include <iostream>
#include "sort_header.h"

extern void practice_1_1(int array[], int length, int array_out[], int out_length);

#define K 10

int main()
{
    int array2[20] = {0};
    tools::Util::CopyData(array2, tools::g_array, sizeof(array2));
    tools::Util::Print(array2, 20);
    int array3[K] = {0};
    practice_1_1(array2, 20, array3, K);
    tools::Util::Print(array3, K);

    return 0;
}