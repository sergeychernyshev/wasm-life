
#include <emscripten/bind.h>
#include "wasm_life.hpp"

using namespace emscripten;

EMSCRIPTEN_BINDINGS(render) {
   function("render", &render);
}

EMSCRIPTEN_BINDINGS(randomize) {
   function("randomize", &randomize);
}