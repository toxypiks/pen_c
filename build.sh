#!/bin/sh

set -xe

mkdir -p bin/
cc -Wall -Wextra -ggdb -Iinclude -o ./bin/example src/example.c -lm
cc -Wall -Wextra -ggdb -Iinclude -o ./bin/test src/test.c -lm
clang -Wall -Wextra -Iinclude --target=wasm32 -o wasm.o -c ./src/wasm.c
wasm-ld -m wasm32 --no-entry --export-all --allow-undefined -o wasm.wasm wasm.o
./bin/example
./bin/test
