#include <stdio.h>

//void middle_process(int arr[8]);

int main(){
    
    int arr[8];
    int max = 0, max_index = 0;
    int change_number = 0;

    printf("입력\n");

    // 0 1 2 3 4 5 6 7
    for( int i = 0; i < 8; i++){
        printf("%d : ", i);
        scanf("%d", &arr[i]);
    }

    printf("sorting이 되는 중간 과정을 출력\n");

    for( int i = 0; i < 8; i++){
        printf("%d ", arr[i]);

    }
    printf("\n");

    for( int i = 0; i < 7; i++){

        max = arr[0];
        max_index = 0;

        for( int j = 1; j < 8 - i; j++){
            
            if(arr[j] >= max){
                max = arr[j];
                max_index = j;
            }

        }
        change_number = arr[7-i];
        arr[7-i] = arr[max_index];
        arr[max_index] = change_number;

            
        for ( int i = 0; i < 8; i++){    
            printf("%d ", arr[i]);            
        }
        printf("\n");

        for( int i = 0; i < 8; i++){
            if ( arr[i] < arr[i + 1]){
                break;
            }
            else{
                continue;
            }
        }
    }

    printf("출력\n");
    for ( int i = 0; i < 8; i++){
        printf("%d : %d\n", i, arr[i]);
    }
    return 0;
}

