#include <stdio.h>

int main(){
    int array[4][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12}
    };
    
    printf("배열A\n");

    /*
        배열을 원래 저장된 순서대로 출력
    */
    for(int i = 0; i < 4; i++){ // i는 행 번호이며 0행부터 3행까지 반복

        for(int j = 0; j < 3; j++){ // j는 열 번호이며 0열부터 2열까지 반복

            /*
                array[i][j]를 사용하여
                현재 i행 j열에 저장된 값을 출력한다.
            */
            printf("%d ", array[i][j]);
        }

        printf("\n"); 
    }

    printf("배열B\n");

    /*
        배열의 행과 열을 반대로 바꾸어 출력
    */
    for(int i = 0; i < 3; i++){ // 원래 배열의 열 번호를 기준으로 반복

        for(int j = 0; j < 4; j++){ // 원래 배열의 행 번호를 기준으로 반복

            printf("%d ", array[j][i]);
        }

        printf("\n"); 
    }

    return 0; 
}