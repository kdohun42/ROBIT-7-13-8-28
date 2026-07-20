#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N;
    int **arr;
    int number = 1;
    int diagonal;
    int row, col;
    int start_row, end_row;
    int i, j;

    /* 배열의 행과 열 크기 입력 */
    printf("N X N(행과열), N을 입력하시오 :");
    scanf("%d", &N);

    if (N <= 0) {
        printf("N은 양수여야 합니다.\n");
        return 1;
    }

    /* N개의 행 포인터 동적 할당 */
    arr = (int **)malloc(sizeof(int *) * N);

    if (arr == NULL) {
        printf("메모리 할당 실패\n");
        return 1;
    }

    /* 각 행에 N개의 정수 공간 동적 할당 */
    for (i = 0; i < N; i++) {
        arr[i] = (int *)malloc(sizeof(int) * N);

        if (arr[i] == NULL) {
            printf("메모리 할당 실패\n");

            /* 이전에 할당된 행의 메모리 해제 */
            for (j = 0; j < i; j++) {
                free(arr[j]);
            }

            free(arr);
            return 1;
        }
    }

    /*
        같은 대각선의 행 번호와 열 번호를 더하면
        모두 같은 값이 나온다.

        N이 5이면 대각선 번호는 0부터 8까지이다.
    */
    for (diagonal = 0; diagonal <= 2 * N - 2; diagonal++) {

        /*
            앞쪽 대각선은 0행부터 시작하고,
            뒤쪽 대각선은 배열을 벗어나지 않도록
            시작 행을 아래로 이동한다.
        */
        if (diagonal < N) {
            start_row = 0;
            end_row = diagonal;
        }
        else {
            start_row = diagonal - N + 1;
            end_row = N - 1;
        }

        /* 각 대각선을 위쪽에서 아래쪽 방향으로 채움 */
        for (row = start_row; row <= end_row; row++) {
            col = diagonal - row;

            arr[row][col] = number;
            number++;
        }
    }

    /* 완성된 배열 출력 */
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%4d", arr[i][j]);
        }

        printf("\n");
    }

    /* 각 행의 메모리 해제 */
    for (i = 0; i < N; i++) {
        free(arr[i]);
    }

    /* 행 포인터 배열의 메모리 해제 */
    free(arr);

    return 0;
}