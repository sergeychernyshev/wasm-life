#include "wasm_life.hpp"
#include <string>

#define GRID_WIDTH 250
#define GRID_HEIGHT 50

bool current_grid[GRID_HEIGHT][GRID_WIDTH];
// bool next_grid[GRID_HEIGHT][GRID_WIDTH];

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
