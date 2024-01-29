#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "prefix_sum.h"

//empty array
int test_ary_empty[] = {};

//simple, obvious tests
int test_ary_1[] = {-2, 1};
int test_ary_2[] = {100, 200, 300, -600};
int test_ary_3[] = {-2, 2, -2, 2, -2, 2, -2, 2, -2, 2, -2, 2, -2, 2, -2, 2, -2, 2, -2, 2, -2, 2, -2, 2, -2, 2, -2, 2, -2, 2, -2, 2, -2, 2, -2, 2};
int test_ary_4[] = {2, -2, 2, -2, 2, -2, 2, -2, 2, -2, 2, -2, 2, -2, 2, -2, 2, -2, 2, -2, 2, -2, 2, -2, 2, -2, 2, -2, 2, -2, 2, -2, 2, -2, 2, -2};
int test_ary_5[] = {1'000'000, 1'000'000, 1'000'000, 1'000'000, 1'000'000, 1'000'000, 1'000'000, 1'000'000, 1'000'000, 1'000'000, -10'000'001};
int test_ary_6[] = {-1'000'000, -1'000'000, -1'000'000, -1'000'000, -1'000'000, -1'000'000, -1'000'000, -1'000'000, -1'000'000, -1'000'000, 10'000'001};

//large int tests
int test_ary_large_1[] = {0, 1, 2, 3, 100'000'000, 500'000'000, 1'000'000'000, -1'000'000'000};
int test_ary_large_2[] = {0, -1, -2, -3, -100'000'000, -500'000'000, -1'000'000'000, 1'000'000'000};
int test_ary_large_3[] = {-1'000'000'000, -1'000'000'000, 2'000'000'000, 0, 0, 0, 0, 0};

//various weird edge cases
int test_ary_weird_1[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                          0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                          0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                          0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                          0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                          0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                          0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                          0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                          0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                          0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int test_ary_weird_2[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                          0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                          0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                          0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                          0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                          0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                          0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                          0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                          0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                          0, 0, 0, 0, 0, 0, 0, 0, 0, -1'000'000};

int test_ary_weird_3[] = {1, 0, 1, 0, 1, 0, 1, 0, 1, 0,
                          -5, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                          5, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                          -5, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                          0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                          0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                          0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                          0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                          0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                          0, 0, 0, 0, 0, 0, 0, 0, 1'000'000'000, -1'000'000'000};

int test_ary_weird_4[1'000'000] = {0};
int test_ary_weird_5[1'000'000] = {10};
int test_ary_weird_6[1'000'000] = {-10};


TEST_CASE("prefix sum") {

    SUBCASE("prefix-sum-initials") {
        CHECK_EQ(prefix_sum(test_ary_1, sizeof(test_ary_1)/sizeof(test_ary_1[0])), -1);
    };

    SUBCASE("non-negative") {
        //empty array
        CHECK(non_neg_prefix_sum(test_ary_empty, 0));

        //basic, obvious array tests
        CHECK_FALSE(non_neg_prefix_sum(test_ary_1, 2));
        CHECK(non_neg_prefix_sum(test_ary_2, 4));
        CHECK_FALSE(non_neg_prefix_sum(test_ary_3, 36));
        CHECK(non_neg_prefix_sum(test_ary_4, 36));

        //larger int testing
        CHECK(non_neg_prefix_sum(test_ary_large_1, 8));
        CHECK_FALSE(non_neg_prefix_sum(test_ary_large_3, 13));

        //weird cases
        CHECK(non_neg_prefix_sum(test_ary_weird_1, 100));
        CHECK_FALSE(non_neg_prefix_sum(test_ary_weird_2, 100));
        CHECK(non_neg_prefix_sum(test_ary_weird_3, 100));
        CHECK(non_neg_prefix_sum(test_ary_weird_4, 1'000'000));
        CHECK(non_neg_prefix_sum(test_ary_weird_5, 1'000'000));
        CHECK_FALSE(non_neg_prefix_sum(test_ary_weird_6, 1'000'000));
        CHECK_FALSE(non_neg_prefix_sum(test_ary_5, 11));
    };

    SUBCASE("non-positive") {
        //empty array
        CHECK(non_pos_prefix_sum(test_ary_empty, 0));

        //basic, obvious array tests
        CHECK(non_pos_prefix_sum(test_ary_1, 2));
        CHECK_FALSE(non_pos_prefix_sum(test_ary_2, 4));
        CHECK(non_pos_prefix_sum(test_ary_3, 36));
        CHECK_FALSE(non_pos_prefix_sum(test_ary_4, 36));

        //larger int testing
        CHECK(non_pos_prefix_sum(test_ary_large_2, 8));
        CHECK(non_pos_prefix_sum(test_ary_large_3, 13));

        //weird cases
        CHECK(non_pos_prefix_sum(test_ary_weird_1, 100));
        CHECK(non_pos_prefix_sum(test_ary_weird_2, 100));
        CHECK_FALSE(non_pos_prefix_sum(test_ary_weird_3, 100));
        CHECK(non_pos_prefix_sum(test_ary_weird_4, 1'000'000));
        CHECK_FALSE(non_pos_prefix_sum(test_ary_weird_5, 1'000'000));
        CHECK(non_pos_prefix_sum(test_ary_weird_6, 1'000'000));
        CHECK_FALSE(non_pos_prefix_sum(test_ary_6, 11));
    };

}
