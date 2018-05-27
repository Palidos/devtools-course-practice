// Copyright 2018 Batanina Liubov

#include <gtest/gtest.h>
#include <vector>
#include <random>
#include <algorithm>
#include <limits>
#include "include/radix_sort.hpp"

using std::uniform_int_distribution;

class RadixSortTest : public testing::Test {
 protected:
    virtual void SetUp() {
        data.resize(10000);
        std::mt19937 generator{std::random_device()()};
        uniform_int_distribution<int> distr(std::numeric_limits<int>::min(),
                                            std::numeric_limits<int>::max());
        generate(data.begin(), data.end(), [&distr, &generator](){
            return distr(generator);
        });
    }
    std::vector<int> data;
};


TEST_F(RadixSortTest, Radix_Sort) {
    // Arrange & Act
    radixSort(data.begin(), data.end());

    // Assert
    EXPECT_EQ(std::is_sorted(data.begin(), data.end()), true);
}

TEST_F(RadixSortTest, Radix_Sort_Empty_Vector) {
    // Arrange & Act & Assert
    ASSERT_NO_THROW(radixSort(data.begin(), data.begin()));
}

TEST_F(RadixSortTest, Throw_When_Pass_Reverse_Range) {
    // Arrange & Act & Assert
    EXPECT_THROW(radixSort(data.end(), data.begin()), std::logic_error);
}

TEST_F(RadixSortTest, Create_Radix_Sorter) {
  // AAA
  EXPECT_NO_THROW(RadixSorter rs);
}

TEST_F(RadixSortTest, Create_Radix_Sorter_From_Vector) {
  // Arrange & Act
  std::vector<int> v = {1, 4, 5};

  // Assert
  EXPECT_NO_THROW(RadixSorter rs(v));
}

TEST_F(RadixSortTest, Check_Get_Data) {
  // Arrange & Act
  std::vector<int> v = {1, 4, 5};

  // Act
  RadixSorter rs(v);

  // Assert
  EXPECT_EQ(v, rs.get_data());
}

TEST_F(RadixSortTest, Create_Radix_Sorter_From_Vector_Iterators) {
  // Arrange
  std::vector<int> v = {1, 5, 6, 1, 6, -2};

  // Act
  RadixSorter rs(v.begin(), v.end());

  // Assert
  EXPECT_EQ(rs.get_data(), v);
}

TEST_F(RadixSortTest, Create_Radix_Sorter_Move) {
  // Arrange
  std::vector<int> v = {1, 5, 6, 1, 6, -2};

  // Act
  RadixSorter rs(v.begin(), v.end());
  RadixSorter mrs(std::move(rs));

  // Assert
  EXPECT_EQ(mrs.get_data(), v);
}

TEST_F(RadixSortTest, Create_Radix_Sorter_Copy) {
  // Arrange
  std::vector<int> v = {1, 5, 6, 1, 6, -2};

  // Act
  RadixSorter rs(v.begin(), v.end());
  RadixSorter crs(rs);

  // Assert
  EXPECT_EQ(crs.get_data(), v);
}

TEST_F(RadixSortTest, Assign_Radix_Sorter) {
  // Arrange
  std::vector<int> v = {1, 5, 0};
  RadixSorter rs(v);
  RadixSorter rs2;

  // Act
  rs2 = rs;

  // Assert
  EXPECT_EQ(rs2.get_data(), v);
}

TEST_F(RadixSortTest, Move_Assign_Radix_Sorter) {
  // Arrange
  std::vector<int> v = {1, 5, 0};
  RadixSorter rs(v);
  RadixSorter rs2;

  // Act
  rs2 = std::move(rs);

  // Assert
  EXPECT_EQ(rs2.get_data(), v);
}

TEST_F(RadixSortTest, Check_Sort_Radix_Sorter) {
  // Arrange
  std::vector<int> v = {-3, 5, 1, 5, 10};
  RadixSorter rs(v);

  // Act
  auto sort_v = rs.sort();

  // Assert
  EXPECT_TRUE(std::is_sorted(sort_v.begin(), sort_v.end()));
}
