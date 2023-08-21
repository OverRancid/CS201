//OverRancid#0590
#include <stdio.h>     //Parental Advisory
#include <stdlib.h>   //Explicit Content
#include <time.h>
#include <string.h>

void checkMalloc(void* ptr){
    if(ptr==NULL){
        printf("malloc failed bruh.\n");
        exit(0);
    }
}

int N, *arr, *CIarr, *BItree;
clock_t start, end;
double tym;

//Prefix Sum
//point update: O(N)
//range sum: O(1)
void function_1(){
    CIarr[0] = 0;
    for(int i=1; i<N; i++){
        CIarr[i] = CIarr[i-1] + arr[i];
    }
}

//Binary Index Tree
//point update: O(logN)
//range sum: O(logN)
void function_2(){
    BItree[0] = 0;
    int i, j;
    for(i=1; i<N; i++){
        BItree[i] = 0;
        for(j=i+1-(i&-i); j<= i; j++){
            BItree[i] += arr[j];
        }
    }
}

void show(int* x){
    for(int i=0; i<N; i++){
        printf("%d ", x[i]);
    }
    printf("\n");
}

int main(){
    FILE* fptr;
    unsigned n = 0x7ffffff; //adjust this value if malloc keeps failing
    int i;
    char *str = (char*)malloc((int)n*sizeof(char));
    checkMalloc(str);


    char instruction;
    printf("Please enter a choice: ");
    scanf("%c", &instruction);
    fflush(stdin); //flushing out the intruction character - to be able to use getline on stdin
    if(instruction=='a'){
        fptr = fopen("ExampleFile.txt", "r");
        if(fptr==NULL){
            printf("fopen failled bruh\n");
            exit(-1);
        }
        getline(&str, &n, fptr);
    }
    else if(instruction=='b'){
        printf("Please input an integer array with space-separator and press Enter when done: ");
        getline(&str, &n, stdin);
    }
    n = strlen(str);
    N = 1;
    for(i=0; i<n; i++){
        if(str[i]==' '){
            N++;
        }
    }
    printf("The array size is %d\n", N);
    arr = (int *)malloc(N*sizeof(int));
    checkMalloc(arr);
    int x=0, temp;
    //please make sure arr[0] = 0.
    for(i=0; i<N; i++){
        arr[i] = atoi(str+i+x);
        temp = arr[i];
        if(arr[i]==0){
            x++;
            continue;
        }
        while(temp){
            x++;
            temp/=10;
        }        
    }

    CIarr = (int *)malloc(N*sizeof(int));
    BItree = (int *)malloc(N*sizeof(int));
    checkMalloc(CIarr);
    checkMalloc(BItree);
    
    function_1();

    printf("By function_1:\n");
    start = clock();
    for(i=1; i<N; i++){
        CIarr[i]+=5;
    }
    //O(N) query
    //expected 10^9 operations in 1 second.
    end = clock();
    tym = (double)(end - start)/CLOCKS_PER_SEC;
    printf("The time taken for query_1 by function_1 is %f seconds.\n", tym);
    printf("The incremented value of the first index element is %d\n", CIarr[1]);    

    start = clock();
    int sum = CIarr[N-6];
    //O(1) query. Takes no time.
    end = clock();
    tym = (double)(end - start)/CLOCKS_PER_SEC;
    printf("The time taken for query_2 by function_1 is %f seconds\n", tym);
    printf("The sum of first n-5 elements is %d\n", sum);

    arr[1]+=5;
    function_2();
    
    printf("By function_2:\n");
    start = clock();
    i = 1;
    while(i<N){
        BItree[i] += 5;
        i += i&-i;
    }
    //O(logn) function. 0 time even for N=10^9
    end = clock();
    tym = ((double)(end - start))/CLOCKS_PER_SEC;
    printf("The time taken for query_1 by function_2 is %f seconds.\n", tym);
    printf("The incremented value of the first index element is %d\n", BItree[1]);    

    start = clock();
    sum = 0;
    i = N-6;
    while(i){
        sum += BItree[i];
        i -= i&-i;
    }
    //O(logn) function. 0 time even for N=10^9
    end = clock();
    tym = (double)(end - start)/CLOCKS_PER_SEC;
    printf("The time taken for query_2 by function_2 is %f seconds\n", tym);
    printf("The sum of first n-5 elements is %d\n", sum);
    
    return 0;
}

