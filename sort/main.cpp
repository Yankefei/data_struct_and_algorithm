#include "sort_header.h"

using namespace sort;

int main()
{
    int array1[20] = {0};
    Util::CopyData(array1, g_array, sizeof(array1));
    Util::Print(array1, 20);
    bubble_sort_positive(array1, 20);
    Util::Print(array1, 20);


    int array2[20] = {0};
    Util::CopyData(array2, g_array, sizeof(array2));
    bubble_sort_negative(array2, 20);
    Util::Print(array2, 20);
    return 0;
}
