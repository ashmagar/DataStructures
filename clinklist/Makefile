all:main

data.o: data.h data.c
	gcc -Wall -g -c data.c

clinklist.o: clinklist.h clinklist.c
	gcc -Wall -g -c clinklist.c

main.o: main.c
	gcc -Wall -g -c main.c

main: data.o clinklist.o main.o
	gcc -Wall -g clinklist.o data.o main.o -o main

clean:
	rm *.o *~ main
