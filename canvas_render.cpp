#include <string>

#include "canvas_render.hpp"

#include <emscripten/val.h>

using emscripten::val;

// Use thread_local when you want to retrieve & cache a global JS variable once per thread.
thread_local const val document = val::global("document");

void renderOnCanvas(int width, int height, int size, bool *grid)
{
    val canvas = document.call<val>("getElementById", val("canvas"));
    val ctx = canvas.call<val>("getContext", val("2d"));

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            if (*(grid + y * width + x))
            {
                ctx.set("fillStyle", "green");
                ctx.call<void>("fillRect", x * size, y * size, size, size);
            }
            else
            {
                ctx.set("fillStyle", "black");
                ctx.call<void>("fillRect", x * size, y * size, size, size);
            }
        }
    }
}