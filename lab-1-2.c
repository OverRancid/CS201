//OverRancid#0590
#include <stdio.h>      //Parental Advisory
#include <math.h>      //Explicit Content

int main(){
    __int32 n, i;
    printf("Enter Number:");
    scanf("%d", &n);
    int bin[32];

    int x = n;
    if(n<0){
        x = -n-1;
    }
    for(i=31; i>=0; i--, x/=2){
        bin[i] = x%2;
        if(n<0){
            bin[i] ^= 1;
        }
    }
    printf("0b");
    for(i=0; i<32; i++){
        printf("%d", bin[i]);
        if(i%4==3){
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}