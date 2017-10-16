all: list.c
	gcc -o list list.c

run: all
	./list

clean:
	rm *o
	rm *~
