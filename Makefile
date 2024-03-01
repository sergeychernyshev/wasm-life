all: attempt_bindings.wasm attempt attempt.html 

attempt_bindings.wasm: attempt.cpp attempt_bindings.cpp
	emcc -I. -o attempt_bindings.js -Oz -s MODULARIZE=1 -s EXPORT_NAME=createModule --bind attempt.cpp attempt_bindings.cpp

attempt.html: cli.cpp
	emcc cli.cpp attempt.cpp -o attempt.html

attempt: cli.cpp attempt.cpp
	g++ -o attempt cli.cpp attempt.cpp
	chmod a+x attempt

clean:
	rm -f attempt \
		attempt.js attempt.wasm attempt.html \
		attempt_bindings.js attempt_bindings.wasm