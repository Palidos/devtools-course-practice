// Copyright 2018 Zinoviev Vladimir

#include <gtest/gtest.h>

#include "include/game_of_life.h"

TEST(Game_Of_Life_Tests, Can_Create) {
    // Arrange
    char start[4][8] = {
        { '.', '.', '.', '.', '.', '.', '.', '.' },
        { '.', '.', '.', '.', '*', '.', '.', '.' },
        { '.', '.', '.', '*', '*', '.', '.', '.' },
        { '.', '.', '.', '.', '.', '.', '.', '.' } };

    char** grid = new char*[4];

    // Act

    for (int i = 0; i < 4; ++i) {
        grid[i] = new char[8];

        for (int j = 0; j < 8; ++j)
            grid[i][j] = start[i][j];
    }

    // Assert
    ASSERT_NO_THROW(game_of_life gol(grid, 4, 8));
}

TEST(Game_Of_Life_Tests, Throw_When_Create_With_nullptr) {
    // Arrange

    // Act

    // Assert
    ASSERT_ANY_THROW(game_of_life gol(nullptr, 1, 1));
}

TEST(Game_Of_Life_Tests, Throw_When_Create_With_Rows_Less_Than_1) {
    // Arrange
    char** grid;

    // Act

    grid = new char*[4];

    // Assert
    ASSERT_ANY_THROW(game_of_life gol(grid, 0, 1));
}

TEST(Game_Of_Life_Tests, Throw_When_Create_With_Columns_Less_Than_1) {
    // Arrange
    char** grid;

    // Act

    grid = new char*[4];

    // Assert
    ASSERT_ANY_THROW(game_of_life gol(grid, 1, 0));
}


TEST(Game_Of_Life_Tests, Throw_When_Create_With_Bad_Grid) {
    // Arrange
    char start[4][8] = {
        { 'a', 'b', '.', '.', '.', '.', '.', '.' },
        { '.', '.', '.', '.', '*', '.', '.', '.' },
        { '.', '.', '.', '*', '*', '.', '.', '.' },
        { '.', '.', '.', '.', '.', '.', '.', '.' } };

    char** grid = new char*[4];

    // Act

    for (int i = 0; i < 4; ++i) {
        grid[i] = new char[8];

        for (int j = 0; j < 8; ++j)
            grid[i][j] = start[i][j];
    }

    // Assert
    ASSERT_ANY_THROW(game_of_life gol(grid, 4, 8));
}

TEST(Game_Of_Life_Tests, Can_Do_Right_Next_Step_And_Get_Grid) {
    // Arrange
    char start[4][8] = {
        { '.', '.', '.', '.', '.', '.', '.', '.' },
        { '.', '.', '.', '.', '*', '.', '.', '.' },
        { '.', '.', '.', '*', '*', '.', '.', '.' },
        { '.', '.', '.', '.', '.', '.', '.', '.' } };

    char res_grid[4][8] = {
        { '.', '.', '.', '.', '.', '.', '.', '.' },
        { '.', '.', '.', '*', '*', '.', '.', '.' },
        { '.', '.', '.', '*', '*', '.', '.', '.' },
        { '.', '.', '.', '.', '.', '.', '.', '.' } };

    char** grid = new char*[4];
    char** test_grid = new char*[4];

    for (int i = 0; i < 4; ++i) {
        grid[i] = new char[8];
        test_grid[i] = new char[8];

        for (int j = 0; j < 8; ++j)
            grid[i][j] = start[i][j];
    }

    // Act
    game_of_life gol(grid, 4, 8);
    gol.next_step();
    gol.get_grid(test_grid);

    bool test = true;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 8; ++j)
            if (test_grid[i][j] != res_grid[i][j])
                test = false;
    }

    // Assert
    ASSERT_TRUE(test);
}

TEST(Game_Of_Life_Tests, Can_Do_Right_Next_Step_And_Get_Grid2) {
    // Arrange
    char start[4][8] = {
        { '.', '.', '.', '.', '.', '.', '.', '.' },
        { '.', '.', '.', '.', '.', '.', '.', '.' },
        { '.', '.', '.', '*', '*', '*', '.', '.' },
        { '.', '.', '.', '.', '.', '.', '.', '.' } };

    char res_grid[4][8] = {
        { '.', '.', '.', '.', '.', '.', '.', '.' },
        { '.', '.', '.', '.', '*', '.', '.', '.' },
        { '.', '.', '.', '.', '*', '.', '.', '.' },
        { '.', '.', '.', '.', '*', '.', '.', '.' } };

    char** grid = new char*[4];
    char** test_grid = new char*[4];

    for (int i = 0; i < 4; ++i) {
        grid[i] = new char[8];
        test_grid[i] = new char[8];

        for (int j = 0; j < 8; ++j)
            grid[i][j] = start[i][j];
    }

    // Act
    game_of_life gol(grid, 4, 8);
    gol.next_step();
    gol.get_grid(test_grid);

    bool test = true;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 8; ++j)
            if (test_grid[i][j] != res_grid[i][j])
                test = false;
    }

    // Assert
    ASSERT_TRUE(test);
}

TEST(Game_Of_Life_Tests, Test_For_20_steps_Game_And_Full_Destroy) {
    // Arrange
    char start[4][8] = {
        { '.', '.', '.', '.', '.', '.', '.', '.' },
        { '.', '.', '*', '.', '.', '.', '*', '.' },
        { '.', '*', '.', '*', '*', '.', '.', '.' },
        { '.', '.', '.', '.', '*', '*', '*', '.' } };

    char res_grid[4][8] = {
        { '.', '.', '.', '.', '.', '.', '.', '.' },
        { '.', '.', '.', '.', '.', '.', '.', '.' },
        { '.', '.', '.', '.', '.', '.', '.', '.' },
        { '.', '.', '.', '.', '.', '.', '.', '.' } };

    char** grid = new char*[4];
    char** test_grid = new char*[4];

    for (int i = 0; i < 4; ++i) {
        grid[i] = new char[8];
        test_grid[i] = new char[8];

        for (int j = 0; j < 8; ++j)
            grid[i][j] = start[i][j];
    }

    // Act
    game_of_life gol(grid, 4, 8);
    for (int i = 0; i < 20; ++i)
        gol.next_step();
    gol.get_grid(test_grid);

    bool test = true;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 8; ++j)
            if (test_grid[i][j] != res_grid[i][j])
                test = false;
    }

    // Assert
    ASSERT_TRUE(test);
}


TEST(Game_Of_Life_Tests, Throw_When_Get_Grid_To_nullptr) {
    // Arrange
    char start[4][8] = {
        { '.', '.', '.', '.', '.', '.', '.', '.' },
        { '.', '.', '.', '.', '*', '.', '.', '.' },
        { '.', '.', '.', '*', '*', '.', '.', '.' },
        { '.', '.', '.', '.', '.', '.', '.', '.' } };

    char** grid = new char*[4];

    for (int i = 0; i < 4; ++i) {
        grid[i] = new char[8];

        for (int j = 0; j < 8; ++j)
            grid[i][j] = start[i][j];
    }

    // Act
    game_of_life gol(grid, 4, 8);
    gol.next_step();

    // Assert
    ASSERT_ANY_THROW(gol.get_grid(nullptr));
}
