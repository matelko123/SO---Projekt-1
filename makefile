all: clean
	clear
	g++ main.cpp -o out
	./out

clean:
	rm -rf out *.o
	clear