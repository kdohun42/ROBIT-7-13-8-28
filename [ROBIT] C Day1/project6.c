#include <stdio.h>

int main(void)
{
    int n;
    int row;
    int i;

    printf("값을 입력하시오. ");
    scanf("%d", &n);

    for (row = 1; row <= n; row++)
    {
        for (i = 0; i < n - row; i++){
            printf(" ");
        }
        if (row == 1){
            printf("*");
        }
        else if (row == n){
            for (i = 0; i < 2 * n - 1; i++){
                printf("*");
            }
        }
        else{
            printf("*");
            for (i = 0; i < 2 * row - 3; i++){
                printf(" ");
            }
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
