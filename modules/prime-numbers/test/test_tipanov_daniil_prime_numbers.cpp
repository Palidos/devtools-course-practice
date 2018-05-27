// Copyright 2018 Tipanov Daniil

#include <gtest/gtest.h>
#include <vector>
#include "include/PrimeNumbers.h"

TEST(PrimeNumbers, can_create_without_error_empty) {
    // AAA
    ASSERT_NO_THROW(PrimeNumbers tmp);
}

TEST(PrimeNumbers, can_create_without_error_not_empty) {
    // AAA
    ASSERT_NO_THROW(PrimeNumbers tmp(2, 5));
}

TEST(PrimeNumbers, error_if_min_is_less_than_zero) {
    // AAA
    ASSERT_ANY_THROW(PrimeNumbers tmp(-6, 6));
}

TEST(PrimeNumbers, error_if_max_is_less_than_min) {
    // AAA
    ASSERT_ANY_THROW(PrimeNumbers tmp(6, 5));
}

TEST(PrimeNumbers, find_prime_numbers_without_errors) {
    // Arrange
    PrimeNumbers tmp(6, 8);

    // Act and assert
    ASSERT_NO_THROW(tmp.FindPrimeNums());
}

TEST(PrimeNumbers, check_result_array) {
    // Arrange
    int min = 3, max = 5;
    std::vector<int> resArr = { 3, 5 };
    PrimeNumbers tmp(min, max);

    // Act and assert
    EXPECT_EQ(resArr, tmp.FindPrimeNums());
}
