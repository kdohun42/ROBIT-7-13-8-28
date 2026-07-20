#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size = 0;
    int max, min, sum = 0;
    double avg;

    printf("입력할 숫자의 개수를 입력하세요: ");
    scanf("%d", &size);

    /* 배열의 크기는 1 이상이어야 함 */
    if (size <= 0) {
        printf("배열의 크기는 1 이상이어야 합니다.\n");
        return 1;
    }

    /* size개의 정수 공간을 0으로 초기화하여 동적 할당 */
    int *arr = (int *)calloc(size, sizeof(int));

    if (arr == NULL) {
        printf("메모리 할당에 실패했습니다.\n");
        return 1;
    }

    /* 배열에 숫자 입력 */
    for (int i = 0; i < size; i++) {
        printf("%d번째 숫자를 입력하세요: ", i + 1);
        scanf("%d", &arr[i]);
    }

    /* 첫 번째 값을 최댓값과 최솟값의 초기값으로 설정 */
    min = arr[0];
    max = arr[0];

    /* 최댓값, 최솟값, 합계를 한 번에 계산 */
    for (int i = 0; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }

        if (arr[i] < min) {
            min = arr[i];
        }

        sum += arr[i];
    }

    /* 정수 나눗셈을 방지하기 위해 sum을 double로 변환 */
    avg = (double)sum / size;

    printf("최댓값 = %d\n", max);
    printf("최소값 = %d\n", min);
    printf("합계 = %d\n", sum);
    printf("평균 = %.2f\n", avg);

    /* 동적으로 할당한 메모리 해제 */
    free(arr);

    return 0;
}