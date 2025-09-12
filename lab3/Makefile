#;-*-Makefile-*-
CFLAGS = -Wall -g
CC = gcc
all: insertionSort mergeSort mergeSort_stderr insertionSort_stderr

insertionSort: sortDriver.o metrics.o insertionSort.o
	gcc -o insertionSort sortDriver.o metrics.o insertionSort.o

mergeSort: sortDriver.o metrics.o mergeSort.o
	gcc -o mergeSort sortDriver.o metrics.o mergeSort.o

mergeSort_stderr: sortDriver.o metrics.o mergeSort_stderr.o
	gcc -o mergeSort_stderr sortDriver.o metrics.o mergeSort_stderr.o

insertionSort_stderr: sortDriver.o metrics.o insertionSort_stderr.o
	gcc -o insertionSort_stderr sortDriver.o metrics.o insertionSort_stderr.o

testMetrics: metrics.c
	gcc -o testMetrics -Wall -D TEST_METRICS metrics.c
	@-./testMetrics
	@-rm metrics.o core testMetrics 2> /dev/null

clean: 
	-@rm -f *~ *.o a.out core insertionSort mergeSort mergeSort_stderr insertionSort_stderr *.exe
