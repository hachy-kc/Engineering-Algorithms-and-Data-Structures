#include <stdlib.h>
#include <stdio.h>
char numToLetter(int num) {
	if(num == 0)
		return 'A';
	else if(num == 1)
		return 'B';
	else if(num == 2)
		return 'C';
	else if(num == 3)
		return 'D';
	else if(num == 4) 
		return 'E';
	else if(num == 5)
		return 'F';
	else if(num == 6)
		return 'G';
	else if(num == 7)
		return 'H';

}
void delete(char array[][3], char garbageArray[8], int count) {
	int i, j;
	for(i = 0; i < count; i++) {
		for(j = 0; j < 8; j++) {
			if(array[j][0] == garbageArray[i]) {
				array[j][0] = 'X';
			}
		}	 	 
	}	 
	
}

void garbageCheck(char array[][3], int current, int instances[8], int deleteOrNot) {
	int i, j = 0, count = 0;
	char garbageArray[8] = {""};
	instances[current] = 1;
	for(i = 0; i < 8; i++) {
		if((array[i][1] == 'A' || array[i][2] == 'A') && array[current][0] != 'A' && array[i][0] != 'A' && array[i][0] != 'Z') 
			instances[0] = 1;
		if((array[i][1] == 'B' || array[i][2] == 'B') && array[current][0] != 'B' && array[i][0] != 'B' && array[i][0] != 'Z') 
			instances[1] = 1;
		if((array[i][1] == 'C' || array[i][2] == 'C') && array[current][0] != 'C' && array[i][0] != 'C' && array[i][0] != 'Z') 
			instances[2] = 1;
		if((array[i][1] == 'D' || array[i][2] == 'D') && array[current][0] != 'D' && array[i][0] != 'D' && array[i][0] != 'Z') 
			instances[3] = 1;
		if((array[i][1] == 'E' || array[i][2] == 'E') && array[current][0] != 'E' && array[i][0] != 'E' && array[i][0] != 'Z') 
			instances[4] = 1;
		if((array[i][1] == 'F' || array[i][2] == 'F') && array[current][0] != 'F' && array[i][0] != 'F' && array[i][0] != 'Z') 
			instances[5] = 1;
		if((array[i][1] == 'G' || array[i][2] == 'G') && array[current][0] != 'G' && array[i][0] != 'G' && array[i][0] != 'Z') 
			instances[6] = 1;
		if((array[i][1] == 'H' || array[i][2] == 'H') && array[current][0] != 'H' && array[i][0] != 'H' && array[i][0] != 'Z') 
			instances[7] = 1;	   
	}
	for(i = 0; i < 8; i++) {
		if(instances[i] == 0) {
			j = 1;
		}
	}
	if(deleteOrNot == 0) {
		if(j == 1) {
			printf("Garbage: ");
			for(i = 0; i < 8; i++) {
				if(instances[i] == 0) 
					printf("%c ", numToLetter(i));
			}
			printf("\n");
		}
		else
			printf("No garbage.\n");
	}
	else if(deleteOrNot == 1){
		if(j == 1) {
			for(i = 0; i < 8; i++) {
				if(instances[i] == 0) {
					garbageArray[count] = numToLetter(i);
					instances[i] = 9;
					count++;
				}
			}
			delete(array, garbageArray, count);
		}
		else
			printf("No states deleted.");
	}
}

int letterToNum(char letter) {
	if(letter == 'A')
		return 0;
	else if(letter == 'B')
		return 1;
	else if(letter == 'C')
		return 2;
	else if(letter == 'D')
		return 3;
	else if(letter == 'E') 
		return 4;
	else if(letter == 'F')
		return 5;
	else if(letter == 'G')
		return 6;
	else if(letter == 'H')
		return 7;
	else
		return -1;

}

int next(char array[][3], int current, char input) {
	if(input == '0')
		return letterToNum(array[current][1]);
	else if(input == '1')
		return letterToNum(array[current][2]);
}

void print(char array[][3]) {
	int i, j;
	for (i = 0; i < 8; i++) {
		if(array[i][0] != 'Z') {
			for (j = 0; j < 3; j++) 
				printf("%c ", array[i][j]);
			printf("\n");
		}
		
	}	 

}
int main(int argc, char * argv[])
{
	int current = 0, i, j, trueInt = 0, numericalValue;
	int instances[8] = {0,0,0,0,0,0,0,0};
	char input[5];
	char array[8][3] = {{'A', 'B', 'E'}, {'B', 'A', 'G'}, {'C', 'F', 'H'}, {'D', 'H', 'A'}, {'E', 'G', 'D'}, {'F', 'E', 'D'}, {'G', 'G', 'C'}, {'H', 'F', 'B'}};
	printf("'Ctrl+D' to output the current state at any given time.\nOR\n'Ctrl+C' to terminate the application.\n");
	printf("The starting state is %c.\n", array[current][0]);
	while(1) {
		for(i = 0; i < 5; i++)
			input[i] = ' ';
		scanf(" %[^\n]s", input);

		if(input[0] == 'p')
			print(array);

		else if(input[0] == '0'|| input[0] == '1') {
			current = next(array, current, input[0]);
			printf("%c\n", array[current][0]);		
		}

		else if(input[0] == 'c') {
			for(i = 0; i < 8; i++) {
				if(array[i][0] == input[4])
					trueInt = 1;
			}
			if(trueInt == 1) {
				numericalValue = input[2] - '0';
				array[current][numericalValue + 1] = input[4];
			}
			else
				printf("%c is not a valid state.\n", input[4]);
			trueInt = 0;
		}

		else if(input[0] == 'g') {
			garbageCheck(array, current, instances, 0);
			for(i = 0; i < 8; i++) {
				if (instances[i] == 1)
					instances[i] = 0;
			}
		}
		else if(input[0] == 'd' && input[2] != '2' && input[2] != ' ') {
			if(letterToNum(input[2]) != -1) {
				garbageCheck(array, current, instances, 3);
				if(instances[letterToNum(input[2])] == 0) {
					instances[letterToNum(input[2])] = 9;
					array[letterToNum(input[2])][0] = 'Z';
					printf("Deleted.\n"); 
				}
				else 
					printf("Not deleted.\n");
				
			}
			else
				printf("Not deleted.\n");
			for(i = 0; i < 8; i++) {
				if (instances[i] != 9)
					instances[i] = 0;
			}
		}
		else if(input[0] == 'd') {
			garbageCheck(array, current, instances, 1);
			for(i = 0; i < 8; i++) {
				if (instances[i] == 1)
					instances[i] = 0;
			}
			for(i = 0; i < 8; i++) {
				if(array[i][0] == 'X')
					j = 1;
			}
			if(j == 1) {
				printf("Deleted: ");
				j = 0;
			}
			for(i = 0; i < 8; i++) {
				if(array[i][0] == 'X') {
					printf("%c ", numToLetter(i));
					array[i][0] = 'Z';
				}
			}
			printf("\n");	   	   
		}
		else if(input[0] == ' ') {
			printf("The current state is %c.\n", array[current][0]);
		}

	}
    exit(0);
}
