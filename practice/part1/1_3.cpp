#include <iostream>
#include <cassert>

void PrintDigit(int a)
{
    assert(a >= 0 && a <=9);
    std::cout << a;
}

// 要打印76543, 需要先打印出7654, 然后再打印出3
// 打印3使用PrintDigit就可以, 剩下的和之前是一个问题
void printOutPositive(uint32_t n)
{
    if (n >= 10)
        printOutPositive(n / 10);
    PrintDigit(n % 10);
}

// -34235
void printOutNegative(int32_t n)
{
    if (n <= -10)
        printOutNegative(n / 10);

    PrintDigit( -n % 10);
}

void PrintOut(int32_t n)
{
    if (n < 0)
    {
        std::cout << "-";
        printOutNegative(n);
    }
    else
    {
        printOutPositive(n);
    }
}

int main()
{
    PrintOut(76543);
    PrintOut(-76543);
    return 0;
}