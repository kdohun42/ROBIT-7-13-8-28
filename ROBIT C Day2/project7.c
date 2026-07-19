#include <stdio.h>

int string_length(char str[]); // 문자열 길이 구하는 함수 선언

int main(void)
{
    // 길이는 임의로 100으로 설정, 모두 0으로 초기화
    char inputStr[100] = {0}; 
    char subStr[100] = {0};

    int inputStr_len; // 입력 문자열 길이
    int subStr_len; // 입력 문자열2 길이
    int found = 0; //

    printf("최대 99개 문자 입력 <inputStr> : ");
    scanf("%99s", inputStr);

    printf("찾는 문자열 <subStr> : ");
    scanf("%99s", subStr);

    // 길이 구하는 함수에서 반환한 값을 길이 변수에 저장
    inputStr_len = string_length(inputStr); 
    subStr_len = string_length(subStr);

    printf("%s의 위치 : ", subStr);

    // 찾는 문자열이 입력 문자열보다 길면 절대로 포함될 수 없기 때문에 예외처리
    if (subStr_len > inputStr_len)
    {
        printf("찾을 수 없습니다.\n");
        return 0;
    }

    // i를 사용해 '찾는 문자열'을 찾기위해 시작 위치를 점점 증가시키면사 찾기
    // inputStr_len - subStr_len -> ex) 입력할 문자열의 길이가 10 찾는 문자열의 길이가 3이면 입력할 문자열의 인덱스 7까지 비교가능
    // 이후 인덱스(8부터)는 찾는 문자열의 크기보다 남아있는 배열의 크기가 작기 때문에 찾을 수 없음
    for (int i = 0; i <= inputStr_len - subStr_len; i++) 
    {
        int same = 1; // 

        for (int j = 0; j < subStr_len; j++) 
        {   
            // 입력한 문자열의 i 인덱스 부터 찾는 문자열의 인덱스만큼 반복하면서 문자열이
            // 같은지 아닌지 확인 다른면 same을 0으로 저장하고 반복문 종료
            if (inputStr[i + j] != subStr[j]) 
            {
                same = 0;
                break;
            }
        }

        if (same == 1) // smae이 0이 되지 않고 그대로 1이면 문자열을 찾은 것이다.
        {
            printf("%d ", i + 1); // i는 인덱스이기 때문에 위치는 1을 더한 값
            found = 1;
        }
    }

    if (found == 0)
    {
        printf("찾을 수 없습니다.");
    }

    printf("\n");

    return 0;
}

// 문자열 길이 구하는 함수 정의
int string_length(char str[])
{
    int length = 0;
    // '\0'이 나올 때까지 length를 증가해 종료 시 반환
    while (str[length] != '\0')
    {
        length++;
    }

    return length;
}