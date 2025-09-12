#include <stdlib.h>
#include <stdio.h>
#include "towers.h"

int main(int argc, char **argv)
{
    int n = 5;
    int from = 2;
    int dest = 3;
    if(argc > 1 && argc <= 2){
        n = atoi(argv[1]);
    }
    if (argc > 2 && argc <= 3) {
        n = atoi(argv[1]);
        from = atoi(argv[2]);
        if(dest == from){
            fprintf(stderr, "The Origin and Destination Towers cannot be the same");
            exit(-1);
        }
        if(dest > 3 || dest < 1){
            fprintf(stderr, "Invalid tower Destination");
            exit(-1);
        }
        if(from > 3 || from < 1){
            fprintf(stderr, "Invalid tower Origin");
            exit(-1);
        }
    }
    if (argc > 3) {
        n = atoi(argv[1]);
        from = atoi(argv[2]);
        dest = atoi(argv[3]);
        if(dest == from){
            fprintf(stderr, "The Origin and Destination Towers cannot be the same");
            exit(-1);
        }
        if(dest > 3 || dest < 1){
            fprintf(stderr, "Invalid tower Destination");
            exit(-1);
        }
        if(from > 3 || from < 1){
            fprintf(stderr, "Invalid tower Origin");
            exit(-1);
        }
    }
    towers(n, from, dest);
    exit(0);
}

