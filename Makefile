main: src/main.cpp
	g++ src/main.cpp -o build/main
	./build/main

clean:
	rm ./build/main

run:
	./build/main