// 과제-5
#include <stdio.h>

int main()
{   
    int num;

    printf("숫자를 입력하세요.");
    scanf("%d", &num);

    int i = 0, j = 0;
    int num2 = num - 1;
    
    for (i = 0; i < num2; i++) {
        for (j = 0; j < i + 1; j++) {
            printf("*");
        }
        for (j = 0; j < num2 - i; j++) {
            printf("  ");
        }
        for (j = 0; j < i + 1; j++) {
            printf("*");
        }
        printf("\n");
    }
    for (i = 0; i < num; i++) {
        for (j = 0; j < num - i; j++) {
            printf("*");
        }
        for (j = 0; j < i; j++) {
            printf("  ");
        }
        for (j = 0; j < num - i; j++) {
            printf("*");
        }
        printf("\n");
    }
}