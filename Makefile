all: attempt.wasm attempt

attempt.wasm: attempt.cpp attempt_bindings.cpp
	emcc -I. -o attempt.js -Oz -s MODULARIZE=1 -s EXPORT_NAME=createModule --bind attempt.cpp attempt_bindings.cpp

attempt: cli.cpp attempt.cpp
	g++ -o attempt cli.cpp attempt.cpp
	chmod a+x attempt

clean:
	rm -f attempt attempt.js attempt.wasm