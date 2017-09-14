/*
 * Name: Jonah Zukosky
 * Pawprint: jbzmv8
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int* readfile(char* filename,int size);
void bubble_sort(int* array,int size);
void selection_sort(int* array,int size);
void insertion_sort(int* array,int size);
double calculate_time(clock_t begin,clock_t end){
    double total = (double)(end-begin)/CLOCKS_PER_SEC;

    return total;
}

int main(int argc, char** argv){

    //PARAMETERS CHECK
    if(argc != 3){
        printf("Incorrect Input\nCorrect Input\n./a.out <size> <inputfile>\n");
        return 1;
    }

    //Variables and Pointers
    char* input_file;
    input_file = *(argv+2);
    int size = atoi(*(argv+1));
    int sort=0;
    int* array;
    int i;
    clock_t start;
    clock_t end;

    while( sort != -1){

        printf("Enter '1' for a bubble sort\nEnter '2' for a selection sort\nEnter '3' for an insertion sort\nEnter -1 to exit program\n");
        scanf("%d",&sort);
        printf("choice: %d\n", sort);

        if(sort == -1){
            return 0;
        }
        //READ FILE CALL
        array = readfile(input_file,size);

        if(sort == 1){
            
            start = clock();
            bubble_sort(array,size);
            end = clock();

            for(i=0;i<10;i++){
                printf("%d\n",*(array+i));
            }

            printf("Bubble Sort on %d integers took %lf seconds\n",size, calculate_time(start,end));
        }

        if(sort == 2){

            start = clock();
            selection_sort(array,size);
            end = clock();

            for(i=0;i<10;i++){
                printf("%d\n",*(array+i));
            }

            printf("Selection Sort on %d integers took %lf seconds\n",size,calculate_time(start,end));

        }

        if(sort == 3){

            start = clock();
            insertion_sort(array,size);
            end = clock();

            for(i=0;i<10;i++){
                printf("%d\n",*(array+i));
            }

            printf("Insertion Sort on %d integers took %lf seconds\n",size,calculate_time(start,end));

        }

        if(sort > 3 || sort < 1){
            printf("Incorrect Input. Try again.\n");

        }
        //FREES
        free(array);
    }

return 0;
}

int* readfile(char* filename,int size){
    //Variables and Pointers
    int i;
    FILE* fptr;
    int* array = malloc(sizeof(int)*500000);
    
    //Mem Check
    if(array == NULL){
        printf("Not enough memory. Exiting Program\n");
        return 0;
    }
    //FILE Check
    if((fptr = fopen(filename,"r")) == NULL){
        printf("Cannot open file. Exiting Program\n");
        return 0;
    }
    //Fscanf
    else{
        for(i=0;i<size;i++){
            fscanf(fptr,"%d", (array+i));
            
        }
    }
fclose(fptr);
return array;
}

void bubble_sort(int* array, int size){
    //Variables and Pointers
    int i, j;
    int swap;

    for(i=0;i<(size-1);i++){
        for(j=0;j<(size-i-1);j++){
            if(*(array+j) > *(array+j+1)){
                swap = *(array+j);
                *(array+j) = *(array+j+1);
                *(array+j+1) = swap;
            }
        }
    }
}

void selection_sort(int* array, int size){
    //Variables and Pointers
    int i,j,index;
    int swap;

    for(i=0;i<(size-1);i++){
        index = i;

        for(j=i+1;j<size;j++){
            if(*(array+j) < *(array+index)){
                index=j;
            }
        }
        if(index != i){
            swap = *(array+index);
            *(array+index) = *(array+i);
            *(array+i) = swap;
        }
    }
}

void insertion_sort(int* array, int size){
    //Variables and Pointers
    int insert;
    int hole;
    int i;

    for(i=1;i<size;i++){
        insert = *(array+i);
        hole = i;
        while(hole > 0 && *(array+(hole-1)) > insert){
            *(array+hole) = *(array+hole-1);
            hole--;
        }

        if(hole != i){
            *(array+hole) = insert;
        }
    }
}



