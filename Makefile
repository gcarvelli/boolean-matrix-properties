all:
	gcc -g -o main *.c -std=c99
	./main

debug:
	gdb main

clean:
	del -f *.o main
