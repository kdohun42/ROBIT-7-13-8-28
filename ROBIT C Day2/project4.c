#include <stdio.h>

int subarr_find_sorting(); //부분 수열 찾기 및 정렬 함수 선언

int number_arr[100]; 
int N = 0, B = 0; 
int count = 0; // 부분 수열의 개수를 저장할 변수

int main(){
    printf("N : ");
    scanf("%d", &N);

    printf("B : ");
    scanf("%d", &B);
    // N 수열의 길이는 홀수만 가능함. 홀수가 아닐 시 예외처리
    if(N % 2 == 0){
        printf("수열의 길이는 홀수만 가능합니다.");
        return 0;
    }

    // 수열 입력 for문
    printf("수열 입력 : ");
    for(int i = 0; i < N; i++){
        scanf("%d", &number_arr[i]);
    }

    subarr_find_sorting();// 부분 수열 찾기 및 정렬 함수 호출

    printf("중앙값이 %d인 부분수열의 개수: %d", B, count);
    return 0;
}
// 부분 수열 찾기 및 정렬 함수 정의
int subarr_find_sorting(){
    
    int arr[100] = {0,}; // 부분 수열을 찾고 찾은 부분 수열을 저장할 배열(길이, 정렬등을 따로 수행하기 위해서) 

    // 부분 수열 찾기 및 정렬 핵심 부분
    for(int i = 0; i < N; i++){ // 
        for(int j = 0; j < N; j++){

            int subarr_len = j - i + 1; // 부분 수열의 길이(부분 수열의 홀수인지 아닌지 판별하기 위해서 생성)

            if(subarr_len % 2 == 0){ // 조건문을 이용해 홀수인지 아닌지 판별
                continue;
            }

            for(int k = i; k <= j; k++){
                arr[k-i] = number_arr[k];
            }
 
            // 오름차순 정렬
            for (int k = 0; k < subarr_len - 1; k++) {
                for (int l = 0; l < subarr_len - 1 - k; l++) {

                    if (arr[l] > arr[l + 1]) { // 정렬 핵심
                        int temp = arr[l]; // 큰 값을 저장할 임의의 변수 생성 및 큰 값 저장
                        arr[l] = arr[l + 1]; // 작은 값이 있던 자리에는 큰 값을 저장
                        arr[l + 1] = temp; // 큰 값이 있던 자리에 임의의 변수를 할당하면서 큰 값을 저장
                    }
                }
            }

            if(arr[subarr_len/2] == B){ // 부분 수열의 길이를 사용해서 부분 수열의 중앙값이 B인지 확인
                count += 1; // 맞다면 부분수열 개수 1씩 증가
            }
        }
    }

}