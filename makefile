all: main.o list.o
	gcc -o program main.o list.o
main.o: main.c list.h
	gcc -c main.c
list.o: list.c list.h
	gcc -c list.c
run:
	./program
clean:
	rm *.o
	rm program
