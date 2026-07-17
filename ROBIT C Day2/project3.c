#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char input(void);

int main(){

    char input(void);
    return 0;
}

char input(void){

    char arr[8];

    printf("음 입력");
    for( int i = 0; i < 8; i++){
        scanf("%c", &arr[i]);
    }

    for( int i = 0; i < 8; i++){
        printf("%c", arr[i]);
    }

} return 