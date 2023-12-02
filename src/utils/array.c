#include "utils.h"

void printArray(long int *array, int length){
    printf("\n");
    for(long int *i = array; i < array+length; i++)
        printf("%ld ",*i);
}

bool isSortedRandomly(long int *a, int n){
    while(--n >= 1)
        if(*(a + n) < *(a + n - 1))
            return false;
    return true;
}

bool isSorted(long int *array, int length, bool increasing){
	if(increasing){
		for(long int *i = array; i < array + length - 1; i++){
			if(*i > *(i+1)){
				printf("\n\tArray not sorted.");
				return false;
			}
		}
	}
	else{
		for(long int *i = array; i < array + length - 1; i++){
			if(*i < *(i+1)){
				printf("\n\tArray not sorted.");
				return false;
			}
		}
	}
	printf("\n\tArray sorted.");
	return true;
}

void fileAfterExec(long int *array, int length, bool display, bool time, unsigned long sec, unsigned long micro, bool sorted){
	FILE *txt = fopen("data.txt","a+");
	if(txt != NULL){
		if(display){
			fprintf(txt,"\n\tArray%ssorted:\n", sorted ? " " : " not ");
			for(long int *i = array; i < array + length; i++)
				fprintf(txt,"%ld ", *i);
			fprintf(txt,"\n");
		}
		if(time)
			fprintf(txt,"\n\tExecution time: %lu seconds %lu microseconds.\n", sec, micro);
	}
	else
		printf("%s", E001);
	if(txt != NULL)
		fclose(txt);
}

void fileBeforeExec(long int *array, int length, bool display, char *sort, int range, int choice){
	FILE *txt = fopen("data.txt","a+");
	if(txt != NULL){
		fprintf(txt,"\n\t%s algorithm with length of %u elements and range of 0 to %d %s.",sort, length,choice == 2 ? range : length, choice == 1 ? "ascending" : choice == 2 ? "randomly" : choice == 3 ? "descending" : "identical");
		if(display){
			fprintf(txt,"\n\tArray before sort:\n");
			for(long int *i = array; i < array + length; i++)
				fprintf(txt,"%ld ", *i);
			fprintf(txt,"\n");
		}
	}
	else
		printf("%s", E001);
	if(txt != NULL)
		fclose(txt);
}

void calculateTime(clock_t tic, clock_t toc, unsigned long *sec, unsigned long *micro){
	*sec = (unsigned long)(toc - tic) / CLOCKS_PER_SEC;
	*micro = (unsigned long)(toc - tic) % 1000000;
	printf("\n\tExecution time: %lu seconds %lu microseconds.\n", *sec, *micro);
}

void createArray(long int **array, int length){
	*array = malloc(length * sizeof(long int));
	if(!(*array)){
		printf("%s", E002);
		exit(1);
	}
}

void generateArray(long int *array, int length, short int choice, int randomRange){
	long int *i, j;
	switch(choice){
		case 1:
			for(i = array, j ^= j; i < array + length; i++, j++)
				*i = j;
			break;
		case 3:
			for(i = array, j ^= j; i < array + length; i++, j++)
				*i = length - j;
			break;
		case 4:
			for(i = array; i < array + length; i++)
				*i = 1;
			break;
		default:
			for(i = array; i < array + length; i++)
				*i = rand() % randomRange;
	}
}