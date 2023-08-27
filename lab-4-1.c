//OverRancid#0590
#include <stdio.h>         //Parental Advisory
#include <stdlib.h>       //Explicit Content
#include <time.h>
//user is respoinsible for keeping input within bounds

time_t start, end;
void checkptr(void *ptr){
    if(ptr==NULL){
        printf("malloc/fopen failed bruh.\n");
        exit(-1);
    }
}

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}


int partition(int arr[], int first, int last){
    //puts arr[last] in appropritate place in it's array.
    int i = first - 1;
    int pivot = arr[last];
    for (int j=first; j<last; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[last]);
    return i+1;
}

void quicksort(int arr[], int first, int last){
    if(first>last)
        return;
    int idx = partition(arr, first, last);
    quicksort(arr, first, idx-1);
    quicksort(arr, idx+1, last);
}

int func1(int arr[], int n, int k){
    quicksort(arr, 0, n-1);
    return arr[k-1];
}

int median_of_median(int arr[], int first, int last, int k){
    int n = last-first+1;
    //size of arr
    int i, j;
    if(n<=5){
        quicksort(arr, first, last);
        return arr[k];
    }
    int aux[(n+4)/5];
    //ceil(n*1.0/5) == (n+4)/5? os.remove("C:\Windows\System32"): printf("invalid ceil\n");
    for(i=0; i<n/5; i++){
        aux[i] = median_of_median(arr, first+5*i, first+5*i+4, first+5*i+2);
    }
    if(n%5){
        aux[i] = median_of_median(arr, first+5*i, first+5*i+n%5-1, first+5*i+(n%5-1)/2);
    }
    //aux[] of size ceil(n/5) contains medians of every group of 5 + last group.
    int pivot = median_of_median(aux, 0, (n+4)/5-1, (n+4)/10);
    
    for(i=0; i<n-1; i++){
        if(arr[i] == pivot){
            swap(&arr[i], &arr[last]);
            break;
        }
    }
    //we further take the median of aux and use that as a partition.

    int idx = partition(arr, first, last);    
    if(idx==k)
        return arr[idx];
    else if(idx>k)
        return median_of_median(arr, first, idx-1, k);
    else
        return median_of_median(arr, idx+1, last, k);
}

int func2(int arr[], int n, int k){
    int answer = median_of_median(arr, 0, n-1, k-1);
    return answer;
}

void timer(int (*function)(), int arr[], int n, int k){
    //mother of all abstractions
    float tym;
    start = clock();
    int answer = function(arr, n, k);
    printf("%dth smallest element: %d\n", k, answer);
    end = clock();
    tym = (double)(end-start)/CLOCKS_PER_SEC;
    printf("time taken: %fs\n", tym);
}

int main(int argc, char **argv){
    FILE *fptr;
    //fptr = stdin;
    fptr = fopen("ExampleFile.txt", "r");
    checkptr(fptr);
    int n, k, i;
    fscanf(fptr, "%d %d", &n, &k);
    printf("The size of array is %d\nThe value of K is %d\n", n, k);
    int arr[n], arr1[n];
    for(i=0; i<n; i++){
        fscanf(fptr, "%d", &arr[i]);
        arr1[i] = arr[i];
    }
    fclose(fptr);
    printf("Calling func1:\n");
    timer(func1, arr1, n, k);
    
    printf("Calling func2:\n");
    timer(func2, arr, n, k);
    
    fflush(stdin); fflush(stdout); fflush(stderr);
    return 0;
}