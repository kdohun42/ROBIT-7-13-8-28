#include <stdio.h>

int main(){
    
    int arr[8];
    int max = 0, max_index = 0; // 최댓값과 최댓값 인덱스를 저장하는 변수
    int change_number = 0; // 선택 정렬에서 교환할 배열의 끝 숫자를 저장할 임의 변수

    printf("입력\n");

    // for문을 사용해 8번 입력 받기
    for( int i = 0; i < 8; i++){
        printf("%d : ", i);
        scanf("%d", &arr[i]);
    }

    printf("sorting이 되는 중간 과정을 출력\n");

    // 입력 받은 배열 출력
    for( int i = 0; i < 8; i++){
        printf("%d ", arr[i]);

    }
    printf("\n");

    // 선택 정렬
    for( int i = 0; i < 7; i++){

        max = arr[0]; // 최댓값을 배열의 첫 번째 값으로 저장
        max_index = 0; // 최댓값 인덱스를 배열의 첫 번째 인덱스로 저장

        // 8번 반복하여 최댓값 찾기
        for( int j = 1; j < 8 - i; j++){
            
            // 최댓값과 최댓값 인덱스 계속해서 갱신
            if(arr[j] >= max){
                max = arr[j];
                max_index = j;
            }

        }
        // 선택 정렬 핵심 
        change_number = arr[7-i]; // 최댓값과 배열의 끝값과 교환하기 위해서 배열의 끝값을 임의의 변수에 저장하기
        arr[7-i] = arr[max_index]; // 배열의 끝에 최댓값 저장하기
        arr[max_index] = change_number; // 최댓값이 있던 자리에 배열의 끝과 저장하기

        // 중간과정 출력
        for ( int i = 0; i < 8; i++){    
            printf("%d ", arr[i]);            
        }
        printf("\n");

        int end = 1; // 배열이 정렬 여부를 확인하기 위한 변수

        for( int i = 0; i < 7; i++){
            if ( arr[i] > arr[i + 1]){ // 앞쪽 숫자가 뒤쪽 숫자보다 정렬이 완료되지 않은 것
                end = 0;
                break;
            }
            }
        if(end == 1){  // 위의 if문을 만족하지 않으면 end 변수가 그대로 1이기 때문에 정렬 for문 종료
            break;
        }
    }
    // 선택 정렬된 배열 세로로 출력
    printf("출력\n");
    for ( int i = 0; i < 8; i++){
        printf("%d : %d\n", i, arr[i]);
    }
    return 0;
}

