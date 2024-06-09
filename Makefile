all: wasm_life_bindings.wasm wasm_life_bindings.js wasm_life

.PHONY: all clean

# wasm_life_bindings.html is created manually so we just build a WASM and JS files
wasm_life_bindings.wasm wasm_life_bindings.js: wasm_life.hpp wasm_life.cpp wasm_life_bindings.cpp
	emcc -I. -o wasm_life_bindings.js -Oz -s MODULARIZE=1 -s EXPORT_NAME=createModule --bind wasm_life.cpp wasm_life_bindings.cpp

# just a CLI desktop version of the same code
wasm_life: wasm_life.hpp wasm_life.cpp wasm_life-cli.cpp
	g++ -o wasm_life wasm_life-cli.cpp wasm_life.cpp
	chmod a+x wasm_life

clean:
	rm -f wasm_life wasm_life_bindings.js wasm_life_bindings.wasm