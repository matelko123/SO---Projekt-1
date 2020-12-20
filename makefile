all: clean main.cpp fileHelper.cpp
	clear
	g++ -pthread -std=c++17 -o main main.cpp fileHelper.cpp
	./main

clean:
	rm -rf main *.o
	clear