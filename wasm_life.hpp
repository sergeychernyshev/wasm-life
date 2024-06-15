#include <string>

#define GRID_WIDTH 240
#define GRID_HEIGHT 180
#define BOX_SIZE 5

void randomize();
void calculate_next_generation();
void renderPixels();
std::string render();