#include <iostream>
#include "wasm_life.hpp"

#include <unistd.h>

int main()
{
  randomize();

  unsigned int sleep = 1000000 / 10; // 1/10th of a second

  int i = 0;

  while (true)
  {
    i++;

    calculate_next_generation();

    std::cout << i << std::endl;
    std::cout << render() << std::endl;

    usleep(sleep);

    // scroll up to the top of the grid
    std::cout << "\033[" << GRID_HEIGHT + 2 << "A" << std::flush;
  }

  return 0;
}