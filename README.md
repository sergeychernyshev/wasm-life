[![we play GitTerra](https://github.com/sergeychernyshev/wasm-life/actions/workflows/life_and_gitterra.yml/badge.svg)](https://sergeychernyshev.github.io/wasm-life/gitterra/)

# Conway's Game of Life in WebAssembly

A simple project using WASM using emscripten and JS bindings using embind.

It implements [Conway's Game of Life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life) that runs in the browser using C++ code compiled to WebAssembly.

## How to build

Use `make` to build the project. It will compile the C++ code to WebAssembly and generate JS bindings.

It will also build a CLI version of the app as well.

## Running the app

Open `index.html` in your browser using a local web server to run the app. Just opening it using `file://` protocol will not work because of CORS restrictions.

You can also run the CLI version of the app by running `./life-cli` in the terminal.
