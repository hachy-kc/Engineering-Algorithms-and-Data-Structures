#include "mySort.h"
#include "metrics.h"
#include <stdio.h>

void mySort(int array[], unsigned int first, unsigned int last)
    {
	int i, j, key;

   	for(i = first; i <= last; i++){
		myCopy(&array[i], &key);
		j = i-1;
		fprintf(stderr, "COPIED\n");
		

		while(j >= 0 && myCompare(array[j], key) >= 0){
			mySwap(&array[j], &array[j+1]);
			j--;
			fprintf(stderr, "			SWAPPED\n");
		}
		
	myCopy(&key, &array[j+1]);
	fprintf(stderr, "COPIED\n");
	}
}	
