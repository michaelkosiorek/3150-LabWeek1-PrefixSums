#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "prefix_sum.h"

int test_ary_0[] = {};
int test_ary_1[] = {-2, 1};

TEST_CASE("prefix sum") {

    CHECK_EQ(prefix_sum(test_ary_1, sizeof(test_ary_1)/sizeof(test_ary_1[0])), -1);

    SUBCASE("non-negative") {
        CHECK_FALSE(non_neg_prefix_sum(test_ary_0, 0));
    };

}