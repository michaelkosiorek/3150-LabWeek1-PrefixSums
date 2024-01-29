#include <iostream>

#include "prefix_sum.h"

int prefix_sum(int ary[], int length) {

    int sum=0;

    for(int i=0; i<length; i++) {
        sum += ary[i];
    }

    return sum;
}


// returns true if prefix sum of ary is never negative
bool non_neg_prefix_sum(int ary[], int length) {

    int sum=0;

    for(int i=0; i<length; i++) {
        // std::cout << "Entered loop with ary len: " << length << std::endl;
        sum += ary[i];
        if (sum < 0) return false;
    }

    return true;
}

// returns true if prefix sum of ary is never positive
bool non_pos_prefix_sum(int ary[], int length) {

    int sum=0;

    for (int i=0; i < length; i++) {
        // std::cout << "Entered loop with ary len: " << length << std::endl;
        sum += ary[i];
        if (sum > 0) return false;
    }

    return true;
}
