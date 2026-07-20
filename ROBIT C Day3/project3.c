#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N1, N2;
    int **arr;
    int top, bottom, left, right;
    int row, col;
    int number = 1;
    int i, j;

    /* N1은 행의 개수, N2는 열의 개수 */
    printf("행과 열을 입력하시오 :");
    scanf("%d %d", &N1, &N2);

    /* 예외처리 */
    if (N1 <= 0 || N2 <= 0) {
        printf("행과 열은 양수여야 합니다.\n");
        return 1;
    }

    /* N1개의 행 포인터를 동적 할당 */
    arr = (int **)malloc(sizeof(int *) * N1);

    if (arr == NULL) {
        printf("메모리 할당 실패\n");
        return 1;
    }

    /* 각 행마다 N2개의 정수 공간을 동적 할당 */
    for (i = 0; i < N1; i++) {
        arr[i] = (int *)malloc(sizeof(int) * N2);

        if (arr[i] == NULL) {
            printf("메모리 할당 실패\n");

            /* 이전에 할당한 행들의 메모리 해제 */
            for (j = 0; j < i; j++) {
                free(arr[j]);
            }

            free(arr);
            return 1;
        }
    }

    /* 아직 숫자가 채워지지 않은 영역의 경계 */
    top = 0;
    bottom = N1 - 1;
    left = 0;
    right = N2 - 1;

    while (top <= bottom && left <= right) {

        /* 위쪽 행을 왼쪽에서 오른쪽으로 채움 */
        for (col = left; col <= right; col++) {
            arr[top][col] = number++;
        }
        top++;

        /* 오른쪽 열을 위에서 아래로 채움 */
        for (row = top; row <= bottom; row++) {
            arr[row][right] = number++;
        }
        right--;

        /* 아래쪽 행이 남아 있으면 오른쪽에서 왼쪽으로 채움 */
        if (top <= bottom) {
            for (col = right; col >= left; col--) {
                arr[bottom][col] = number++;
            }
            bottom--;
        }

        /* 왼쪽 열이 남아 있으면 아래에서 위로 채움 */
        if (left <= right) {
            for (row = bottom; row >= top; row--) {
                arr[row][left] = number++;
            }
            left++;
        }
    }

    /* 완성된 배열 출력 */
    for (i = 0; i < N1; i++) {
        for (j = 0; j < N2; j++) {
            printf("%4d", arr[i][j]);
        }
        printf("\n");
    }

    /* 동적으로 할당한 메모리 해제 */
    for (i = 0; i < N1; i++) {
        free(arr[i]);
    }

    free(arr);

    return 0;
}