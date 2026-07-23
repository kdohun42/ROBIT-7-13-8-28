#include <stdio.h>
#include <stdlib.h>

/* 문자와 다음 노드 주소를 저장하는 구조체 */
typedef struct Node {
    char value;
    struct Node *next;
} Node;

/* 스택의 최상단과 데이터 개수를 관리 */
typedef struct {
    Node *top;
    int count;
} Stack;

/* 큐의 시작과 끝, 데이터 개수를 관리 */
typedef struct {
    Node *front;
    Node *rear;
    int count;
} Queue;

/* 스택과 큐에서 사용할 함수 선언 */
void pushStack(Stack *stack, char value);
char popStack(Stack *stack);

void enqueueQueue(Queue *queue, char value);
char dequeueQueue(Queue *queue);

int main(void)
{
    Stack stack;
    Queue queue;
    char inputChar;

    /* 빈 스택으로 초기화 */
    stack.top = NULL;
    stack.count = 0;

    /* 빈 큐로 초기화 */
    queue.front = NULL;
    queue.rear = NULL;
    queue.count = 0;

    printf("입력: ");

    /* 문자를 하나씩 입력받아 스택과 큐에 저장 */
    while (scanf("%c", &inputChar) == 1) {
        if (inputChar == '\n') {
            break;
        }

        /* 공백은 회문 검사에서 제외 */
        if (inputChar != ' ') {
            pushStack(&stack, inputChar);
            enqueueQueue(&queue, inputChar);
        }
    }

    /* 앞에서 꺼낸 문자와 뒤에서 꺼낸 문자를 비교 */
    while (queue.front != NULL && stack.top != NULL) {
        if (dequeueQueue(&queue) != popStack(&stack)) {
            printf("회문이 아닙니다.\n");
            return 0;
        }
    }

    printf("회문입니다.\n");

    return 0;
}

/* 새 노드를 스택의 최상단에 추가 */
void pushStack(Stack *stack, char value)
{
    Node *newNode;

    newNode = (Node *)malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("메모리 할당에 실패했습니다.\n");
        return;
    }

    newNode->value = value;
    newNode->next = stack->top;

    stack->top = newNode;
    stack->count++;
}

/* 스택의 최상단 문자를 삭제하고 반환 */
char popStack(Stack *stack)
{
    Node *deleteNode;
    char value;

    deleteNode = stack->top;
    value = deleteNode->value;

    stack->top = deleteNode->next;
    free(deleteNode);

    stack->count--;

    return value;
}

/* 새 노드를 큐의 마지막에 추가 */
void enqueueQueue(Queue *queue, char value)
{
    Node *newNode;

    newNode = (Node *)malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("메모리 할당에 실패했습니다.\n");
        return;
    }

    newNode->value = value;
    newNode->next = NULL;

    /* 첫 노드는 front와 rear가 모두 가리킴 */
    if (queue->front == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    queue->count++;
}

/* 큐의 맨 앞 문자를 삭제하고 반환 */
char dequeueQueue(Queue *queue)
{
    Node *deleteNode;
    char value;

    deleteNode = queue->front;
    value = deleteNode->value;

    queue->front = deleteNode->next;
    free(deleteNode);

    queue->count--;

    /* 마지막 노드가 삭제되면 rear도 초기화 */
    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    return value;
}