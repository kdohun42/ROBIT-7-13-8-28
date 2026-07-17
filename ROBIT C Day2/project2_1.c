#include <stdio.h>

int main(void)
{
    //           0  1  2   3  4  5   6  7
    int arr[] = {14, 2, 10, 5, 1, 3, 17, 7};
    int max = 0, max_index = 0;
    int change_number;

    printf("정렬이 안 된 숫자들 : ");
    for ( int i = 0; i < 8; i++)
    {
        printf("%d ", arr[i]);
    }

    for ( int i = 0; i < 7; i++) // 0 1 2 3 4 5 6
    {
        // 현재 정렬 범위의 첫 번째 값을 최댓값으로 설정
        max = arr[0];
        max_index = 0;
        // 아직 정렬되지 않은 범위에서 최댓값 찾기
        for ( int j = 1; j < 8 - i; j++)
        {
            if (arr[j] > max)
            {
                max = arr[j];
                max_index = j;
            }
        }
        // 찾은 최댓값을 현재 범위의 마지막 위치와 교환
        change_number = arr[7 - i];
        arr[7 - i] = arr[max_index];
        arr[max_index] = change_number;
    }

    printf("\n정렬된 숫자들 : ");

    for ( int i = 0; i < 8; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}