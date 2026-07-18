#include <stdio.h>

int char_compare(char arr[9]);

int main(){

    char arr[8];

    printf("음 입력\n");
    for( int i = 0; i < 8; i++){
        scanf("%c", &arr[i]);
    }

    printf("\n");

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
    
    char compare_arr1[8] = "cdefgabC";
    char compare_arr2[8] = "Cbagfedc";
    int count1 = 0, count2 = 0;

    for( int i = 0; i < 8; i++){

        if(compare_arr1[i] == arr[i]){
            count1 += 1;
        }
        else if(compare_arr2[i] == arr[i]){
            count2 += 1;
        }
        else{
            break;
        }
    }

    if ( count1 == 8){
        return 1;
    }

    else if( count2 == 8){
        return 2;
    }
    
    else{
        return 3;
    }
}