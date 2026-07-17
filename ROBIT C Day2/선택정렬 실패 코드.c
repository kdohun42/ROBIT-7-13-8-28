#include <stdio.h>
int main(){

    int arr[] = {14,2,10,5,1,3,17,7};
    int max = 0;
    int max_index = 0;
    int change_number = 0;
    int i = 0;
    int j = 0;

    printf("정렬이 안된 숫자들 :");
    for(int i = 0; i < 8; i++){
        printf("%d ", arr[i]);
    }


    for( i = 0; i < 8; i++){
        for( j = 0; j < 8 - i; j++){
            if ( arr[j] > max ){
            max = arr[j];
            max_index = j;

            }
            change_number = arr[7-j];
            arr[7-j] = max;
            arr[max_index] = change_number;
        }
    }

    printf("\n최댓값 찾기 : %d", max);
    printf("\n최댓값 인덱스 : %d", max_index);

    printf("\n정렬된 숫자들 : ");
    for(int i = 0; i < 8; i++){
        printf("%d ", arr[i]);
    }


    return 0;
}