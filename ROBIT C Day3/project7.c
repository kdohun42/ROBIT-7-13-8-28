#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char input[1000] = {0};
    int capacity = 10;
    int top = 0;
    int i = 0;
    int error = 0;
    int has_tag = 0;
    char **stack;

    printf("입력: ");

    /* 줄바꿈 전까지 공백을 포함하여 입력 */
    scanf("%999[^\n]", input);

    /* 아무것도 입력하지 않은 경우 */
    if (input[0] == '\0') {
        printf("오류: 입력된 내용이 없습니다.\n");
        return 1;
    }

    /* 태그 이름을 저장할 동적 스택 생성 */
    stack = (char **)malloc(sizeof(char *) * capacity);

    if (stack == NULL) {
        printf("malloc error\n");
        return 1;
    }

    /* HTML 태그 구조 검사 */
    while (input[i] != '\0' && error == 0) {
        if (input[i] == '<') {
            int close_tag = 0;
            int start;
            int length;
            int j;
            char *tagname;

            i++;

            /* 닫는 태그인지 확인 */
            if (input[i] == '/') {
                close_tag = 1;
                i++;
            }

            start = i;

            /* 태그의 끝 위치 탐색 */
            while (input[i] != '\0' && input[i] != '>') {
                if (input[i] == '<' ||
                    input[i] == '/' ||
                    input[i] == ' ' ||
                    input[i] == '\t') {
                    error = 1;
                    break;
                }

                i++;
            }

            /* 태그 형식이 잘못된 경우 */
            if (error == 1 ||
                input[i] != '>' ||
                i == start) {
                error = 1;
                break;
            }

            length = i - start;

            /* 태그 이름을 저장할 공간 할당 */
            tagname = (char *)malloc(sizeof(char) * (length + 1));

            if (tagname == NULL) {
                printf("malloc error\n");

                for (j = 0; j < top; j++) {
                    free(stack[j]);
                }

                free(stack);
                return 1;
            }

            /* 태그 이름 복사 */
            for (j = 0; j < length; j++) {
                tagname[j] = input[start + j];
            }

            tagname[length] = '\0';
            i++;

            if (close_tag == 1) {
                int same = 1;

                /* 스택이 비어 있는데 닫는 태그가 나온 경우 */
                if (top == 0) {
                    free(tagname);
                    error = 1;
                    break;
                }

                /* 스택 맨 위 태그와 닫는 태그 비교 */
                j = 0;

                while (stack[top - 1][j] != '\0' ||
                       tagname[j] != '\0') {
                    if (stack[top - 1][j] != tagname[j]) {
                        same = 0;
                        break;
                    }

                    j++;
                }

                if (same == 0) {
                    free(tagname);
                    error = 1;
                    break;
                }

                /* 정상적으로 닫힌 태그를 스택에서 제거 */
                free(stack[top - 1]);
                free(tagname);
                top--;
            }
            else {
                char **temp;

                has_tag = 1;

                /* 스택 공간이 부족하면 크기를 두 배로 확장 */
                if (top == capacity) {
                    capacity *= 2;

                    temp = (char **)realloc(
                        stack,
                        sizeof(char *) * capacity
                    );

                    if (temp == NULL) {
                        printf("malloc error\n");

                        free(tagname);

                        for (j = 0; j < top; j++) {
                            free(stack[j]);
                        }

                        free(stack);
                        return 1;
                    }

                    stack = temp;
                }

                /* 여는 태그를 스택에 저장 */
                stack[top] = tagname;
                top++;
            }
        }
        else {
            int text_start = i;
            int has_text = 0;

            /* 다음 태그 전까지 일반 문자 검사 */
            while (input[i] != '\0' && input[i] != '<') {
                if (input[i] != ' ' && input[i] != '\t') {
                    has_text = 1;
                }

                i++;
            }

            /*
                태그가 열려 있지 않은 상태에서 일반 문자가 나오면 오류
                숫자만 입력하거나 일반 문자열만 입력한 경우도 포함
            */
            if (top == 0 && has_text == 1) {
                error = 1;
            }

            /* 경고 방지를 위해 사용 */
            (void)text_start;
        }
    }

    /* 여는 태그가 하나도 없는 경우 */
    if (error == 0 && has_tag == 0) {
        error = 1;
    }

    /* 닫히지 않은 태그가 남아 있는 경우 */
    if (error == 0 && top != 0) {
        error = 1;
    }

    if (error == 1) {
        printf("오류: 잘못된 HTML 입력 또는 태그 구조입니다.\n");

        for (i = 0; i < top; i++) {
            free(stack[i]);
        }

        free(stack);
        return 1;
    }

    free(stack);

    i = 0;

    {
        int depth = 0;

        /* 올바른 HTML 구조를 들여쓰기하여 출력 */
        while (input[i] != '\0') {
            if (input[i] == '<') {
                int end = i;
                int close_tag;
                int k;

                close_tag = (input[i + 1] == '/');

                while (input[end] != '>') {
                    end++;
                }

                /* 닫는 태그는 깊이를 먼저 감소 */
                if (close_tag == 1) {
                    depth--;
                }

                for (k = 0; k < depth; k++) {
                    printf("    ");
                }

                for (k = i; k <= end; k++) {
                    putchar(input[k]);
                }

                putchar('\n');

                /* 여는 태그 뒤에는 깊이를 증가 */
                if (close_tag == 0) {
                    depth++;
                }

                i = end + 1;
            }
            else {
                int start = i;
                int end;
                int k;

                /* 다음 태그 전까지 일반 텍스트 탐색 */
                while (input[i] != '\0' && input[i] != '<') {
                    i++;
                }

                end = i;

                /* 텍스트 앞뒤 공백 제거 */
                while (start < end &&
                       (input[start] == ' ' ||
                        input[start] == '\t')) {
                    start++;
                }

                while (end > start &&
                       (input[end - 1] == ' ' ||
                        input[end - 1] == '\t')) {
                    end--;
                }

                if (start < end) {
                    for (k = 0; k < depth; k++) {
                        printf("    ");
                    }

                    for (k = start; k < end; k++) {
                        putchar(input[k]);
                    }

                    putchar('\n');
                }
            }
        }
    }

    return 0;
}