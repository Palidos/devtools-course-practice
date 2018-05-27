// Copyright 2018 Pozdeeva Varvara

#include <gtest/gtest.h>

#include "include/binary_search.h"

TEST(Pozdeeva_Varvaral_BinarySearchTest, can_create) {
     // Arrange
     int mas[3];
      // Act
    for (int i = 0; i < 3; i++)
        mas[i] = i;
      // Assert
     ASSERT_NO_THROW(BinarySearch search(mas, 3));
}
TEST(Pozdeeva_Varvaral_BinarySearchTest, can_create_with_negative_size) {
     // Arrange
     int mas[3];
      // Act
    for (int i = 0; i < 3; i++)
        mas[i] = i;
      // Assert
     ASSERT_ANY_THROW(BinarySearch search(mas, -3));
}
TEST(Pozdeeva_Varvaral_BinarySearchTest, can_create_with_null_mas) {
     // Arrange
     int *mas;
      // Act
    mas = nullptr;
      // Assert
     ASSERT_ANY_THROW(BinarySearch search(mas, 3));
}
TEST(Pozdeeva_Varvaral_BinarySearchTest, can_search) {
     // Arrange
     int mas[] = { 1, 2, 3};
     BinarySearch search(mas, 3);
     // Act
     int resalt = search.Search(3);
      // Assert
     EXPECT_EQ(resalt , 2);
}
TEST(Pozdeeva_Varvaral_BinarySearchTest, can_search_if_num_not_in_mas) {
     // Arrange
    int mas[] = { 1, 2, 3};
    BinarySearch search(mas, 3);
     // Act
    int resalt = search.Search(4);
     // Assert
    EXPECT_EQ(resalt, -1);
}
TEST(Pozdeeva_Varvaral_BinarySearchTest, can_Search_if_mas_not_sort) {
    // Arrange
    int mas[] = { 5, 2, 3, 1, 9};
    BinarySearch search(mas, 5);
     // Act
     int resalt = search.Search(3);
      // Assert
    EXPECT_EQ(resalt, 2);
}
