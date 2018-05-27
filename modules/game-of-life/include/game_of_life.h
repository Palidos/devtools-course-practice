// Copyright 2018 Zinoviev Vladimir

#ifndef MODULES_GAME_OF_LIFE_INCLUDE_GAME_OF_LIFE_H_
#define MODULES_GAME_OF_LIFE_INCLUDE_GAME_OF_LIFE_H_

class game_of_life {
 private:
    bool** grid;
    int len1, len2;

 private:
    bool is_alive(int i, int j);

 public:
    game_of_life(char** source, int rows, int columns);
    ~game_of_life();
    void next_step();
    void get_grid(char** dest);
};

#endif  // MODULES_GAME_OF_LIFE_INCLUDE_GAME_OF_LIFE_H_
