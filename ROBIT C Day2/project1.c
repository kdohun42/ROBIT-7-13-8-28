#include <stdio.h>

// 종류 1,2,3,4 그리는 함수 선언
void type1_print(int size); 
void type2_print(int size);
void type3_print(int size);
void type4_print(int size);


int main(){
    // size, type 변수 선언 및 입력 출력과정
    int size = 0;
    int type = 0;

    printf("사이즈와 종류를 입력하시오.");
    scanf("%d %d", &size, &type);
    // 길이가 홀수일 때만 가능하기 때문에 짝수일 때는 예외처리
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
            // 종류는 1,2,3,4 네가지만 있기 때문에 4 이상의 수를 입력했을 때는 예외처리 
            printf("종류는 1,2,3,4 중 선택해주세요.\n");
            return 0;
        }
    }
    return 0;
}
// 종류 1 출력 함수
void type1_print(int size){
    int n = size / 2; // 별을 한 번에 출력할 수 없기 때문에 길이를 정수 나눗셈하여 사용
    
    for(int i = 1; i <= n + 1; i++){ //세로 반복 for문, n+1로 길이 맞춰주기 ex) size = 7이면 n = 3이다. n+1 해줘 4번 반복하게한다. 
        for( int j = 0; j < i; j++){ //가로 반복 for문, i로 인해 점점 반복 횟수가 증가는 for문이다.  
            printf("*");
        }
        printf("\n"); // 줄넘김
    }

    for(int i = 0; i < n; i++){ // 세로 반복 for문, 위의 for문에서 n+1해줬기 때문에 그대로 n 사용 가능. ex) size = 7이면 n = 3이다. 그대로 n을 사용해 3번 반복한다.
        for(int j = 0; j < n - i; j++){ // 가로 반복 for문
            printf("*"); 
        }
        printf("\n"); // 줄넘김
    }
}
// 종류 2출력 함수
void type2_print(int size){
    int n = size / 2;
    for(int i = 1; i <= n+1; i++){ //세로 반복 for문, n+1로 길이 맞춰주기 ex) size = 7이면 n = 3이다. n+1 해줘 4번 반복하게한다.
        //가로 반복 for문
        for(int j = 0; j <= n - i; j++){ // i로 인해 점점 반복횟수가 줄어드는 for문이다. 공백 출력은 점점 줄어들어야 한다.
            printf(" ");
        } 
        for(int j = 0; j < i; j++){ // i로 인해 점점 반복횟수가 증가하는 for문이다. 별 출력은 점점 증가해야한다.
            printf("*");
        }
        printf("\n");
    }
    //위와 반대로 로직을 구성, 위는 공백이 점점 감소하는 것이었다면 아래는 공백이 점점 증가하는 것이다.
    for(int i = 1; i <= n; i++){ // 세로 반복 for문, 그대로 n사용
        //가로 반복 for문, 
        for(int j = 0; j < i; j++){ // i로 인해 반복횟수가 점점 증가하는 for문, 공백 출력은 점점 증가해야한다.
            printf(" ");
        }
        for(int j = 0; j <= n - i; j++){ // i로 인해 반복횟수가 점점 감소하는 for문, 별 출력은 점점 감소애햐한다.
            printf("*");
        }
        printf("\n");
    }
}
// 종류 3 출력 함수
void type3_print(int size){
    int n = size / 2;
    //세로 반복 for문
    for(int i = 0; i < n+1; i++){ // '='를 사용하지 않음으로써 i = 0 일 때는 실행되지 않는다.
        // 가로 반복 for문
        for(int j = 0; j < i; j++){
            printf(" ");
        }
        for(int j = 0; j < size - (i*2); j++){ // 종류 3은 별이 점점 2씩 증가하거나 감소하는 구조이다. size - (i*2)를 사용함으로써 한줄한줄 내려갈 때마다 별의 개수가 2개씩 줄어들게했다. 
            printf("*");
        }
        printf("\n");
    }
    // 세로 반복 for문
    for( int i = 1; i <= n; i++){ // int i = 1;로 설정함으로써 하위 for문이 실행되지 않는 것을 방지
        // 가로 반복 for문
        for(int j = 0; j < n-i; j++){
            printf(" ");
        }
        for(int j = 0; j < (i*2) + 1; j++){ // (i*2) + 1를 사용함으로써 별이 점점 2씩 증가하는 것을 구현
            printf("*");
        }
        printf("\n");
    }
}
//종류 4 출력 함수
void type4_print(int size){
    int n = size / 2;
    //세로 반복 for문
    for(int i = 0; i < n+1; i++){ // n+1번 반복
        //가로 반복 for문
        for(int j = 0; j < i; j++){ // 공백 출력, '='를 사용하지 않음으로써 첫 번째 실행시 공백이 출력되지 않음
            printf(" ");
        }
        for(int j = 0; j <= n-i; j++){ // i로 인해 점점 반복횟수 감소, 별 출력은 감소되야하기 때문
            printf("*");
        }
        printf("\n");
    }
    // 세로 반복 for문
    for(int i = 0; i < n; i++){
        //가로 반복 for문
        for(int j = 0; j < n; j++){ // 세로 반복 횟수 만큼 n개의 공백 출력
            printf(" ");
        }
        printf("*"); // 세로 반복 횟수만큼 별을 미리 출력하기 
        for(int j = 0; j <= i; j++){
            printf("*");
        }
        printf("\n");
    }
}

