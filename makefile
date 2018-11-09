all: signals.o
	gcc -o go signals.o

signals.o: signals.c
	gcc -c signals.c

run:
	./go

clear:
	rm go
	rm *.o
