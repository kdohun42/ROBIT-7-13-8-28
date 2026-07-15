//과제-6

#include <stdio.h>

int main()
{
    int n = 0;
    int i, j;

    printf("숫자를 입력하세요.");
    scanf("%d", &n);

    for (i = 1; i <= n; i++){
        if (i == n){
            for (j = 0; j < 2 * n - 1; j++)
                printf("*");
        }
        else
            for (j = 0; j < n-i; j++){
                printf(" ");
            }
            printf("*");
            if(i>1){
                for (j = 0; j < 2 * (i - 1) - 1; j++){
                        printf(" ");
            }
                    printf("*");
            }
        printf("\n");
    }
    return 0;
}