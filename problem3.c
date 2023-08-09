//OverRancid#0590
#include <stdio.h>      //Parental Advisory
#include <string.h>    //Explicit Content

int main(){
    
    char bit[32];
    __int32 answer = 0;
    scanf("%s", bit);
    int n = strlen(bit);
    char number[32];
    int i, x=0;
    for(i=32-n; i<32; i++){
        number[i] = (int)(bit[x++]-'0');
    }
    for(i=31-n; i>=0; i--){
        number[i] = number[i+1];
    }
    printf("0b");
    for(i=0; i<32; i++){
        printf("%d", number[i]);
        if(i%4==3){
            printf(" ");
        }
    }
    printf("\n");
    x=0;
    for(i=31; i>=0; i--, x++){
        if(number[i]){
            answer += 1<<x;
        }
    }
    printf("%d\n", answer);
    return 0;
}

