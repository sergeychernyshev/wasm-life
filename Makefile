all: attempt_bindings.wasm attempt_bindings.js attempt-cli attempt.html attempt.js attempt.wasm

.PHONY: all clean

# attempt_bindings.html is created manually so we just build a WASM and JS files
attempt_bindings.wasm attempt_bindings.js: attempt.cpp attempt_bindings.cpp
	emcc -I. -o attempt_bindings.js -Oz -s MODULARIZE=1 -s EXPORT_NAME=createModule --bind attempt.cpp attempt_bindings.cpp

# HTML, JS and WASM files are created by emscripten
attempt.html: attempt.cpp attempt-cli.cpp
	emcc attempt-cli.cpp attempt.cpp -o attempt.html

# just a CLI desktop version of the same code
attempt-cli: attempt.cpp attempt-cli.cpp
	g++ -o attempt-cli attempt-cli.cpp attempt.cpp
	chmod a+x attempt-cli

clean:
	rm -f attempt-cli \
		attempt.js attempt.wasm attempt.html \
		attempt_bindings.js attempt_bindings.wasm