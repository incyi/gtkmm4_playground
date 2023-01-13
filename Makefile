###############################################################################
# Makefile for my gtkmm4_playground                                           #
###############################################################################

# the compiler: gcc for C program, define as g++ for C++
CXX = g++

BUILD_USER := $(shell whoami | grep -o '^\S*')
BUILD_MACHINE := $(shell hostname | grep -o '^\S*')
BUILD_GCC_VERSION := $(shell gcc --version | grep ^gcc | sed 's/^.* //g')

# compiler flags:
#  -g     - this flag adds debugging information to the executable file
#  -Wall  - this flag is used to turn on most compiler warnings
CFLAGS  = -g -Wall 
CFLAGS += -DBUILD_MACHINE=\"$(BUILD_MACHINE)\"
CFLAGS += -DBUILD_USER=\"$(BUILD_USER)\"
CFLAGS += -DBUILD_GCC_VERSION=\"$(BUILD_GCC_VERSION)\"

SRC = Source/Main.cpp
SRC += Source/MainWindow.cpp

INCLUDE_FOLDER += Include

OUTPUT_FOLDER = Bin
OUTPUT_FILE = $(OUTPUT_FOLDER)/gtkmm4_playground

gtkmm4_playground: $(SRC)
ifeq ($(OS),Windows_NT)
## This should be Windows
	$(CXX) \
	$(CFLAGS) \
	$(SRC) \
	-I $(INCLUDE_FOLDER) \
	-o $(OUTPUT_FILE) \
	-std=c++20 \
	`pkg-config --cflags --libs gtkmm-3.0`
else
## This should be linux
	$(CXX) \
	$(CFLAGS) \
	$(SRC) \
	-I $(INCLUDE_FOLDER) \
	-o $(OUTPUT_FILE) \
	-std=c++17 \
	`pkg-config --cflags --libs gtkmm-3.0`
endif

clean:
	rm -rf $(OUTPUT_FILE).exe
	rm -rf $(OUTPUT_FOLDER)/*.dll

run:
	./$(OUTPUT_FILE).exe

## Copy rquired dlls to run it on Windows ! Credits to: https://stackoverflow.com/questions/49092784/
distrib:
	ldd $(OUTPUT_FILE) | grep '\/mingw.*\.dll' -o | xargs -I{} cp "{}" ./$(OUTPUT_FOLDER)
