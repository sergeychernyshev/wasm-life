
#include <emscripten/bind.h>
#include "wasm_life.hpp"

using namespace emscripten;

EMSCRIPTEN_BINDINGS(randomize)
{
   function("randomize", &randomize);
}

EMSCRIPTEN_BINDINGS(calculate_next_generation)
{
   function("calculate_next_generation", &calculate_next_generation);
}

EMSCRIPTEN_BINDINGS(render)
{
   function("render", &render);
}

EMSCRIPTEN_BINDINGS(renderPixels)
{
   function("renderPixels", renderPixels);
}

EMSCRIPTEN_BINDINGS(GRID_WIDTH)
{
   constant("GRID_WIDTH", GRID_WIDTH);
}

EMSCRIPTEN_BINDINGS(GRID_HEIGHT)
{
   constant("GRID_HEIGHT", GRID_HEIGHT);
}

EMSCRIPTEN_BINDINGS(BOX_SIZE)
{
   constant("BOX_SIZE", BOX_SIZE);
}