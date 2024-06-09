#include <iostream>
#include "wasm_life.hpp"

int main() {
  randomize();
  std::cout << render() << std::endl;

  return 0;
}