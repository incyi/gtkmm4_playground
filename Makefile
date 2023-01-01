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

hello_world: $(SRC)
	$(CXX) \
	$(CFLAGS) \
	$(SRC) \
	-o $(OUTPUT_FILE) \
	-std=c++20
	