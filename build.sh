#!/bin/sh

nasm -f macho64 rules.s -g
nasm -f macho64 equipment.s -g
g++ -std=c++17 -Wall -no-pie -g rules.o equipment.o main.cpp game.cpp -o main -g
./main
