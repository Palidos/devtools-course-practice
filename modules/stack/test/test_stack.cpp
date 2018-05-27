// Copyright 2018 Gladyshev Alexey

#include <gtest/gtest.h>

#include <string>

#include "include/stack.h"

TEST(Gladyshev_Alexey_StackTest, Always_Correct_Test) {
    // Arrange
    int hello = 1;
    int world = 1;
    int result = 0;

    // Act
    result = hello + world;

    // Assert
    EXPECT_EQ(result, 2);
}

TEST(Gladyshev_Alexey_StackTest, Can_Create_Stack_With_My_Size) {
    // Arrange
    TStack<int> stack(47);
    int size = 0;

    // Act
    size = stack.GetSize();

    // Assert
    EXPECT_EQ(size, 47);
}

TEST(Gladyshev_Alexey_StackTest, Can_Create_Copy_Stack) {
    // Arrange
    TStack<int> stack(47);

    // Act
    TStack<int> copyStack(stack);

    // Assert
    EXPECT_EQ(stack.GetSize(), copyStack.GetSize());
}

TEST(Gladyshev_Alexey_StackTest, Can_Push_Value_On_Stack) {
    // Arrange
    TStack<int> stack(47);

    // Act
    stack.Push(47);

    // Assert
    EXPECT_EQ(stack.GetSP(), 1);
}

TEST(Gladyshev_Alexey_StackTest, Can_Pop_Value_From_Stack) {
    // Arrange
    TStack<int> stack(47);

    // Act
    stack.Push(47);

    // Assert
    EXPECT_EQ(stack.Pop(), 47);
}

TEST(Gladyshev_Alexey_StackTest, Can_See_Value_From_Top_Of_Stack) {
    // Arrange
    TStack<int> stack(47);

    // Act
    stack.Push(47);

    // Assert
    EXPECT_EQ(stack.Top(), 47);
    EXPECT_EQ(stack.GetSP(), 1);
}

TEST(Gladyshev_Alexey_StackTest, Can_Create_Empty_Stack) {
    // Arrange & Act
    TStack<int> stack(47);

    // Assert
    EXPECT_TRUE(stack.IsEmpty() == true);
}

TEST(Gladyshev_Alexey_StackTest, Can_Create_Full_Stack) {
    // Arrange
    TStack<int> stack(5);

    // Act
    for (int i = 0; i < 5; i++)
        stack.Push(i);

    // Assert
    EXPECT_TRUE(stack.IsFull() == true);
}

TEST(Gladyshev_Alexey_StackTest, Compare_Identical_Stacks) {
    // Arrange
    TStack<int> stack1(5);
    TStack<int> stack2(5);

    // Act
    for (int i = 0; i < 5; i++) {
        stack1.Push(i);
        stack2.Push(i);
    }

    // Assert
    EXPECT_TRUE(stack1 == stack2);
}

TEST(Gladyshev_Alexey_StackTest, Can_Assign_Stack) {
    // Arrange
    TStack<int> stack1(5);
    for (int i = 0; i < 5; i++)
        stack1.Push(i);

    // Act
    TStack<int> stack2(47);
    stack2 = stack1;

    // Assert
    EXPECT_TRUE(stack1 == stack2);
}

TEST(Gladyshev_Alexey_StackTest, Cant_push_into_overflow_5e2shAra) {
    // Arrange
    TStack<int> stack(5);
    for (int i = 0; i < 5; i++)
        stack.Push(i);

    // Act & Assert
    EXPECT_ANY_THROW(stack.Push(47));
}

TEST(Gladyshev_Alexey_StackTest, Cant_pop_from_empty_5e2shAra) {
    // Arrange
    TStack<int> stack(5);

    // Act & Assert
    EXPECT_ANY_THROW(stack.Pop());
}

TEST(Gladyshev_Alexey_StackTest, Cant_Top_from_empty_5e2shAra) {
    // Arrange
    TStack<int> stack(5);

    // Act & Assert
    EXPECT_ANY_THROW(stack.Top());
}
