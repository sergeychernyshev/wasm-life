#include <string>

#include "wasm_life.hpp"
#include "canvas_render.hpp"

bool grid_A[GRID_HEIGHT][GRID_WIDTH];
bool grid_B[GRID_HEIGHT][GRID_WIDTH];

bool *current_grid_ptr = &grid_A[0][0];
bool *next_grid_ptr = &grid_B[0][0];

void calculate_next_generation()
{
    for (int i = 0; i < GRID_HEIGHT; i++)
    {
        for (int j = 0; j < GRID_WIDTH; j++)
        {
            int neighbors = 0;

            for (int x = -1; x <= 1; x++)
            {
                for (int y = -1; y <= 1; y++)
                {
                    if (x == 0 && y == 0)
                    {
                        continue;
                    }

                    int new_x = i + x;
                    int new_y = j + y;

                    if (new_x < 0 || new_x >= GRID_HEIGHT || new_y < 0 || new_y >= GRID_WIDTH)
                    {
                        continue;
                    }

                    if (*(current_grid_ptr + new_x * GRID_WIDTH + new_y))
                    {
                        neighbors++;
                    }
                }
            }

            // update cells in next grid
            if (*(current_grid_ptr + i * GRID_WIDTH + j))
            {
                if (neighbors < 2 || neighbors > 3)
                {
                    *(next_grid_ptr + i * GRID_WIDTH + j) = false;
                }
                else
                {
                    *(next_grid_ptr + i * GRID_WIDTH + j) = true;
                }
            }
            else
            {
                if (neighbors == 3)
                {
                    *(next_grid_ptr + i * GRID_WIDTH + j) = true;
                }
                else
                {
                    *(next_grid_ptr + i * GRID_WIDTH + j) = false;
                }
            }
        }
    }

    bool *temp = current_grid_ptr;
    current_grid_ptr = next_grid_ptr;
    next_grid_ptr = temp;
}

std::string render()
{
    std::string output = "";

    for (int i = 0; i < GRID_HEIGHT; i++)
    {
        for (int j = 0; j < GRID_WIDTH; j++)
        {
            if (*(current_grid_ptr + i * GRID_WIDTH + j))
            {
                output += "O";
            }
            else
            {
                output += " ";
            }
        }
        output += "\n";
    }

    return output;
}

void renderPixels()
{
    renderOnCanvas(GRID_WIDTH, GRID_HEIGHT, BOX_SIZE, current_grid_ptr);
}

void randomize()
{
    for (int i = 0; i < GRID_HEIGHT; i++)
    {
        for (int j = 0; j < GRID_WIDTH; j++)
        {
            if (std::rand() > RAND_MAX / 2)
            {
                *(current_grid_ptr + i * GRID_WIDTH + j) = true;
            }
            else
            {
                *(current_grid_ptr + i * GRID_WIDTH + j) = false;
            }
        }
    }
}
