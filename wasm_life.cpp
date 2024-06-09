#include "wasm_life.hpp"
#include <string>

bool current_grid[GRID_HEIGHT][GRID_WIDTH];
bool next_grid[GRID_HEIGHT][GRID_WIDTH];

void calculate_next_generation() {
    for (int i = 0; i < GRID_HEIGHT; i++) {
        for (int j = 0; j < GRID_WIDTH; j++) {
            int neighbors = 0;

            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    if (x == 0 && y == 0) {
                        continue;
                    }

                    int new_x = i + x;
                    int new_y = j + y;

                    if (new_x < 0 || new_x >= GRID_HEIGHT || new_y < 0 || new_y >= GRID_WIDTH) {
                        continue;
                    }

                    if (current_grid[new_x][new_y]) {
                        neighbors++;
                    }
                }
            }

            if (current_grid[i][j]) {
                if (neighbors < 2 || neighbors > 3) {
                    next_grid[i][j] = false;
                } else {
                    next_grid[i][j] = true;
                }
            } else {
                if (neighbors == 3) {
                    next_grid[i][j] = true;
                } else {
                    next_grid[i][j] = false;
                }
            }
        }
    }

    for (int i = 0; i < GRID_HEIGHT; i++) {
        for (int j = 0; j < GRID_WIDTH; j++) {
            current_grid[i][j] = next_grid[i][j];
        }
    }
}

std::string render() {
    std::string output = "";

    for (int i = 0; i < GRID_HEIGHT; i++) {
        for (int j = 0; j < GRID_WIDTH; j++) {
            if (current_grid[i][j]) {
                output += "O";
            } else {
                output += " ";
            }
        }
        output += "\n";
    }

    return output;
}

void randomize() {
    for (int i = 0; i < GRID_HEIGHT; i++) {
        for (int j = 0; j < GRID_WIDTH; j++) {
            if (std::rand() > RAND_MAX / 2) {
                current_grid[i][j] = true;
            } else {
                current_grid[i][j] = false;
            }
        }
    }
}
