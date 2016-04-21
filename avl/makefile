all:main

data.o: data.h data.c
	gcc -Wall -g -c data.c

random.o: random.h random.c
	gcc -Wall -g -c random.c


timing.o: timing.h timing.c
	gcc -Wall -g -c timing.c

avl.o: avl.h avl.c
	gcc -Wall -g -c avl.c

main.o: main.c
	gcc -Wall -g -c main.c

main: data.o random.o timing.o avl.o main.o
	gcc -Wall -g data.o random.o timing.o avl.o main.o -o main

clean:
	rm *.o *~ main