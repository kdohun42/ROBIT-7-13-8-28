// 과제-7
#include <stdio.h>

int main()
{
    int n, r;
    int n_fac = 1, nr_fac = 1, r_fac = 1;
    int nr1_fac = 1, n1_fac = 1;
    int nPr, nTTr = 1, nCr, nHr;

    printf("n과 r을 입력하시오 : ");
    scanf("%d %d", &n, &r);

    if (n <= 0 || r < 0) {
        printf("n은 1 이상 r은 0 이상이어야 합니다.\n");
        return 1;
    }
    if (r > n) {
        printf("r은 n보다 클 수 없습니다.\n");
        return 1;
    }
    // n!
    for (int i = 1; i <= n; i++) {
        n_fac *= i;
    }
    // (n-r)!
    for (int i = 1; i <= n - r; i++) {
        nr_fac *= i;
    }
    // r!
    for (int i = 1; i <= r; i++) {
        r_fac *= i;
    }
    // (n+r-1)!
    for (int i = 1; i <= n + r - 1; i++) {
        nr1_fac *= i;
    }
    // (n-1)!
    for (int i = 1; i <= n - 1; i++) {
        n1_fac *= i;
    }
 
    nPr = n_fac / nr_fac;

    for (int i = 0; i < r; i++) {
        nTTr *= n;
    }

    nCr = n_fac / (nr_fac * r_fac);
    nHr = nr1_fac / (r_fac * n1_fac);

    printf("순열: %d\n", nPr);
    printf("중복순열: %d\n", nTTr);
    printf("조합: %d\n", nCr);
    printf("중복조합: %d\n", nHr);
    return 0;
}