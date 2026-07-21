#include <stdio.h>
#include <stdlib.h>

/* 물품 이름과 금액을 하나의 물품 정보로 저장 */
typedef struct {
    char name[10];
    int money;
} item;

/* 두 문자열이 완전히 같은지 확인 */
int same_string(char str1[], char str2[]);

/* 찾을 물품과 이름이 같은 모든 물품의 금액을 합산 */
int compare(char check_item[], item list[], int num);

int main()
{
    int num;
    int sum_money;
    char check_item[10];
    item *list;

    printf("입력: ");

    /* scanf의 반환값이 1이 아니면 정수를 정상적으로 입력받지 못한 경우 */
    if (scanf("%d", &num) != 1) {
        printf("오류: 물품 개수는 정수로 입력해야 합니다.\n");
        return 1;
    }

    /* 물품 정보가 최소 1개 이상 있어야 비교가 가능함 */
    if (num <= 0) {
        printf("오류: 물품 개수는 1개 이상이어야 합니다.\n");
        return 1;
    }

    /*
    입력받은 물품 개수만큼 구조체 배열을 동적으로 생성한다.
    물품 개수가 실행할 때 결정되므로 일반 배열 대신 malloc을 사용한다.
    */
    list = (item *)malloc(sizeof(item) * num);

    /* malloc이 실패하면 list에 NULL이 저장되므로 이후 작업을 중단 */
    if (list == NULL) {
        printf("오류: 메모리 할당에 실패했습니다.\n");
        return 1;
    }

    /*
    각 물품의 이름과 금액을 구조체 배열에 저장한다.
    %9s는 name[10]에 최대 9글자만 입력받아 배열 범위를 넘지 않게 한다.
    */
    for (int i = 0; i < num; i++) {
        if (scanf("%9s %d", list[i].name, &list[i].money) != 2) {
            printf("오류: 물품 이름과 금액을 올바르게 입력해야 합니다.\n");

            /* 오류로 프로그램을 종료하기 전에 할당한 메모리를 해제 */
            free(list);
            return 1;
        }

        /* 구매 금액에 음수가 입력되는 경우를 잘못된 입력으로 처리 */
        if (list[i].money < 0) {
            printf("오류: 물품 금액은 0 이상이어야 합니다.\n");

            free(list);
            return 1;
        }
    }

    /* 금액의 합계를 확인할 물품 이름을 입력 */
    if (scanf("%9s", check_item) != 1) {
        printf("오류: 찾을 물품 이름을 입력해야 합니다.\n");

        free(list);
        return 1;
    }

    /*
    compare 함수에서 이름 비교와 금액 합산을 한 번에 처리한다.
    같은 물품이 없으면 sum_money에는 0이 저장된다.
    */
    sum_money = compare(check_item, list, num);

    printf("출력 : %d\n", sum_money);

    /* 더 이상 구조체 배열을 사용하지 않으므로 동적 메모리 해제 */
    free(list);

    return 0;
}

/*
두 문자열을 첫 글자부터 한 글자씩 비교한다.
문자 하나라도 다르면 0, 문자열 전체가 같으면 1을 반환한다.
*/
int same_string(char str1[], char str2[])
{
    int i = 0;

    /*
    두 문자열 중 하나가 끝날 때까지 같은 위치의 문자를 비교한다.
    서로 다른 문자가 발견되면 같은 이름이 아니므로 바로 0을 반환한다.
    */
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return 0;
        }

        i++;
    }

    /*
    앞부분의 문자가 모두 같더라도 문자열 길이가 다를 수 있다.
    두 문자열이 같은 위치에서 동시에 끝나야 완전히 같은 이름이다.

    예를 들어 Apple과 Apples는 앞부분은 같지만 길이가 다르므로
    같은 문자열로 처리하지 않는다.
    */
    if (str1[i] == '\0' && str2[i] == '\0') {
        return 1;
    }

    return 0;
}

/*
check_item과 구조체 배열에 저장된 모든 물품 이름을 비교한다.
이름이 같은 물품이 여러 개 있으면 해당 금액을 모두 누적한다.
*/
int compare(char check_item[], item list[], int num)
{
    int sum_money = 0;

    for (int i = 0; i < num; i++) {
        /*
        same_string의 반환값이 1이면 두 물품 이름이 완전히 같은 경우이다.
        같은 이름을 찾을 때마다 해당 물품의 금액을 합계에 더한다.
        */
        if (same_string(check_item, list[i].name) == 1) {
            sum_money += list[i].money;
        }
    }

    /*
    일치하는 물품이 없으면 한 번도 금액이 더해지지 않으므로 0을 반환한다.
    별도의 검색 성공 여부나 check_list 배열을 만들 필요가 없다.
    */
    return sum_money;
}