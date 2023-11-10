//Akshat Nagpal
//2022MCB1255
#include <stdio.h>         //Parental Advisory
#include <stdlib.h>       //Explicit Content
#include <time.h>        //OverRancid#0590

int c_insert[] = {0, 0, 0};
int c_quick[] = {0, 0, 0};
//Sorry for not using 6 different global variables.
//This allows for better abstraction
const char* file_in[] = {"sorted.txt", "reverse.txt", "AlmostSorted.txt"};
const char* insertion_out[] = {"insertion_sorted.txt", "insertion_reverse.txt", "insertion_AlmostSorted.txt"};
const char* quick_out[] = {"quick_sorted.txt", "quick_reverse.txt", "quick_AlmostSorted.txt"};
const char* stdout_str[] = {"%s\t\t%d\t\t%d\n", "%s\t\t%d\t%d\n", "%s\t%d\t\t%d\n"}; //🔥🔥✍🔥🔥
int idx;

const int arr_size = 10000;

/*
    for some reason 
    *x+=*y; *y=*x-*y; *x-=*y;
    *x^=*y; *y^=*x; *x^=*y;
    doesn't work for swapping in randomQuickSort
*/
void swap(int *x, int *y){
    int t=*x; *x=*y; *y=t;
}

int randomPartition(int arr[], int l, int r){
    int i = rand()%(r-l+1)+l;
    swap(&arr[i], &arr[r]);
    int pivot = arr[r];
    int part = l-1; 
    for (int j=l; j<=r-1; j++,c_quick[idx]++){
        if(arr[j]<pivot){
            part++;
            swap(&arr[part], &arr[j]);
        }
    }
    swap(&arr[part+1], &arr[r]);
    return part+1;
}

void randomQuickSort(int arr[], int l, int r){
    if(l<r){
        int part = randomPartition(arr, l, r);
        randomQuickSort(arr, l, part - 1);
        randomQuickSort(arr, part + 1, r);
    }
}
 

void insersionSort(int *arr){
    for(int i=1; i<arr_size; i++, c_insert[idx]++){
        for(int j=i-1; arr[j]>arr[j+1]; j--, c_insert[idx]++){
            swap(&arr[j], &arr[j+1]);
        }
    }
}

int main(){
    srand(time(NULL));      //Removing this and I will provide you a Ω(n^2) running test case.
    int A1[arr_size];
    int A2[arr_size];
    
    for(idx=0; idx<3; idx++){
        //decalre a file pointer
        FILE *fIO;                     

        //take input A1[]
        fIO = fopen(file_in[idx], "r");
        for(int i=0; i<arr_size; i++){
            fscanf(fIO, "%d", &A1[i]);
        }
        fclose(fIO);               

        //copy A1[] into A2[]
        for(int i=0; i<arr_size; i++){
            A2[i] = A1[i];
        }                           

        //perform insersion on A1[]. Number of comparisions is stored globally.
        insersionSort(A1);
        
        //output the sorted array A1[] into a file.
        fIO = fopen(insertion_out[idx], "w");
        for(int i=0; i<arr_size; i++){
            fprintf(fIO, "%d ", A1[i]);
        }
        fclose(fIO);

        //perform randomized quick sort on A2[]. Number of comparisions is stored globally.
        randomQuickSort(A2, 0, arr_size-1);

        //output the sorted array A2[] into a file.
        fIO = fopen(quick_out[idx], "w");
        for(int i=0; i<arr_size; i++){
            fprintf(fIO, "%d ", A2[i]);
        }
        fclose(fIO);
    }

    //stdout table
    printf("Comparisons by\t\tInsersion Sort\tRandomized Quick Sort\n");    
    for(int i=0; i<3; i++){
        printf(stdout_str[i], file_in[i], c_insert[i], c_quick[i]);  
    }
    return 0;
}