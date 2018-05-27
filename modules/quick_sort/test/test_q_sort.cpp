// Copyright 2018 Romanov Alexander

#include <gtest/gtest.h>

#include <algorithm>
#include <cstdlib>
#include <vector>
#include "include/q_sort.h"

TEST(QuickSortTest, Cant_Sort_Empty_Array) {
  // Arrange
  std::vector<int> arr;

  // Act & Assert
  EXPECT_ANY_THROW(sort::quickSort(&arr, 0, 3));
}

TEST(QuickSortTest, Cant_Sort_Negative_index) {
    // Arrange
    std::vector<int> arr = { 2, 1 };

    // Assert
    EXPECT_ANY_THROW(sort::quickSort(&arr, -1, 1));
}

TEST(QuickSortTest, Cant_out_right_bound) {
    // Arrange
    std::vector<int> arr = { 1, 3, 4, 5, 6 };

    // Act & Assert
    EXPECT_ANY_THROW(sort::quickSort(&arr, 0, 8));
}

TEST(QuickSortTest, Sort_one_elem_no_exept) {
    // Arrange
    std::vector<int> arr = { 2, 1 };

    // Act & Assert
    EXPECT_NO_THROW(sort::quickSort(&arr, 1, 1));
}

TEST(QuickSortTest, Can_Sort_one_elem) {
    // Arrange
    std::vector<int> arr = { 2, 1 };

    // Act
    sort::quickSort(&arr, 1, 1);

    // Assert
    EXPECT_EQ(arr[1], 1);
}

TEST(QuickSortTest, Can_Sort_large_arr) {
    // Arrange
    std::vector<int> arr1 = {2, 1, 4, 8, 6, 9, 3, 0, 7, 5};
    std::vector<int> arr2 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    // Act
    sort::quickSort(&arr1, 0, 9);

    // Assert
    EXPECT_TRUE(arr1 == arr2);
}
