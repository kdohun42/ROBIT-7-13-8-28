#include <stdio.h>

int char_compare(char arr[8]); // 입력한 음을 비교하기 위한 함수 선언

int main(){

    char arr[8];

    // 반복문을 사용해서 입력받기, 문자 하나씩 비교해야하기 때문에 for문을 사용해 하나씩 입력받기
    printf("음 입력\n");
    for( int i = 0; i < 8; i++){
        scanf("%c", &arr[i]);
    }

    printf("\n");

    // switch문을 사용해 함수에서 반환 값에 따른 코드 실행
    switch (char_compare(arr))
    {
    case 1:
        printf("결과 : ascending");
        break;
    case 2:
        printf("결과 : descending");
        break;
    default:
        printf("결과 : mixed");
        break;
    }

    return 0;
}

int char_compare(char arr[8]){
    // 입력한 음과 비교할 배열들
    char compare_arr1[8] = "cdefgabC";
    char compare_arr2[8] = "Cbagfedc";
    // 입력한 음과 위의 배열들을 비교할 떄 사용할 변수들, 같은 음일시 1씩 증가, 반환 값을 판별할 때도 사용
    int count1 = 0, count2 = 0;
    
    // for문을 사용해 8번 반복하여 하나씩 비교
    for( int i = 0; i < 8; i++){

        if(compare_arr1[i] == arr[i]){ //하나씩 비교했을 때 맞다면 count1 -> 1씩 증가
            count1 += 1;
        }
        else if(compare_arr2[i] == arr[i]){ //하나씩 비교했을 때 맞다면 count2 -> 1씩 증가
            count2 += 1;
        }
        else{
            break;
        }
    }

    if ( count1 == 8){ //count1이 8이면 첫 번쨰 배열과 입력한 배열이 일치하다는 것 
        return 1;
    }

    else if( count2 == 8){ //count2가 8이면 두 번쨰 배열과 입력한 배열이 일치하다는 것
        return 2;
    }
    
    else{
        return 3;
    }
}