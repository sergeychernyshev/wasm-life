
#include <emscripten/bind.h>
#include "attempt.hpp"

using namespace emscripten;

EMSCRIPTEN_BINDINGS(attempt) {
   function("attempt", &attempt);
}