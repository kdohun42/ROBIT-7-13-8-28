#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

typedef struct Queue{
    Node* front; /*Queue의 맨 앞*/
    Node* rear; /*Queue의 맨 뒤*/
    int size;
} Queue;

Queue* createQueue(void) {
    Queue* queue = (Queue*)malloc(sizeof(Queue)); // Queue 생성
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

/* 명령어 함수 */
int isEmpty(Queue* queue){
    if(queue->front == NULL){
        //printf("true\n");
        return 0;
    }
    else{
        //printf("false");
        return 1;
    }
}

void Enqueue ( Queue* queue, int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> next = NULL;
    /*
    첫 번쨰 입력에서는 첫 번쨰 노드가 front, rear로 설정 및 큐 사이즈 증가
    */
    if(isEmpty(queue) == 0){
        queue->front = newNode;
        queue->rear = newNode;
        queue->size++;
    }
    /*그게 아니라면 rear에 노드 저장 및 next에 노드 주소 저장 똑같이 큐 사이즈 증가*/
    else{
        queue->rear->next = newNode;
        queue->rear = newNode;
        queue->size++;
    }
}
/*비어있을 시 예외처리 및 노드 삭제 후 사이즈 감소*/
int Dequeue(Queue* queue){
    if(queue->front == NULL){
        printf("Queue가 비어있습니다.\n");
        return 0;
    }
    Node* temp = queue->front;
    int data = temp->data;
    queue->front = temp->next;
    free(temp);
    queue->size--;
    return data;
}
/*front 값 반환*/
int front(Queue* queue){
    if (queue->front == NULL){
        printf("queue이 비어있습니다.\n");
        return -1;
    }
    return queue->front->data;
}
/*rear 값 반환*/
int rear(Queue* queue){
    return queue->rear->data;
}
/* 출력 함수*/
int printQueue(Queue* queue){
    Node* current = queue->front;

    if (queue->front == NULL){
        printf("Queue이 비어있습니다.\n");
        return -1;
    }

    while( current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }

    return 0;
}
/*strcmp구현 명령어 구현*/
int string_compare(char command[], char arr[]){
    int i = 0;
    while(command[i] != '\0' || arr[i] != '\0'){
        if(command[i] != arr[i]){
            return 2;
        }
        i++;
        }
        if(command[i] == '\0' && arr[i] == '\0'){
            return 1;
        }
        return 0;
}

int main(){
    Queue* queue = createQueue();
while(1){

    int command_number = 0; /* 명령어 숫자 초기화*/

    char str1[20] = "Enqueue"; /*1*/
    char str2[20] = "Dequeue"; /*2*/
    char str3[20] = "size"; /*3*/
    char str4[20] = "front"; /*4*/
    char str5[20] = "rear"; /*5*/
    char str6[20] = "isEmpty"; /*6*/
    char str7[20] = "printQueue"; /*7*/

    char command[20];
    printf("명령어 입력: ");
    scanf("\n%[^\n]", command);
    /*
    strcmp 구현 함수로 반환값을 받고 그 반환 값이 1이면 즉 문자열 비교가 모두 참이면
    command_number에 해당하는 숫자 저장
    */
    if(string_compare(command, str1) == 1){
        command_number = 1;
    }
    else if(string_compare(command, str2) == 1){
        command_number = 2;
    }
    else if(string_compare(command, str3) == 1){
        command_number = 3;
    }
    else if(string_compare(command, str4) == 1){
        command_number = 4;
    }
    else if(string_compare(command, str5) == 1){
        command_number = 5;
    }
    else if(string_compare(command, str6) == 1){
        command_number = 6;
    }
    else if(string_compare(command, str7) == 1){
        command_number = 7;
    }
    else{
        printf("해당하는 명령어가 없습니다.");
        return 0;
    }

    int data_number;

    if(command_number == 1){
        printf("데이터를 입력하시오: ");
        scanf("%d", &data_number);
        Enqueue(queue, data_number);
    }
    else if(command_number == 2){
        printf("Dequeue된 값: %d\n", Dequeue(queue));
    }
    else if(command_number == 3){
        printf("Queue 크기: %d\n",queue->size);
    }
    else if(command_number == 4){
        printf("front 값: %d\n", front(queue));
    }
    else if(command_number == 5){
        printf("rear 값: %d\n", rear(queue));
    }
    else if(command_number == 6){
        if(isEmpty(queue) == 0){
            printf("true\n");
        }
        else{
            printf("false\n");
        }
        
    }
    else if(command_number == 7){
        printf("Queue : ");
        printQueue(queue);
        printf("\n");
    }
    }
}