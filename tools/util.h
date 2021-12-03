#ifndef _TOOLS_UTIL_H_
#define _TOOLS_UTIL_H_

#include <iostream>
#include <cassert>
#include <cstring>

extern int g_array[20];

class Util
{
public:
    static void Print(int array[], int length)
    {
        std::cout << "Num: "<< length << ", Print: ";
        for (int i = 0; i < length; i++)
        {
            std::cout << array[i];
            if (i != length -1)
                std::cout << ", ";
        }
        std::cout << std::endl;
    }

    static void CopyData(void* dst, const void* src, const size_t copy_size)
    {
        if (src == g_array)
        {
            assert(copy_size == sizeof(g_array));
            memcpy(dst, src, copy_size);
            return;
        }
        assert(false);
    }
};



#endif /* _TOOLS_UTIL_H_ */
