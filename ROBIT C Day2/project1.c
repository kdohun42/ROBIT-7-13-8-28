#include <stdio.h>

void type1_print(int size);
void type2_print(int size);
void type3_print(int size);
void type4_print(int size);


int main(){

    int size = 0;
    int type = 0;

    printf("사이즈와 종류를 입력하시오.");
    scanf("%d %d", &size, &type);

    if( size % 2 == 0){
        printf("길이는 홀수만 가능합니다.");
        return 0;
    }
    else{
        if(type == 1){
            type1_print(size);
        }
        else if(type == 2){
            type2_print(size);
        }
        else if(type == 3){
            type3_print(size);
        }
        else if(type == 4){
            type4_print(size);
        }
        else{
            printf("종류는 1,2,3,4 중 선택해주세요.\n");
            return 0;
        }
    }
    return 0;
}

void type1_print(int size){
    int n = size / 2;
    for(int i = 1; i <= n + 1; i++){
        for( int j = 0; j < i; j++){
            printf("*");
        }
        printf("\n");
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i; j++){
            printf("*");
        }
        printf("\n");
    }
}
void type2_print(int size){

    int n = size / 2;
    for(int i = 1; i <= n+1; i++){
        for(int j = 0; j <= n - i; j++){
            printf(" ");
        }
        for(int j = 0; j < i; j++){
            printf("*");
        }
        printf("\n");
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < i; j++){
            printf(" ");
        }
        for(int j = 0; j <= n - i; j++){
            printf("*");
        }
        printf("\n");
    }
}
void type3_print(int size){

    int n = size / 2;
    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < i; j++){
            printf(" ");
        }
        for(int j = 0; j < size - (i*2); j++){
            printf("*");
        }
        printf("\n");
    }
    for( int i = 1; i <= n; i++){
        for(int j = 0; j < n-i; j++){
            printf(" ");
        }
        for(int j = 0; j < (i*2) + 1; j++){
            printf("*");
        }
        printf("\n");
    }
}
void type4_print(int size){
    int n = size / 2;
    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < i; j++){
            printf(" ");
        }
        for(int j = 0; j <= n-i; j++){
            printf("*");
        }
        printf("\n");
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf(" ");
        }
        printf("*");
        for(int j = 0; j <= i; j++){
            printf("*");
        }
        printf("\n");
    }
}

