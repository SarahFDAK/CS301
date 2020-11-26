#!/bin/sh

nasm -f macho64 rules.s -g
nasm -f macho64 equipment.s -g
nasm -f macho64 goals.s -g
g++ -std=c++17 -Wall -no-pie -g rules.o equipment.o goals.o game.cpp main.cpp -o main
./main
