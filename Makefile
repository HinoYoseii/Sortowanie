all: sort
sort: main.o al.o
        g++ -o sort main.o al.o
main.o: main.cpp algorytmy.hpp
        g++ -c main.cpp
al.o: al.cpp algorytmy.hpp
        g++ -c al.cpp
clean:
        rm *.o