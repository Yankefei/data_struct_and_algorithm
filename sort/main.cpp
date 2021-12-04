#include "sort_header.h"
#include "sort_algorithm_check.h"

using namespace sort;

int main()
{
    tools::SortAlgorithmChecker<int> positive_checker(100, 100, true);
    if (!positive_checker.Check(bubble_sort_positive))
    {
        std::cout << "check failed" <<std::endl;
    }


    tools::SortAlgorithmChecker<int> negative_checker(100, 100, false);
    if (!negative_checker.Check(bubble_sort_negative))
    {
        std::cout << "check failed" <<std::endl;
    }

    return 0;
}
