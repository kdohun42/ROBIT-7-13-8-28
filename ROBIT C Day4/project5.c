#include <stdio.h>

int inputarray_len(char inputarray[]);
void reverse_string(char inputarray[], int length);
char find_max_char(char inputarray[], int length, int *max_count);

int main()
{
    char inputarray[50];
    char input_char;
    char max_char;

    int index = 0;
    int length;
    int max_count;
    int overflow = 0;

    printf("입력: ");

    /*
    scanf("%c")를 반복하여 공백을 포함한 문장을 한 글자씩 입력받는다. 
    줄바꿈 문자가 입력되면 문장 입력이 끝난 것으로 판단한다.
    */
    while (1) {
        scanf("%c", &input_char);

        if (input_char == '\n') {
            break;
        }

        /*
        inputarray[50]에서 마지막 한 칸은 '\0'을 저장해야 하므로
        실제 문자는 최대 49개까지만 배열에 저장한다.
        */
        if (index < 49) {
            inputarray[index] = input_char;
            index++;
        }
        else {
            /*
            배열 범위를 넘은 문자는 저장하지 않지만
            줄바꿈이 입력될 때까지 남은 입력은 계속 읽어낸다.
            */
            overflow = 1;
        }
    }

    /* 입력된 문자 뒤에 문자열의 끝을 나타내는 '\0' 저장 */
    inputarray[index] = '\0';

    if (overflow == 1) {
        printf("오류: 문장은 최대 49자까지 입력할 수 있습니다.\n");
        return 1;
    }

    if (index == 0) {
        printf("오류: 한 글자 이상의 문장을 입력해야 합니다.\n");
        return 1;
    }

    /* 포인터를 이용하여 입력된 문자열의 길이를 계산 */
    length = inputarray_len(inputarray);

    /*
    문자열을 뒤집기 전에 가장 많이 등장한 문자를 찾는다.
    등장 횟수가 같은 문자가 여러 개라면 먼저 나온 문자를 선택한다.
    */
    max_char = find_max_char(inputarray, length, &max_count);

    /* 공백만 입력되어 최다 등장 문자를 찾지 못한 경우 */
    if (max_count == 0) {
        printf("오류: 공백을 제외한 문자를 입력해야 합니다.\n");
        return 1;
    }

    /* 양쪽 끝의 문자를 교환하여 문자열을 거꾸로 뒤집음 */
    reverse_string(inputarray, length);

    printf("출력: %s\n", inputarray);
    printf("최다등장문자: %c\n", max_char);

    return 0;
}

/*
문자열의 시작 주소부터 '\0'이 나올 때까지 포인터를 이동한다.
이동한 횟수를 이용하여 문자열의 길이를 반환한다.
*/
int inputarray_len(char inputarray[])
{
    int length = 0;
    char *pointer = inputarray;

    while (*pointer != '\0') {
        length++;
        pointer++;
    }

    return length;
}

/*
left는 문자열의 첫 번째 문자를 가리키고,
right는 문자열의 마지막 문자를 가리킨다.

두 포인터가 만날 때까지 문자를 교환하면서
left는 오른쪽, right는 왼쪽으로 이동한다.
*/
void reverse_string(char inputarray[], int length)
{
    char *left = inputarray;
    char *right = inputarray + length - 1;
    char temp;

    while (left < right) {
        temp = *left;
        *left = *right;
        *right = temp;

        left++;
        right--;
    }
}

/*
문장의 각 문자가 전체 문장에서 몇 번 등장했는지 계산한다.
공백은 최다 등장 문자 검사에서 제외한다.

max_count는 포인터이므로 함수에서 구한 최대 등장 횟수를
main 함수의 max_count 변수에 직접 저장할 수 있다.
*/
char find_max_char(char inputarray[], int length, int *max_count)
{
    char max_char = '\0';

    char *current = inputarray;
    char *compare;
    char *end = inputarray + length;

    *max_count = 0;

    while (current < end) {
        int count = 0;

        /* 공백은 최다 등장 문자 후보에서 제외 */
        if (*current == ' ') {
            current++;
            continue;
        }

        /*
        current가 가리키는 문자를 기준으로
        문장 전체를 다시 확인하여 같은 문자의 개수를 계산한다.
        */
        compare = inputarray;

        while (compare < end) {
            if (*current == *compare) {
                count++;
            }

            compare++;
        }

        /*
        현재 문자의 등장 횟수가 기존 최댓값보다 클 때만 갱신한다.
        같은 횟수라면 문장에서 먼저 나온 문자가 유지된다.
        */
        if (count > *max_count) {
            *max_count = count;
            max_char = *current;
        }

        current++;
    }

    return max_char;
}