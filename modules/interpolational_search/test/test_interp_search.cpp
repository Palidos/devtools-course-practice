// Copyright 2017 Konakov Alexandr

#include <gtest/gtest.h>

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include "include/interp_search.h"

TEST(InterpolationalSearchTest, Throws_On_Empty_Input_Array) {
  // Arrange
  std::vector<int> arr;
  // Act & Assert
  EXPECT_ANY_THROW(xab::interpSearch(arr, 6));
}

TEST(InterpolationalSearchTest, Can_Find_In_Array_With_Just_One_Element) {
  // Arrange
  std::vector<int> arr = {5};
  // Act
  int search_result = xab::interpSearch(arr, 5);
  // Assert
  EXPECT_EQ(search_result, 0);
}

TEST(InterpolationalSearchTest, Can_Find_Existing_Element_In_Even_Array) {
  // Arrange
  std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  // Act
  int search_result = xab::interpSearch(arr, arr[2]);
  // Assert
  EXPECT_EQ(search_result, 2);
}

TEST(InterpolationalSearchTest, Cant_Find_Not_Existing_Element_In_Even_Array) {
  // Arrange
  std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  // Act
  int search_result = xab::interpSearch(arr, 26);
  // Assert
  EXPECT_EQ(search_result, -1);
}

TEST(InterpolationalSearchTest,
     Can_Find_Existing_Element_In_Not_Uniform_Array) {
  // Arrange
  std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 80, 90, 100};
  // Act
  int search_result = xab::interpSearch(arr, arr[8]);
  // Assert
  EXPECT_EQ(search_result, 8);
}
TEST(InterpolationalSearchTest,
     Can_Find_Existing_Element_In_Not_Uniform_Array_From_Left) {
  // Arrange
  std::vector<int> arr = {1, 2, 3, 4, 5, 60, 70, 90, 98, 100};
  // Act
  int search_result = xab::interpSearch(arr, arr[7]);
  // Assert
  EXPECT_EQ(search_result, 7);
}

TEST(InterpolationalSearchTest,
     Cant_Find_Not_Existing_Element_In_Not_Uniform_Array) {
  // Arrange
  std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 9, 10, 100};
  // Act
  int search_result = xab::interpSearch(arr, 26);
  // Assert
  EXPECT_EQ(search_result, -1);
}

TEST(InterpolationalSearchTest,
     Can_Find_Existing_Element_In_Large_Random_Array) {
  // Arrange
  srand(time(0));
  auto myrand = rand;
  const int arr_size = 10000;
  const int elem_indx = 62;
  auto stupid_lambda = [&elem_indx]()->int{return elem_indx;};
  std::vector<int> arr(arr_size);
  for (auto& elem : arr) elem = myrand();
  std::sort(arr.begin(), arr.end());
  // Act
  int search_result = xab::interpSearch(arr, arr[elem_indx]);
  // Assert
  EXPECT_EQ(arr[search_result], arr[stupid_lambda()]);
}
