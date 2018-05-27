// Copyright 2018 Krasikova Ekaterina

#include <gtest/gtest.h>

#include "include/Node.h"

TEST(NodeForLeftistHeapTest,
    There_is_no_throw_when_create_null_node) {
    // Act and Assert
    EXPECT_NO_THROW(node n);
}
TEST(NodeForLeftistHeapTest, Can_create_null_node) {
    // Act
    node n;
    // Assert
    EXPECT_EQ(0, n.key);
}
TEST(NodeForLeftistHeapTest,
    There_is_no_throw_when_create_not_null_node) {
    // Act and Assert
    EXPECT_NO_THROW(node n(10));
}
TEST(NodeForLeftistHeapTest, Can_create_not_null_node) {
    // Act
    node n(10);
    // Assert
    EXPECT_EQ(10, n.key);
}
