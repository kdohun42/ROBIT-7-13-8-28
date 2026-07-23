#include <stdio.h>
#include <stdlib.h>

/*노드 구조체*/
typedef struct Node{
    int data;
    struct Node* next;
} Node;

/*스택 구조체*/
typedef struct Stack{
    Node* top;
    int size;
} Stack;

Stack* createStack(void) {
    Stack* stack = (Stack*)malloc(sizeof(Stack)); /*동적 할당을 사용해 스택 생성*/
    (*stack).top = NULL;
    stack->size = 0; /*스택 사이즈를 0으로 초기화*/
    return stack; /*스택 반환*/
}

/* 명령어 함수 */
/* 
push 함수, 노드 생성후 입력 받은 데이터 저장, 노드의 next에 stack의 top 주소를 저장
입력 받은 숫자를 계속해서 top으로 갱신
*/
void push ( Stack* stack, int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> next = stack -> top;
    stack->top = newNode;
    stack->size++; /*스택 구조체에 숫자를 추가 시 사이즈도 같이 증가*/
}
/*pop 함수*/
int pop( Stack* stack){
    /*top이 비었으면 stack가 빈 것으로 처리*/
    if(stack->top == NULL){
        printf("stack이 비어있습니다.\n");
        return -1;
    }
    Node* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    stack->size--; /*pop시 사이즈 감소*/
    return data;
}

int top(Stack* stack){
    if (stack->top == NULL){
        printf("stack이 비어있습니다.\n");
        return -1;
    }
    return stack->top->data;
}
/*출력 함수 계속해서 next에 저장된 주소 변경하면서 출력*/
int printStack(Stack* stack){
    Node* current = stack->top;

    if (stack->top == NULL){
        printf("stack이 비어있습니다.\n");
        return -1;
    }

    while( current != NULL){
        printf("%d", current->data);
        current = current->next;
    }

    return 0;
}
/*top이 NULL이면 숫자가 없는 것*/
int isEmpty(Stack* stack){
    if(stack->top == NULL){
        printf("true\n");
        return 0;
    }
    printf("false");
}

/*strcmp 구현, 명령어 확인용*/
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
    Stack* stack = createStack();
while(1){
    

    int command_number = 0;

    char str1[20] = "push";
    char str2[20] = "pop";
    char str3[20] = "size";
    char str4[20] = "top";
    char str5[20] = "isEmpty";
    char str6[20] = "printStack";

    char command[20];
    printf("명령어 입력: ");
    scanf("\n%[^\n]", command);

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
    else{
        printf("해당하는 명령어가 없습니다.");
        return 0;
    }

    int data_number;

    if(command_number == 1){
        printf("데이터를 입력하시오: ");
        scanf("%d", &data_number);
        push(stack, data_number);
    }
    else if(command_number == 2){
        printf("pop된 값: %d\n", pop(stack));
    }
    else if(command_number == 3){
        printf("stack 크기: %d\n",stack->size);
    }
    else if(command_number == 4){
        printf("top 값: %d\n", top(stack));
    }
    else if(command_number == 5){
        isEmpty(stack);
    }
    else if(command_number == 6){
        printStack(stack);
    }
    }
}