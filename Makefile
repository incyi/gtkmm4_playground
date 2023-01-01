###############################################################################
# Makefile for my gtkmm4_playground                                           #
###############################################################################

# the compiler: gcc for C program, define as g++ for C++
CXX = g++

# compiler flags:
#  -g     - this flag adds debugging information to the executable file
#  -Wall  - this flag is used to turn on most compiler warnings
CFLAGS  = -g -Wall

SRC += Source/Main.cpp

OUTPUT_FILE = bin/gtkmm4_playground
OUTPUT_FOLDER = bin

hello_world: $(SRC)
ifeq ($(OS),Windows_NT)
## This should be Windows
	$(CXX) \
	$(CFLAGS) \
	$(SRC) \
	-o $(OUTPUT_FILE) \
	-std=c++20 \
	`pkg-config --cflags --libs gtkmm-3.0`
else
## This should be linux
	$(CXX) \
	$(CFLAGS) \
	$(SRC) \
	-o $(OUTPUT_FILE) \
	-std=c++20 \
	`pkg-config --cflags --libs gtkmm-3.0`
endif