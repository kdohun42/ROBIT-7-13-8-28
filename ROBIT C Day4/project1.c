#include <stdio.h>

/* 학생의 학년, 성적, 이름을 하나의 자료형으로 관리 */
typedef struct {
    int grade;
    double score;
    char name[10];
} st;

/* 문자열 비교를 위한 사용자 정의 함수 */
int name_compare(char name1[], char name2[]);

int main()
{
    st list[5];

    printf("입력:\n");

    /*
       이름 배열의 크기가 10이므로 %9s를 사용한다.
       최대 9글자를 입력받고 마지막 공간에는 '\0'이 저장된다.
     */
    for (int i = 0; i < 5; i++) {
        scanf("%d %lf %9s",
              &list[i].grade,
              &list[i].score,
              list[i].name);
    }

    /*
       버블 정렬
       서로 붙어 있는 두 학생을 비교하고
       정렬 기준에 맞지 않으면 위치를 교환한다
     */
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4 - i; j++) {
            /*
               정렬 조건 중 하나라도 만족하면 1로 변경한다.
               실제 위치 교환 코드를 한 번만 작성하기 위해 사용한다
             */
            int change = 0;

            /* 첫 번째 기준: 학년 오름차순 */
            if (list[j].grade > list[j + 1].grade) {
                change = 1;
            }

            /* 두 번째 기준: 학년이 같으면 성적 오름차순 */
            else if (list[j].grade == list[j + 1].grade &&
                     list[j].score > list[j + 1].score) {
                change = 1;
            }

            /*
               세 번째 기준: 학년과 성적이 같으면 이름 오름차순
               반환값이 양수이면 앞 학생의 이름이 사전 순으로 뒤에 있다
             */
            else if (list[j].grade == list[j + 1].grade &&
                     list[j].score == list[j + 1].score &&
                     name_compare(list[j].name,
                                  list[j + 1].name) > 0) {
                change = 1;
            }

            /*
               구조체 전체를 교환하므로
               학년, 성적, 이름이 서로 섞이지 않는다
             */
            if (change == 1) {
                st temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }

    printf("\n출력:\n");

    for (int i = 0; i < 5; i++) {
        printf("%d %.1f %s\n",
               list[i].grade,
               list[i].score,
               list[i].name);
    }

    return 0;
}

/*
   두 이름을 앞 글자부터 비교한다.
  
   반환값
    1 : name1이 사전 순으로 뒤
   -1 : name1이 사전 순으로 앞
    0 : 두 이름이 같음
 */
int name_compare(char name1[], char name2[])
{
    int i = 0;

    /*
       같은 위치의 문자를 차례대로 비교한다.
       서로 다른 문자가 나오면 그 문자의 코드값으로 순서를 결정한다.
     */
    while (name1[i] != '\0' && name2[i] != '\0') {
        if (name1[i] > name2[i]) {
            return 1;
        }

        if (name1[i] < name2[i]) {
            return -1;
        }

        i++;
    }

    /* 두 문자열이 동시에 끝났으면 완전히 같은 이름 */
    if (name1[i] == '\0' && name2[i] == '\0') {
        return 0;
    }

    /*
       앞부분이 같다면 먼저 끝난 짧은 문자열이 앞에 온다.
       예: "kim"은 "kims"보다 앞에 온다.
     */
    if (name1[i] == '\0') {
        return -1;
    }

    return 1;
}