// Copyright 2018 Roman Kudalin

#include <gtest/gtest.h>

#include "include/queue.h"

TEST(QueueTest, Can_Create_Default_Queue) {
    // AAA
    ASSERT_NO_THROW(Queue<int> q);
}

TEST(QueueTest, Can_Create_Queue_With_Specified_Size) {
    // AAA
    ASSERT_NO_THROW(Queue<int> q(5));
}

TEST(QueueTest, Can_Create_Queue_Via_Copy_Ctor) {
    // Arrange
    Queue<int> src;

    // Act & Assert
    ASSERT_NO_THROW(Queue<int> dst(src));
}

TEST(QueueTest, Can_Determine_Empty_Queue) {
    // Arrange
    Queue<int> q;

    // Act & Assert
    EXPECT_TRUE(q.empty());
}

TEST(QueueTest, Can_Push_Element_Into_Queue) {
    // Arrange
    Queue<int> q;

    // Act & Assert
    ASSERT_NO_THROW(q.push(1));
}

TEST(QueueTest, Can_Get_Queue_Size) {
    // Arrange
    Queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    // Act & Assert
    std::size_t expected_size = 3;
    EXPECT_EQ(q.size(), expected_size);
}

TEST(QueueTest, Can_Get_Front_Element_From_Queue) {
    // Arrange
    Queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    // Act & Assert
    int expected_front = 1;
    EXPECT_EQ(q.front(), expected_front);
}

TEST(QueueTest, Throws_While_Getting_Front_Elem_From_Empty_Queue) {
    // Arrange
    Queue<int> q;

    // Act & Assert
    ASSERT_THROW(q.front(), std::runtime_error);
}

TEST(QueueTest, Can_Get_Front_Elem_From_Constant_Queue) {
    // Arrange
    Queue<int> q1;
    q1.push(1); q1.push(2); q1.push(3);
    const Queue<int> q2(q1);

    // Act & Assert
    EXPECT_EQ(q2.front(), 1);
}

TEST(QueueTest, Can_Get_Last_Element_From_Queue) {
    // Arrange
    Queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    // Act & Assert
    int expected_back = 3;
    EXPECT_EQ(q.back(), expected_back);
}

TEST(QueueTest, Throws_While_Getting_Last_Elem_From_Empty_Queue) {
    // Arrange
    Queue<int> q;

    // Act & Assert
    ASSERT_THROW(q.back(), std::runtime_error);
}

TEST(QueueTest, Can_Get_Last_Elem_From_Constant_Queue) {
    // Arrange
    Queue<int> q1;
    q1.push(1); q1.push(2); q1.push(3);
    const Queue<int> q2(q1);

    // Act & Assert
    EXPECT_EQ(q2.back(), 3);
}

TEST(QueueTest, First_And_Last_Elem_Are_Equal_In_Singleton_Queue) {
    // Arrange
    Queue<int> q;
    q.push(1);

    // Act & Assert
    EXPECT_TRUE(q.front() == 1 && q.back() == 1);
}

TEST(QueueTest, Can_Remove_Element_From_Queue) {
    // Arrange
    Queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    // Act & Assert
    ASSERT_NO_THROW(q.pop());
    EXPECT_EQ(q.size(), 2);
}

TEST(QueueTest, Removed_Element_Was_Inserted_First) {
    // Arrange
    Queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    // Act
    q.pop();

    // Assert
    int first_inserted_elem = 1;
    EXPECT_NE(q.front(), first_inserted_elem);
}

TEST(QueueTest, Throws_While_Removing_Element_From_Empty_Queue) {
    // Arrange
    Queue<int> q;

    // Act & Assert
    ASSERT_THROW(q.pop(), std::runtime_error);
}

TEST(QueueTest, Can_Swap_Two_Queues) {
    // Arrange
    Queue<int> q1, q2;
    q1.push(1); q1.push(2);
    q2.push(3); q2.push(4);

    // Act
    q1.swap(q2);

    // ASSERT
    EXPECT_TRUE(q1.front() == 3 && q1.back() == 4
        && q2.front() == 1 && q2.back() == 2);
}

TEST(QueueTest, Can_Assign_Queue_To_Itself) {
    // Arrange
    Queue<int> q;
    q.push(1);

    // Act & Assert
    ASSERT_NO_THROW(q = q);
}

TEST(QueueTest, Can_Compare_Two_Queues) {
    // Arrange
    Queue<int> q1, q2;
    q1.push(1); q1.push(2); q1.push(3);
    q2.push(1); q2.push(2); q2.push(3);

    // Act & Assert
    EXPECT_TRUE(q1 == q2);
}

TEST(QueueTest, Can_Determine_Not_Equal_Queues) {
    // Arrange
    Queue<int> q1, q2;
    q1.push(1); q1.push(2); q1.push(3);
    q2.push(3); q2.push(4); q2.push(5);

    // Act & Assert
    EXPECT_FALSE(q1 == q2);
}

TEST(QueueTest, Empty_Queue_Is_Not_Equal_To_Any_Other) {
    // Arrange
    Queue<int> q1, q2;
    q2.push(1); q2.push(2);

    // Act & Assert
    EXPECT_FALSE(q1 == q2);
}

TEST(QueueTest, Queues_With_Different_Sizes_Are_Not_Equal) {
    // Arrange
    Queue<int> q1, q2;
    q1.push(1);
    q2.push(1); q2.push(2);

    // Act & Assert
    EXPECT_FALSE(q1 == q2);
}

TEST(QueueTest, Queue_Copied_Via_Copy_Ctor_Is_Equal_To_Original) {
    // Arrange
    Queue<int> q1;
    q1.push(1); q1.push(2); q1.push(3);

    // Act
    Queue<int> q2(q1);

    // Assert
    EXPECT_TRUE(q1 == q2);
}

TEST(QueueTest, Queue_Copied_Via_Copy_Ctor_Has_Its_Own_Memory) {
    // Arrange
    Queue<int> q1;
    q1.push(1); q1.push(2); q1.push(3);

    // Act
    Queue<int> q2(q1);
    q1.push(5); q1.push(6); q1.push(7);

    // Assert
    EXPECT_FALSE(q1 == q2);
}

TEST(QueueTest,
Queue_Becomes_Equal_To_Another_After_Applying_Assignment_Operator) {
    // Arrange
    Queue<int> q1;
    q1.push(1); q1.push(2); q1.push(3);

    // Act
    Queue<int> q2 = q1;

    // Assert
    EXPECT_TRUE(q2 == q1);
}

TEST(QueueTest,
Queue_Copied_Via_Copy_Assignment_Operator_Has_Its_Own_Memory) {
    // Arrange
    Queue<int> q1;
    q1.push(1); q1.push(2); q1.push(3);

    // Act
    Queue<int> q2 = q1;
    q1.push(5); q1.push(6); q1.push(7);

    // Assert
    EXPECT_FALSE(q1 == q2);
}

TEST(QueueTest,
Inequality_Operator_Returns_Opposite_Result_From_Equality_Operator) {
    // Arrange
    Queue<int> q1, q2;
    q1.push(1); q1.push(2); q1.push(3);
    q2.push(1); q2.push(2); q2.push(3);

    // Act & Assert
    EXPECT_TRUE((q1 == q2) && !(q1 != q2));
}

