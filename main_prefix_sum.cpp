#include <iostream>

#include "prefix_sum.h"

int main() {

    int ary[] = { 1, -1, 1, 1, -1, -1 };

    int sum = prefix_sum(ary, sizeof(ary)/sizeof(ary[0]));


    std::cout << sum << std::endl;

    return 0;
}