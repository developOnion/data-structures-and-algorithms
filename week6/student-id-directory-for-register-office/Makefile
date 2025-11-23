.PHONY: clean run

app: bin/main.o
	g++ bin/main.o -o app

bin/main.o: main.cpp Student.hpp StudentManager.hpp
	mkdir -p bin
	g++ -c main.cpp -o bin/main.o

clean:
	rm -rf bin app

run: app
	./app