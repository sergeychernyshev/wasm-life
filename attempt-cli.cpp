#include <iostream>
#include "attempt.hpp"

int main() {
  randomize();
  std::cout << attempt() << std::endl;

  return 0;
}