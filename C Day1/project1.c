// 과제-1
#include <stdio.h>

int main() {
    double avg = 0, max = 0, min = 0, num = 0;

    for (int i = 1; i < 6; i++) {
        printf("%d번째 실수를 입력하십시오. ", i);
        scanf("%lf", &num);

        avg = avg + num;

        if (i == 1) {
            max = num;
            min = num;
            continue;
        }
        if (num > max) {
            max = num;
        }
        if (num < min) {
            min = num;
        }
    }

    printf("---- 결과 ----\n");
    printf("평균은 %lf입니다.\n", avg / 5);
    printf("최댓값은 %lf입니다.\n", max);
    printf("최솟값은 %lf입니다.\n", min);
    return 0;
}