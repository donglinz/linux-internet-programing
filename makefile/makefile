cacu:main.o add.o sub.o 
	g++ -o cacu main.o add.o sub.o
add.o:add.cpp
	g++ -c add.cpp -o add.o
sub.o:sub.cpp
	g++ -c sub.cpp -o sub.o
main.o:main.cpp
	g++ -c main.cpp -o main.o

clean:
	rm -f main.o add.o sub.o
