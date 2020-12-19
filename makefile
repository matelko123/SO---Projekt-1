all: clean main.cpp fileHelper.cpp
	clear
	g++ -o main main.cpp fileHelper.cpp
	./main

clean:
	rm -rf main *.o
	clear