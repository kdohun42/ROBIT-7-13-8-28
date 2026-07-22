#include <stdio.h>
#include <stdlib.h>

void print(int *row, int* col, int** arr); /*숫자 출력 함수*/
void arr_ij(int *sizeRow, int* sizeCol, int** arr); /*숫자 나선형 정렬 함수*/

int main(){
    int **arr = NULL; /* 2차원 배열*/
    int row, col, sizeRow, sizeCol;
    /*
    행과 열을 입력받는다.
    */
    printf("열의 수를 입력하세요:");
    scanf("%d", &sizeCol);
    printf("행의 수를 입력하세요:");
    scanf("%d", &sizeRow);

    if(sizeCol <= 0 || sizeRow <= 0){
        printf("행과 열은 1이상의 정수이어야 합니다.");
    }
            
    row = sizeRow;
    col = sizeCol;

    /*2차원 배열 동적할당*/
    arr = (int**)malloc(sizeof(int *) * row); 
    // 행 생성
    for(int i = 0; i < row; i++){
        arr[i] = (int*)malloc(sizeof(int) * col); // 열 생성
    }
    /* 함수 호출*/
    arr_ij(&sizeRow, &sizeCol, arr);
    print(&row, &col, arr);

    /*메모리 해제*/
    for(int i = 0; i < row; i++){
        free(arr[i]);
    }
    free(arr);
    return 0;
}

void print(int *row, int* col, int** arr){
    /*
    '*' 역참조 연산자를 사용하여 주소로 받은 값들을 실제 값으로 역참조
    */
    int row_value = *row; 
    int col_value = *col;
    /*
    숫자 출력 
    */
    printf("\n");
    for(int i = 0; i < row_value; i++){
        for(int j = 0; j < col_value; j++){
            printf("%3d", arr[i][j]);
        }
        printf("\n");
    }
}

void arr_ij(int *sizeRow, int* sizeCol, int** arr){

    /*
    '*' 역참조 연산자를 사용하여 주소로 받은 값들을 실제 값으로 역참조
    */
    int sizeRow_value = *sizeRow; // 2차원 배열 인덱스 기준 가장 아래쪽 행
    int sizeCol_value = *sizeCol; //   '' ''         ''     ''   오른쪽  열      
    int start_Row = 0; // 2차원 배열 인덱스 기준 가장 위쪽 행
    int start_Col = 0; // 2차원 배열 인덱스 기준 가장 왼쪽 열
    int number = 1; // 채워질 숫자

while(start_Col < sizeCol_value && start_Row < sizeRow_value ){ // 나선형 반복 조건, 가장 위쪽 열이 끝 열보다 크면 그 열은 숫자로 다 채워진 것, 가장 위쪽 행이 끝 행보다 크면 그 행은 숫자로 다 채워진 것
    /*
    가장 왼쪽 열 부터 가장 오른쪽 열 까지 반복
    반복 시 숫자 채움
    ex) [0][1] [0][2] [0][3] ....
    */
    for(int i = start_Col; i < sizeCol_value; i++){ 
        arr[start_Row][i] = number++;

    }
    start_Row++; // 위의 반복문이 끝났다는 것은 그 행은 숫자로 다 채워짐 더 이상 채울 공간이 없기 때문에 아래쪽으로 한 칸 내려감
    /*
    두 번째 행 부터 가장 아래쪽 행까지 반복
    반복 시 숫자 채움
    [2][sizeCol_value] [3][sizeCol_value] ....
    */
    for(int i = start_Row; i < sizeRow_value ; i++){
        arr[i][sizeCol_value-1] = number++;
    }
    sizeCol_value--; // 위의 반복문 끝나면 더 이상 내려갈 곳이 없다. 왼쪽으로 한 칸 이동

    if(start_Row < sizeRow_value){ // 아래쪽 행이 남았는지 확인
        /*
        오른쪽 열 에서 왼쪽 열까지 반복 
        반복 시 숫자 채움
        [sizeRow_value][4] [sizeRow_value][3]
        */
        for(int i = sizeCol_value-1; i >= start_Col; i--){
            arr[sizeRow_value-1][i] = number++;
        }
        sizeRow_value--; // 위의 반복문 끝나면 왼쪽으로 갈 곳이 없다. 위로 한 칸 이동
    }

    if(start_Col <= sizeCol_value){ // 왼쪽 열이 남았는지 확인
        /*
        아래 행에서 위 행까지 반복
        반복 시 숫자 채움
        [3][sizeCol_value] [2][sizeCol_value]...
        */
        for(int i = sizeRow_value-1; i >= start_Row; i--){
            arr[i][start_Col] = number++;
        }
        start_Col++; // 반복문이 끝나면 위로 올라갈 곳이 없다. 오른쪽 한 칸 이동
    }
}
}
