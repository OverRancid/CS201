#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void query1(int *arr, int *CIarr, int n);
void query2(int *arr, int n);
void query_1(int* BItree, int n);
void query_2(int *BItree, int n);

void func1(int *arr, int n)
    {   
        int CIarr[n];
        CIarr[0]=arr[0];
        for(int j=1;j<n;j++)
        {
            CIarr[j]=CIarr[j-1]+arr[j];
        }
        printf("By function_1:\n");
        clock_t t;
        t = clock();
        arr[1]+=5;
        query1(arr,CIarr,n); 
        t = clock() - t;
        double time_taken1 = ((double)t)/CLOCKS_PER_SEC; // in seconds
        printf("The time taken for query 1 by function 1 is %f seconds.\n", time_taken1);
        printf("The incremented value of first indexed element is %d\n",CIarr[1]);
        
        clock_t t2;
        t2 = clock();
        query2(CIarr,n);
        t2 = clock() - t2;
        double time_taken2 = ((double)t2)/CLOCKS_PER_SEC; // in seconds
        printf("The time taken for query 2 by function 1 is %f seconds.\n", time_taken2);
    }

void query1(int *arr, int *CIarr, int n)
    {
        for(int i=1;i<n;i++)
        {
            CIarr[i]=CIarr[i]+5;
        }
    }

void query2(int *CIarr, int n)
{
    printf("The sum of first n-5 elements is %d\n",CIarr[n-6]);
}

void func2(int *a,int n){
    a[1]+=5;
    int j;
    int* BItree=(int *)malloc(sizeof(int));
    int m=1;
    BItree[0]=a[0];
    for(int i=1; i<n; i++){
        if(i==m){
            BItree=realloc(BItree,4*(2*m));
            m*=2;
        }
        BItree[i] = 0;
        int sum=0;
        j=i-(i&(-i));
        j++;
        for(int k=j; k<i+1; k++){
            sum+=a[k];
        }
        BItree[i]=sum;
    }

    printf("By function_2:\n");
        clock_t t;
        t = clock();
        query_1(BItree, n);
        t = clock() - t;
        double time_taken1 = ((double)t)/CLOCKS_PER_SEC; // in seconds
        printf("The time taken for query_1 by function 2 is %f seconds.\n", time_taken1) ; 
        printf("The incremented value of the first indexed elemt is %d\n",a[1]); 

        clock_t t2;
        t2 = clock();
        query_2(BItree, n-6);
        t2 = clock() - t2;
        double time_taken2 = ((double)t2)/CLOCKS_PER_SEC; // in seconds
        printf("The time taken for query 2 by function 2 is %f seconds.\n", time_taken2);
}

void query_1(int* BItree ,int n)
{
    int idx=1;
    while(idx<=n)
    {
        BItree[idx]+= 5;
        idx+= (idx & -idx);
    }
}

void query_2(int *BItree, int n)
{
    int sum=0;
    for(int i=n; i>0; (i-=(i & -i)))
    {
        sum+=BItree[i];
    }
    printf("The sum of first n-5 elements is %d\n",sum-5);
}




int main()
{
    char choice;
    printf("Please enter a choice: ");
    scanf(" %c", &choice);
    if(choice =='a')
    {
        FILE *f;
        f=fopen("ExampleFile.txt","r");
        if(f==NULL)
        {
            printf("Error in opening the file.\n");
            exit(0);
        }
        int *arr=(int *)malloc(sizeof(int));
        int i=0;
        int size=1;
        while(!feof(f))
        {
            fscanf(f,"%d",arr+i);
            i++;
            if(i==size)
            {
                arr=realloc(arr,4*(2*size));
                size=2*size;
            }
        }
        i--;
        printf("%d\n",i);
        func1(arr,i);
        func2(arr,i);
    }
    else if(choice=='b')
    {
        int *arr=(int *)malloc(sizeof(int));
        int i=0;
        int size=1;
        printf("Please input an integer array with space-separator and press Enter when done: ");
        while(1)
        {
            scanf("%d",&arr[i]);
            i++;
            if(i==size)
            {
                arr=realloc(arr,4*(2*size));
                size=2*size;
            }
            char y;
            scanf("%c",&y);
            if(y=='\n')
            {
                break;
            }
        }
        printf("The array size is %d\n",i);
        func1(arr,i);
        func2(arr,i);
    }
    else
    {
        printf("Wrong input\n");
    }
    return 0;
}