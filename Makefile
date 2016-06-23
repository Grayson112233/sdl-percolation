main: main.o algorithm.o visualization.o
	gcc main.o algorithm.o visualization.o -L/opt/local/lib -lSDL2 -Wall -o main --std=c99

main.o: main.c
	gcc -Wall -c main.c --std=c99

algorithm.o: algorithm.c
	gcc -Wall -c algorithm.c --std=c99

visualization.o: visualization.c
	gcc -Wall -c visualization.c --std=c99