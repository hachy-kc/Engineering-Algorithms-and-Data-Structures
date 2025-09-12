#include <stdio.h>
#include <stdlib.h>
#include "mySort.h"
 

int main(int argc, char * argv[])
 
{
 
    int data[100000]; /* Array of ints to sort */
 
    int nDataItems;   /* number of actual items in the array */
 
    int i;
 
    
 
    if (argc == 1) {
        /* No command line arguments, use hardcoded test data */
        nDataItems = 4;
        data[0] = 10;
        data[1] = 20;
        data[2] = 30;
        data[3] = 40;
    } else {
        /* Command line arguments provided, use them to initialize data array */
        nDataItems = argc - 1;
        for (i = 0; i < nDataItems; i++) {
            /* Convert command line argument to integer */
            data[i] = atoi(argv[i + 1]);
        }
    }
 
    
 
    mySort(data, nDataItems);
 
    
 
    /* Check that the data array is sorted. */
 
    for(i = 0; i < nDataItems-1; i++) {
 
        if (data[i] > data[i+1]) {
 
            fprintf(stderr, "Sort error: data[%d] (= %d)"
 
              " should be <= data[%d] (= %d)- -aborting\n",
 
              i, data[i], i+1, data[i+1]);
 
            exit(1);
 
        }
 
    }
 
    
 
    /* Print sorted array to stdout */
 
    for(i = 0; i < nDataItems; i++) {
 
        printf("%d\n", data[i]);
 
    }
 
    exit(0);
 
}

