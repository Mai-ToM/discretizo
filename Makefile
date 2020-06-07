all:
	gcc discretizo.c -fopenmp -o discretizo

run:
	./discretizo