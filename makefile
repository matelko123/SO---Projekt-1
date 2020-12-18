all: clean main.cpp fileHelper.cpp
	clear
	g++ -o out main.cpp fileHelper.cpp
	./out

clean:
	rm -rf out *.o
	clear