// 과제-2

#include <stdio.h>

int main()
{
    int n;
    int a = 0;       
    int b = 1;       
    int next;

    printf("n을 입력하시오: ");
    scanf("%d", &n);
    if (n < 2) {
        printf("2 이상의 수를 입력하시오.\n");
    }
    else {
        for (int i = 3; i <= n; i++) {
            next = a + b;
            a = b;
            b = next;
        }
        printf("%d번째 피보나치 수: %d\n", n, b);
    }
    return 0;
}

// f1 = 0
// f2 = 1
// f3 = f2 + f1 = 1
// f4 = f3 + f2 = f2 + f2 + f1 = 2
// f5 = f4 + f3 = f2+ +f2 + f2 + f1 + f1 = 3