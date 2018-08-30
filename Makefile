LIBS = src/Logicle.o src/FastLogicle.o src/zeroin.o

LIB = logicle

OPTS = -fPIC -std=c++11

all: main

main: src/main.cpp liblogicle.so
	g++ -o $@ $^ -l$(LIB) -L.

liblogicle.so: $(LIBS)
	g++ $(OPTS) -shared -o $@ $^

src/%.o: src/%.cpp
	g++ $(OPTS) -c -o $@ $^

.PHONY: run
run: main
	./$^

.PHONY: clean
clean:
	rm -f main
	rm -f src/*.o
	rm -f *.so
