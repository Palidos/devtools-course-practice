// Copyright 2018 Zinoviev Vladimir

#include "include/game_of_life.h"
#include <stdexcept>

game_of_life::game_of_life(char** source, int rows, int columns) {
    if (source == nullptr)
        throw std::logic_error("Source array is null pointer.");

    if (rows <= 0 || columns <= 0)
        throw std::logic_error("Size can't be <= 0.");

    len1 = rows;
    len2 = columns;

    grid = new bool*[rows];
    for (int i = 0; i < rows; ++i) {
        grid[i] = new bool[columns];
    }

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < columns; ++j)
            switch (source[i][j]) {
            case '.':
                grid[i][j] = false;
                break;
            case '*':
                grid[i][j] = true;
                break;
            default:
            {
                for (int i = 0; i < len1; ++i)
                    delete[] grid[i];
                delete[] grid;
                throw std::logic_error("Bad source array.");
            }
            }
}

game_of_life::~game_of_life() {
    for (int i = 0; i < len1; ++i)
        delete[] grid[i];
    delete[] grid;
}

bool game_of_life::is_alive(int i, int j) {
    int neighbours = 0;
    bool up = i > 0, down = i < len1 - 1,
        left = j > 0, right = j < len2 - 1;

    if (up) {
        neighbours += grid[i - 1][j] ? 1 : 0;
        if (left)
            neighbours += grid[i - 1][j - 1] ? 1 : 0;
        if (right)
            neighbours += grid[i - 1][j + 1] ? 1 : 0;
    }
    if (left) {
        neighbours += grid[i][j - 1] ? 1 : 0;
        if (down)
            neighbours += grid[i + 1][j - 1] ? 1 : 0;
    }
    if (down) {
        neighbours += grid[i + 1][j] ? 1 : 0;
        if (right)
            neighbours += grid[i + 1][j + 1] ? 1 : 0;
    }
    if (right)
        neighbours += grid[i][j + 1] ? 1 : 0;

    if (neighbours > 3 || neighbours < 2)
        return false;
    if (neighbours == 3)
        return true;

    return grid[i][j];
}

void game_of_life::next_step() {
    bool** new_grid = new bool*[len1];

    for (int i = 0; i < len1; ++i) {
        new_grid[i] = new bool[len2];

        for (int j = 0; j < len2; ++j)
            new_grid[i][j] = is_alive(i, j);
    }

    bool** old_grid = grid;
    grid = new_grid;

    for (int i = 0; i < len1; ++i)
        delete[] old_grid[i];
    delete[] old_grid;
}

void game_of_life::get_grid(char** dest) {
    if (dest == nullptr)
        throw std::logic_error("Destination array is null pointer.");

    for (int i = 0; i < len1; ++i)
        for (int j = 0; j < len2; ++j)
            dest[i][j] = grid[i][j] ? '*' : '.';
}
