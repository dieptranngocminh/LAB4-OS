exercise2: main.o mem.o
	gcc main.o mem.o -o exercise2 -pthread
main.o: main.c
	gcc -c main.c -pthread 
mem.o: mem.h mem.c
	gcc -c mem.c -pthread
clean: rm *.o exercise2
