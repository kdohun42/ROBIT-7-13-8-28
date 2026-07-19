#include <stdio.h>
// 입력할 문자열, 모든 명령어가 문자열 크기 10이하이기 때문에 크기는 10으로 설정
char command[10] = {0};
// 입력할 명령어가 무엇인지 확인하기 위한 문자열
char add_command[10] = "add";
char remove_command[10] = "remove";
char check_command[10] = "check";
char toggle_command[10] = "toggle";
char all_command[10] = "all";
char empty_command[10] = "empty";
// 크기가 21인 이유는 인덱스 값에 해당하는 값이 존재하는지 아닌지 판별하기 위해서 (인덱스 0은 사용하지 않음)
int exists[21] = {0};  // 1~20의 존재 여부 확인 배열, 숫자가 존재하면 1을 저장 존재하지 않으면 0을 저장
int list[20] = {0};    // 실제로 값을 넣을 배열
int list_count = 0; // 값을 순차적으로 넣기 위해 만든 변수

int compare(const char command1[], const char command2[]); // 입력한 명령어가 무엇인지 확인하는 함수 선언
void add_number(int number); // add 함수 선언
void remove_number(int number); // remove 함수 선언
void list_print(void); // 집합 출력 함수 선언

int main()
{
    int number;

    printf("연산을 선택하세요. (1 <= x <= 20)");
    printf("\nadd X");
    printf("\nremove X");
    printf("\ncheck X");
    printf("\ntoggle X");
    printf("\nall 0");
    printf("\nempty 0\n");

    while (1) 
    {
        printf("\ninput : ");
        scanf("%s %d", &command, &number);

        if (compare(command, add_command)) // 함수에서 반환되는 값이 0이면 하위 코드 실행x, 1이면 하위 코드 실행
        {
            if (number < 1 || number > 20) // 숫자 입력은 1 <= X <= 20이어야 하기 때문에 범위를 벗어나는 숫자 입력시 예외처리
            {
                printf("숫자는 1부터 20까지만 입력할 수 있습니다.\n");
                continue;
            }

            add_number(number); 
            list_print();
        }
        else if (compare(command, remove_command))
        {   
            if (number < 1 || number > 20) // 숫자 예외처리
            {
                printf("숫자는 1부터 20까지만 입력할 수 있습니다.\n");
                continue;
            }

            remove_number(number); // 숫자 제거 함수 호출
            list_print();
        }
        else if (compare(command, check_command))
        {
            if (number < 1 || number > 20) // 숫자 예외처리
            {
                printf("숫자는 1부터 20까지만 입력할 수 있습니다.\n");
                continue;
            }

            printf("%d\n", exists[number]); // 해당 숫자가 있으면 1을 출력 없으면 0을 출력
        }
        else if (compare(command, toggle_command))
        {
            if (number < 1 || number > 20) // 숫자 예외처리
            {
                printf("숫자는 1부터 20까지만 입력할 수 있습니다.\n");
                continue;
            }

            if (exists[number] == 1) // 해당 숫자가 있으면 숫자 제거
            {
                remove_number(number);
            }
            else // 해당 숫자가 없으면 숫자 추가
            {
                add_number(number);
            }

            list_print();
        }
        else if (compare(command, all_command))
        {
            if (number != 0) // 0이 아닐 시 예외처리
            {
                printf("all 명령어는 all 0으로 입력해야 합니다.\n");
                continue;
            }

            list_count = 0;

            for (int i = 1; i <= 20; i++)
            {
                exists[i] = 1; // 모든 수가 존재하기 때문에 모두 1로 저장
                list[list_count] = i; //i가 1부터 20까지 반복하기 때문에 i의 값을 저장
                list_count++; // 집합의 크기도 20이 되기 때문에 반복 횟수 만큼 증가
            }

            list_print();
        }
        else if (compare(command, empty_command))
        {
            if (number != 0) // 0이 아닐 시 예외처리
            {
                printf("empty 명령어는 empty 0으로 입력해야 합니다.\n");
                continue;
            }

            list_count = 0;

            for (int i = 1; i <= 20; i++)
            {
                exists[i] = 0; // 모든 수가 존재하지 않기 때문에 1인덱스부터 20인덱스까지 0으로 저장
            }

            list_print();
        }
        else
        {  // 잘못된 명령어일 시 예외 처리
            printf("명령어는 add, remove, check, toggle, all, empty 중 하나를 선택해주세요.\n");
            break;
        }
    }

    return 0;
}
// 입력한 문자열이 무엇인지 확인하는 함수 정의
int compare(const char command1[], const char command2[])// 입력한 문자열과 비교할 문자열을 받는다.
{
    int i = 0;
    // 반복문을 사용해 \0 문자가 나올 때까지 맞는지 확인. 맞다면 계속해서 반복문 실행 후 1 반환, 맞지 않다면 0 반환
    while (command1[i] != '\0' || command2[i] != '\0') 
    {
        if (command1[i] != command2[i])
        {
            return 0;
        }

        i++; // i를 계속해서 증가시키면서 모든 문자열 확인
    }

    return 1;
}
// 집합에 숫자 추가 함수 정의
void add_number(int number)
{
    // 이미 존재하면 아무것도 하지 않음
    if (exists[number] == 1) 
    {
        return;
    }

    exists[number] = 1; // 값이 존재하지 않으면 추가하려는 숫자(number) 인덱스(에 해당하는 exists 배열에 1을 저장. 1은 값이 존재한다는 것을 의미
    list[list_count] = number; // list_count = 0은 list에 아무것도 명령하지 않았을 때를 말한다.
    list_count++;
}
// 집합에 숫자 제거 함수 정의
void remove_number(int number)
{
    int remove_index = -1;

    // 집합에 없으면 아무것도 하지 않음
    if (exists[number] == 0)
    {
        return;
    }

    // list_count 만큼 반복하여 삭제할 숫자의 위치를 찾음 
    for (int i = 0; i < list_count; i++)
    {
        if (list[i] == number) // 숫자 있다면 
        {
            remove_index = i;
            break;
        }
    }

    // 삭제된 자리를 뒤의 숫자들로 채움
    for (int i = remove_index; i < list_count - 1; i++)
    {
        list[i] = list[i + 1];
    }

    list_count--; //숫자를 제거하면서 집합의 크기가 줄어들었기 때문에 감소
    exists[number] = 0; // 숫자가 존재하지 않기 때문에 해당하는 인덱스에 0을 저장
}
// 집합 출력 함수
void list_print(void)
{
    printf("집합 : { ");

    for (int i = 0; i < list_count; i++) // 집합의 크기만큼 반복하면서 집합을 출력
    {
        printf("%d, ", list[i]);
    }

    printf(" }\n");
}