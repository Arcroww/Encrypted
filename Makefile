all: program

program: main.o sha256.o sha512.o ccrypt.o cdecrypt.o
	g++ -g main.o sha256.o sha512.o ccrypt.o cdecrypt.o -o encrypted

main.o: src/main.cpp
	g++ -c src/main.cpp

sha256.o: src/sha256.cpp
	g++ -c src/sha256.cpp

sha512.o: src/sha512.cpp
	g++ -c src/sha512.cpp

ccrypt.o: src/ccrypt.cpp
	g++ -c src/ccrypt.cpp

cdecrypt.o: src/cdecrypt.cpp
	g++ -c src/cdecrypt.cpp

clean:
	rm -rf *o encrypted
