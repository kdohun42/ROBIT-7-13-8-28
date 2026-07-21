#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* 하나의 좌표를 저장하는 구조체 */
typedef struct {
    int x;
    int y;
} location;

int main()
{
    int num;
    int max_location = 0;

    double distance;
    double sum_distance;
    double max_sum_distance;

    location *arr;
    double *arr2;

    printf("입력 : ");

    /* 좌표 개수에 정수가 아닌 값이 입력되었는지 확인 */
    if (scanf("%d", &num) != 1) {
        printf("오류: 좌표의 개수는 정수로 입력해야 합니다.\n");
        return 1;
    }

    /* 다른 좌표와 거리를 비교하려면 좌표가 2개 이상 필요 */
    if (num < 2) {
        printf("오류: 좌표는 2개 이상 입력해야 합니다.\n");
        return 1;
    }

    /* 입력받은 좌표 개수만큼 좌표와 거리 합을 저장할 공간 할당 */
    arr = (location *)malloc(num * sizeof(location));
    arr2 = (double *)malloc(num * sizeof(double));

    /* 필요한 메모리가 정상적으로 할당되었는지 확인 */
    if (arr == NULL || arr2 == NULL) {
        printf("오류: 메모리 할당에 실패했습니다.\n");

        free(arr);
        free(arr2);

        return 1;
    }

    printf("좌표 입력\n");

    /* 각 좌표의 x값과 y값을 입력받아 구조체 배열에 저장 */
    for (int i = 0; i < num; i++) {
        if (scanf("%d %d", &arr[i].x, &arr[i].y) != 2) {
            printf("오류: 좌표는 두 개의 정수로 입력해야 합니다.\n");

            free(arr);
            free(arr2);

            return 1;
        }
    }

    /*
    각 좌표에서 나머지 모든 좌표까지의 거리를 계산하고
    계산한 거리의 총합을 arr2의 같은 인덱스에 저장한다.
    */
    for (int i = 0; i < num; i++) {
        sum_distance = 0.0;

        for (int j = 0; j < num; j++) {
            double x_difference;
            double y_difference;

            /* 두 좌표 사이의 x축과 y축 거리 차이 */
            x_difference = (double)arr[i].x - arr[j].x;
            y_difference = (double)arr[i].y - arr[j].y;

            /* 두 좌표 사이의 직선거리를 피타고라스 공식으로 계산 */
            distance = sqrt(x_difference * x_difference +
                            y_difference * y_difference);

            sum_distance += distance;
        }

        arr2[i] = sum_distance;
    }

    /*
    첫 번째 좌표의 거리 합을 기준값으로 설정하고
    더 큰 거리 합을 가진 좌표의 위치를 찾는다.
    */
    max_sum_distance = arr2[0];

    for (int i = 1; i < num; i++) {
        if (arr2[i] > max_sum_distance) {
            max_sum_distance = arr2[i];
            max_location = i;
        }
    }

    printf("출력: 가장 거리가 먼 좌표는 (%d, %d)이며, "
           "다른 좌표의 거리 총합은 약 %.1f입니다.\n",
           arr[max_location].x,
           arr[max_location].y,
           max_sum_distance);

    /* 동적 할당한 메모리 반환 */
    free(arr);
    free(arr2);

    return 0;
}