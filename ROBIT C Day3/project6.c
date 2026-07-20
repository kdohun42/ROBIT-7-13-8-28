#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char input1[20];
    char input2[20];

    int N1 = 0, N2 = 0;
    int **arr;
    int top, bottom, left, right;
    int row, col;
    int number = 1;
    int error = 0;
    int i, j;

    printf("행과 열을 입력하시오: ");

    /* 숫자를 문자열 형태로 입력 */
    scanf("%19s %19s", input1, input2);

    /* 첫 번째 입력이 숫자로만 이루어졌는지 검사 */
    for (i = 0; input1[i] != '\0'; i++) {
        if (input1[i] < 48 || input1[i] > 57) {
            error = 1;
            break;
        }

        /* 문자를 실제 정수로 변환 */
        N1 = N1 * 10 + (input1[i] - 48);
    }

    /* 두 번째 입력이 숫자로만 이루어졌는지 검사 */
    for (i = 0; input2[i] != '\0'; i++) {
        if (input2[i] < 48 || input2[i] > 57) {
            error = 1;
            break;
        }

        /* 문자를 실제 정수로 변환 */
        N2 = N2 * 10 + (input2[i] - 48);
    }

    /* 숫자가 아닌 문자가 입력된 경우 */
    if (error == 1) {
        printf("입력 오류: 숫자만 입력해야 합니다.\n");
        return 1;
    }

    /* 행과 열이 양수인지 검사 */
    if (N1 <= 0 || N2 <= 0) {
        printf("행과 열은 양수여야 합니다.\n");
        return 1;
    }

    /* 행 포인터 배열 동적 할당 */
    arr = (int **)malloc(sizeof(int *) * N1);

    if (arr == NULL) {
        printf("메모리 할당 실패\n");
        return 1;
    }

    /* 각 행의 열 공간 동적 할당 */
    for (i = 0; i < N1; i++) {
        arr[i] = (int *)malloc(sizeof(int) * N2);

        if (arr[i] == NULL) {
            printf("메모리 할당 실패\n");

            /* 이전에 할당한 메모리 해제 */
            for (j = 0; j < i; j++) {
                free(arr[j]);
            }

            free(arr);
            return 1;
        }
    }

    /* 숫자를 채울 영역의 경계 설정 */
    top = 0;
    bottom = N1 - 1;
    left = 0;
    right = N2 - 1;

    /* 배열의 바깥쪽부터 시계 방향으로 숫자를 채움 */
    while (top <= bottom && left <= right) {

        /* 위쪽 행 */
        for (col = left; col <= right; col++) {
            arr[top][col] = number++;
        }
        top++;

        /* 오른쪽 열 */
        for (row = top; row <= bottom; row++) {
            arr[row][right] = number++;
        }
        right--;

        /* 아래쪽 행 */
        if (top <= bottom) {
            for (col = right; col >= left; col--) {
                arr[bottom][col] = number++;
            }
            bottom--;
        }

        /* 왼쪽 열 */
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