#include <stdio.h>

int size = 0, type = 0;


int main(){

    printf("사이즈와 종류를 입력하시오.");
    scanf("%d %d", &size, &type);

    return 0;
} 

void size_d(int size){ 
//길이 홀짝 판별
    if( size % 2 == 0){
        // 종류 선택
    }
    else
        printf("별을 그릴 수 없는 길이입니다.");
}

    if ( type == 1 ){

    }
    else if ( type == 2 ){

    }
    else if( type == 3 ){

    }
    else if ( type == 4){

    }
    else
        printf(" 종류는 4가지 입니다.");