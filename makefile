CFILES   = $(wildcard *.cpp)
OBJFILES = $(CFILES:.cpp=.o)
OUT      = main

CC      = g++
CFLAGS 	= -g -Wall

$(OUT): $(OBJFILES)

clean:
	rm -f $(OBJFILES) $(OUT)

# CXX = g++
# CFLAGS = -pthread -std=c++17 -g -Wall

# target = out

# all: clean main.cpp fileHelper.cpp
# 	clear
# 	$(CXX) $(CFLAGS) -o $(target) main.cpp fileHelper.cpp
# 	./$(target)

# clean:
# 	rm -rf $(target) *.o
# 	clear