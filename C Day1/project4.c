//과제-4
#include <stdio.h>

int main(){
    printf("Input Arithmetic Operation\n");
    printf("ex)      3.4 * 8.5\n");
    printf("         2.9 - 5.4\n");
    printf("         3.9 * 8.0\n");
    printf("         3.9 ^ 8");
    printf("\n\ninput :");
    
    float num1, num2, result;
    char a;
    scanf("%f %c %f", &num1, &a, &num2);
    if( a == '+' ){
        result = num1 + num2;
    }
    else if( a == '-'){
        result = num1 - num2;
    }
    else if( a == '*'){
        result = num1 * num2;
    }
    else if( a == '/'){
        result = num1 / num2;
    }
    else if( a == '^'){
        float exp = 1;
        for(int i = 1; i < (int)num2; i++){
            exp = exp * num1;
            result = num1 * exp;
        }
    }
    else{ 
        printf("사칙연산과 거듭제곱만 가능합니다.\n");
    }
    printf("%.2f %c %.2f = %.2f\n", num1, a, num2, result);
    printf("계속하려면 아무 키나 누르십시오. . .");
    return 0;
}