
#include <emscripten/bind.h>
#include "wasm_life.hpp"

using namespace emscripten;


EMSCRIPTEN_BINDINGS(randomize) {
   function("randomize", &randomize);
}

EMSCRIPTEN_BINDINGS(calculate_next_generation) {
   function("calculate_next_generation", &calculate_next_generation);
}

EMSCRIPTEN_BINDINGS(render) {
   function("render", &render);
}
