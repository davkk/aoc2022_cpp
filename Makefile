.SILENT:

CC=g++
CFLAGS=-std=c++23 -O3 -Wsign-conversion -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wmisleading-indentation -Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wnull-dereference -Wuseless-cast -Wdouble-promotion -Wformat -Wimplicit-fallthrough

all: aoc

aoc: ./src/$(day)/main.cpp
	$(CC) $(CFLAGS) -o /tmp/aoc.out ./src/$(day)/main.cpp

run: aoc
	/tmp/aoc.out $(part)
