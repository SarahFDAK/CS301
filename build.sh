#!/bin/sh

/usr/local/bin/nasm -f macho64 rules.s && ld -macosx_version_min 10.7.0 -g
nasm -f macho64 equipment.s -g
g++ -std=c++17 -Wall -no-pie -g rules.o equipment.o main.cpp game.cpp -o main -g
./main
