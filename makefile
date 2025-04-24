
CC := g++
CFLAGS := -O2 -Wall -Wextra -Wno-maybe-uninitialized -std=c++20
SRC_FOLDER := ./src
BIN_FOLDER := ./bin
INC_FOLDER := ./include
IFLAGS := -I./include/
LFLAGS := -L./bin/
SOURCES := $(wildcard $(SRC_FOLDER)/*.cpp)
INCLUDES := $(wildcard $(INC_FOLDER)/*.hpp)
BINARIES := $(addprefix $(BIN_FOLDER)/lib, $(addsuffix .a, $(basename $(notdir $(SOURCES)))))
LDFLAGS := -I./include/ $(addprefix -l, $(basename $(notdir $(SOURCES))))

all: main

main: ./main.cpp $(SOURCES) $(BINARIES)
	$(CC) $(CFLAGS) -g $< -o $(basename $<) $(LFLAGS) $(LDFLAGS)

$(BIN_FOLDER):
	mkdir $(BIN_FOLDER)

$(BIN_FOLDER)/libvectorImpl.a: $(SRC_FOLDER)/vectorImpl.cpp $(INC_FOLDER)/vectorImpl.hpp
	if [ -d $(BIN_FOLDER) ]; then : ; else mkdir $(BIN_FOLDER); fi
	rm -f $@
	$(CC) $(CFLAGS) $< -c -o $(basename $@).o $(IFLAGS)
	ar rcs $@ $(basename $@).o
	rm -f $(basename $@).o

.PHONY: run qcPerf qcRead clean

run: main
	./main

qcPerf:
	clang-tidy -checks="-*,boost-*,clang-analyzer-*,modernize-*,performance-*,cppcoreguidelines-*,-cppcoreguidelines-avoid-magic-numbers" main.cpp ./src/* ./include/* -- -I./include/ -std=c++20

qcRead:
	clang-tidy -checks="-*,boost-*,clang-analyzer-*,readability-*,-readability-magic-numbers" main.cpp ./src/* ./include/* -- -I./include/ -std=c++20

clean:
	rm -f ./main
	rm -rf ./bin/