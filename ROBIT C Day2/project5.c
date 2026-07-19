#include <stdio.h>

int isSquareFree(int number); //제곱ㄴㄴ수인지 아닌지 확인하는 함수 선언

int main(void)
{
    int min, max;
    int count = 0; // 제곱ㄴㄴ수의 개수를 저장할 변수

    printf("min : ");
    scanf("%d", &min);

    printf("max : ");
    scanf("%d", &max);

    // min이 max보다 큰 경우 예외 처리
    if (min > max)
    {   
        printf("입력에 오류가 있습니다. 다시 입력하십시오.");
        return 0;
    }

    // 제곱ㄴㄴ수의 개수 구하기 
    for (int number = min; number <= max; number++) //min에서 max
    {
        if (isSquareFree(number)) // 함수의 반환값이 1이면 if문 하위 코드 실행 반환값이 0이면 하위 코드 실행x
        {
            count++; // 제솝ㄴㄴ수 개수 증가
        }
    }

    printf("제곱ㄴㄴ수 : %d개\n", count);

    // 제곱ㄴ수 출력
    for (int number = min; number <= max; number++)
    {
        if (isSquareFree(number)) //제곱ㄴㄴ 확인 함수가 1을 반환하면 하위 코드 실행
        {
            printf("%d ", number); 
        }
    }

    printf("\n");

    return 0;
}

// 제곱ㄴ수인지 확인하는 함수
int isSquareFree(int number)
{
    for (int i = 2; i * i <= number; i++) // 반복문의 조건에 맞는 반복 횟수 만큼 돌면 제곱ㄴㄴ수 도중에 반복문이 끝나면 제곱ㄴㄴ수
    {
        if (number % (i*i) == 0) // 제곱수로 나누어 떨어지면 제곱ㄴㄴ수가 아님.
        {
            return 0; // number가 제곱ㄴㄴ수가 아니면 반복문 종료
        }
    }

    return 1; // number가 제곱 ㄴㄴ수일 때 반환
}