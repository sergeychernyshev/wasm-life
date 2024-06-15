[![Compiling the WASM Life project 🌱 and Playing 🌎 GitTerra 🗺️](https://github.com/sergeychernyshev/wasm-life/actions/workflows/life_and_gitterra.yml/badge.svg)](https://github.com/sergeychernyshev/wasm-life/actions/workflows/life_and_gitterra.yml)

# Conway's Game of Life in WebAssembly

A simple project using WASM using emscripten and JS bindings using embind.

It implements [Conway's Game of Life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life) that runs in the browser using C++ code compiled to WebAssembly.

## See it in action

You can see the app running on our GitHub Pages:
https://sergeychernyshev.github.io/wasm-life/

## Build it yourself

Use `make` to build the project. It will compile the C++ code to WebAssembly and generate JS bindings.

It will also build a CLI version of the app as well.

### Running the app

Open `index.html` in your browser using a local web server to run the app. Just opening it using `file://` protocol will not work because of CORS restrictions.

<!-- You can also run the CLI version of the app by running `./life-cli` in the terminal. -->

## We also play GitTerra

We also play [GitTerra](https://gitterra.com/), a game that generates a [map for our code](https://sergeychernyshev.github.io/wasm-life/gitterra/).
