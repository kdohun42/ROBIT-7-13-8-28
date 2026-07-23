#include <stdio.h>
#include <stdlib.h>

#define TEXT_LENGTH 30

/* 주소 정보를 저장하는 구조체 */
typedef struct {
    char country[TEXT_LENGTH];
    char province[TEXT_LENGTH];
    char city[TEXT_LENGTH];
    char district[TEXT_LENGTH];
} Address;

/* 학생 정보를 저장하는 구조체 */
typedef struct {
    int id;
    char name[TEXT_LENGTH];
    Address address;
    float score;
} Student;

/* 정렬과 검색에 사용할 기준 */
enum {FIELD_ID = 1, FIELD_NAME, FIELD_COUNTRY, FIELD_PROVINCE, FIELD_CITY, FIELD_DISTRICT, FIELD_SCORE };

/* 문자열 처리 함수 */
int compareText(const char first[], const char second[]);
void copyText(char destination[], const char source[]);

/* 입력 처리 함수 */
void clearInputBuffer(void);
int readInteger(const char *message);
float readFloat(const char *message);
void readText(const char *message, char output[]);

/* 학생 관리 함수 */
int compareStudent(const Student *first, const Student *second, int field);
int selectField(void);
void printStudents(const Student *students, int studentCount);
void sortStudents(Student *students, int studentCount, int field);
void searchStudents(const Student *students, int studentCount);
void addStudent(Student **students, int *studentCount, int *capacity);
void deleteStudent(Student *students, int *studentCount);
void saveStudents(const Student *students, int studentCount);
void loadStudents(Student **students, int *studentCount, int *capacity);

int main(void)
{
    int capacity = 4;
    int studentCount = 0;

    Student *students;
    char command[TEXT_LENGTH];

    /* 학생 배열의 초기 공간 생성 */
    students = (Student *)malloc(sizeof(Student) * capacity);

    if (students == NULL) {
        printf("메모리 할당 실패\n");
        return 1;
    }

    while (1) {
        printf("\n명령어 : stu_add / stu_del / stu_sort / stu_search / ");
        printf("stu_print / stu_save / stu_read / exit\n");

        readText("입력: ", command);

        /* 입력한 명령에 맞는 함수 실행 */
        if (compareText(command, "stu_add") == 0) {
            addStudent(&students, &studentCount, &capacity);
        }
        else if (compareText(command, "stu_del") == 0) {
            deleteStudent(students, &studentCount);
        }
        else if (compareText(command, "stu_sort") == 0) {
            int selectedField;

            selectedField = selectField();

            if (selectedField != 0) {
                sortStudents(students, studentCount, selectedField);
                printStudents(students, studentCount);
            }
        }
        else if (compareText(command, "stu_search") == 0) {
            searchStudents(students, studentCount);
        }
        else if (compareText(command, "stu_print") == 0) {
            printStudents(students, studentCount);
        }
        else if (compareText(command, "stu_save") == 0) {
            saveStudents(students, studentCount);
        }
        else if (compareText(command, "stu_read") == 0) {
            loadStudents(&students, &studentCount, &capacity);
        }
        else if (compareText(command, "exit") == 0) {
            break;
        }
        else {
            printf("ERROR : 없는 명령입니다.\n");
        }
    }

    /* 학생 배열의 메모리 해제 */
    free(students);

    return 0;
}

/* 두 문자열의 크기를 비교 */
int compareText(const char first[], const char second[])
{
    int index = 0;

    while (first[index] != '\0' && second[index] != '\0') {
        if ((unsigned char)first[index] < (unsigned char)second[index]) {
            return -1;
        }

        if ((unsigned char)first[index] > (unsigned char)second[index]) {
            return 1;
        }

        index++;
    }

    if (first[index] == '\0' && second[index] == '\0') {
        return 0;
    }

    if (first[index] == '\0') {
        return -1;
    }

    return 1;
}

/* source 문자열을 destination에 복사 */
void copyText(char destination[], const char source[])
{
    int index = 0;

    while (source[index] != '\0') {
        destination[index] = source[index];
        index++;
    }

    destination[index] = '\0';
}

/* 입력 버퍼에 남은 문자를 제거 */
void clearInputBuffer(void)
{
    int character;

    while ((character = getchar()) != '\n' && character != EOF) {
    }
}

/* 정수를 정상적으로 입력할 때까지 반복 */
int readInteger(const char *message)
{
    int number;

    while (1) {
        printf("%s", message);

        if (scanf("%d", &number) == 1) {
            clearInputBuffer();
            return number;
        }

        printf("ERROR : 숫자를 입력하세요.\n");
        clearInputBuffer();
    }
}

/* 실수를 정상적으로 입력할 때까지 반복 */
float readFloat(const char *message)
{
    float number;

    while (1) {
        printf("%s", message);

        if (scanf("%f", &number) == 1) {
            clearInputBuffer();
            return number;
        }

        printf("ERROR : 숫자를 입력하세요.\n");
        clearInputBuffer();
    }
}

/* 공백이 없는 문자열을 입력 */
void readText(const char *message, char output[])
{
    printf("%s", message);

    if (scanf("%29s", output) != 1) {
        output[0] = '\0';
    }

    clearInputBuffer();
}

/* 정렬과 검색에 사용할 항목 선택 */
int selectField(void)
{
    int selectedField;

    printf("기준 선택 ");
    printf("[1]번호 [2]이름 [3]나라 [4]도 [5]시 [6]구 [7]성적\n");

    selectedField = readInteger("번호 입력: ");

    if (selectedField < 1 || selectedField > 7) {
        printf("ERROR : 1~7 사이로 입력하세요.\n");
        return 0;
    }

    return selectedField;
}

/* 선택한 항목을 기준으로 두 학생을 비교 */
int compareStudent(const Student *first, const Student *second, int field)
{
    switch (field) {
        case FIELD_ID:
            if (first->id < second->id) {
                return -1;
            }

            if (first->id > second->id) {
                return 1;
            }

            return 0;

        case FIELD_NAME:
            return compareText(first->name, second->name);

        case FIELD_COUNTRY:
            return compareText(
                first->address.country,
                second->address.country
            );

        case FIELD_PROVINCE:
            return compareText(
                first->address.province,
                second->address.province
            );

        case FIELD_CITY:
            return compareText(
                first->address.city,
                second->address.city
            );

        case FIELD_DISTRICT:
            return compareText(
                first->address.district,
                second->address.district
            );

        case FIELD_SCORE:
            if (first->score < second->score) {
                return -1;
            }

            if (first->score > second->score) {
                return 1;
            }

            return 0;
    }

    return 0;
}

/* 등록된 모든 학생 정보를 출력 */
void printStudents(const Student *students, int studentCount)
{
    int index;

    if (studentCount == 0) {
        printf("등록된 학생이 없습니다.\n");
        return;
    }

    printf("\n%-6s %-10s %-8s %-8s %-8s %-8s %6s\n","번호", "이름", "나라", "도", "시", "구", "성적");

    for (index = 0; index < studentCount; index++) {
        printf("%-6d %-10s %-8s %-8s %-8s %-8s %6.2f\n",
               students[index].id,
               students[index].name,
               students[index].address.country,
               students[index].address.province,
               students[index].address.city,
               students[index].address.district,
               students[index].score);
    }
}

/* 선택한 항목을 기준으로 학생을 정렬 */
void sortStudents(Student *students, int studentCount, int field)
{
    int start;
    int compareIndex;
    int minimumIndex;

    for (start = 0; start < studentCount - 1; start++) {
        minimumIndex = start;

        for (compareIndex = start + 1;
             compareIndex < studentCount;
             compareIndex++) {

            if (compareStudent(
                    &students[compareIndex],
                    &students[minimumIndex],
                    field) < 0) {

                minimumIndex = compareIndex;
            }
        }

        /* 가장 작은 학생 정보를 현재 위치와 교환 */
        if (minimumIndex != start) {
            Student temporaryStudent;

            temporaryStudent = students[start];
            students[start] = students[minimumIndex];
            students[minimumIndex] = temporaryStudent;
        }
    }

    printf("정렬 완료.\n");
}

/* 선택한 조건과 일치하는 학생을 검색 */
void searchStudents(const Student *students, int studentCount)
{
    int selectedField;
    int matchCount = 0;
    int index;

    if (studentCount == 0) {
        printf("등록된 학생이 없습니다.\n");
        return;
    }

    selectedField = selectField();

    if (selectedField == 0) {
        return;
    }

    if (selectedField == FIELD_ID) {
        int targetId;

        targetId = readInteger("찾을 번호: ");

        for (index = 0; index < studentCount; index++) {
            if (students[index].id == targetId) {
                printf("%s\n", students[index].name);
                matchCount++;
            }
        }
    }
    else if (selectedField == FIELD_SCORE) {
        float targetScore;

        targetScore = readFloat("찾을 성적: ");

        for (index = 0; index < studentCount; index++) {
            float difference;

            difference = students[index].score - targetScore;

            if (difference < 0) {
                difference = -difference;
            }

            /* 실수의 작은 오차를 고려하여 비교 */
            if (difference < 0.0001f) {
                printf("%s\n", students[index].name);
                matchCount++;
            }
        }
    }
    else {
        char targetText[TEXT_LENGTH];

        readText("찾을 값: ", targetText);

        for (index = 0; index < studentCount; index++) {
            const char *selectedText;

            if (selectedField == FIELD_NAME) {
                selectedText = students[index].name;
            }
            else if (selectedField == FIELD_COUNTRY) {
                selectedText = students[index].address.country;
            }
            else if (selectedField == FIELD_PROVINCE) {
                selectedText = students[index].address.province;
            }
            else if (selectedField == FIELD_CITY) {
                selectedText = students[index].address.city;
            }
            else {
                selectedText = students[index].address.district;
            }

            if (compareText(selectedText, targetText) == 0) {
                printf("%s\n", students[index].name);
                matchCount++;
            }
        }
    }

    if (matchCount == 0) {
        printf("해당하는 학생이 없습니다.\n");
    }
    else {
        printf("총 %d명 찾음.\n", matchCount);
    }
}

/* 새로운 학생 정보를 배열에 추가 */
void addStudent(
    Student **students,
    int *studentCount,
    int *capacity
)
{
    Student *newStudent;

    /* 공간이 부족하면 배열 크기를 두 배로 확장 */
    if (*studentCount >= *capacity) {
        int newCapacity;
        Student *resizedStudents;

        if (*capacity == 0) {
            newCapacity = 4;
        }
        else {
            newCapacity = (*capacity) * 2;
        }

        resizedStudents = (Student *)realloc(
            *students,
            sizeof(Student) * newCapacity
        );

        if (resizedStudents == NULL) {
            printf("메모리 재할당 실패\n");
            return;
        }

        *students = resizedStudents;
        *capacity = newCapacity;
    }

    /* 새 학생을 저장할 배열 위치 선택 */
    newStudent = &(*students)[*studentCount];

    newStudent->id = readInteger("번호: ");
    readText("이름: ", newStudent->name);
    readText("나라: ", newStudent->address.country);
    readText("도  : ", newStudent->address.province);
    readText("시  : ", newStudent->address.city);
    readText("구  : ", newStudent->address.district);
    newStudent->score = readFloat("성적: ");

    (*studentCount)++;

    printf("추가 완료. (현재 %d명)\n", *studentCount);
}

/* 번호가 일치하는 학생 정보를 삭제 */
void deleteStudent(Student *students, int *studentCount)
{
    int matchedIndexes[100];
    int matchCount = 0;
    int targetId;
    int deleteIndex;
    int index;

    if (*studentCount == 0) {
        printf("등록된 학생이 없습니다.\n");
        return;
    }

    targetId = readInteger("삭제할 학생 번호: ");

    /* 번호가 같은 학생의 위치를 저장 */
    for (index = 0;
         index < *studentCount && matchCount < 100;
         index++) {

        if (students[index].id == targetId) {
            matchedIndexes[matchCount] = index;
            matchCount++;
        }
    }

    if (matchCount == 0) {
        printf("해당 번호의 학생이 없습니다.\n");
        return;
    }

    if (matchCount == 1) {
        deleteIndex = matchedIndexes[0];
    }
    else {
        int selectedNumber;

        printf("중복된 학생이 %d명 있습니다.\n", matchCount);

        for (index = 0; index < matchCount; index++) {
            int studentIndex;

            studentIndex = matchedIndexes[index];

            printf("[%d] %d %s %s %s %s %s %.2f\n",
                   index + 1,
                   students[studentIndex].id,
                   students[studentIndex].name,
                   students[studentIndex].address.country,
                   students[studentIndex].address.province,
                   students[studentIndex].address.city,
                   students[studentIndex].address.district,
                   students[studentIndex].score);
        }

        selectedNumber = readInteger("삭제할 항목 번호: ");

        if (selectedNumber < 1 || selectedNumber > matchCount) {
            printf("ERROR : 범위를 벗어났습니다.\n");
            return;
        }

        deleteIndex = matchedIndexes[selectedNumber - 1];
    }

    /* 삭제한 위치 뒤의 학생을 한 칸씩 이동 */
    for (index = deleteIndex;
         index < *studentCount - 1;
         index++) {

        students[index] = students[index + 1];
    }

    (*studentCount)--;

    printf("삭제 완료. (현재 %d명)\n", *studentCount);
}

/* 학생 정보를 파일에 저장 */
void saveStudents(const Student *students, int studentCount)
{
    char fileName[TEXT_LENGTH];
    FILE *file;
    int index;

    readText("저장할 파일 이름: ", fileName);

    file = fopen(fileName, "w");

    if (file == NULL) {
        printf("ERROR : 파일을 열 수 없습니다.\n");
        return;
    }

    /* 첫 번째 줄에 학생 수 저장 */
    fprintf(file, "%d\n", studentCount);

    for (index = 0; index < studentCount; index++) {
        fprintf(file, "%d %s %s %s %s %s %.2f\n",
                students[index].id,
                students[index].name,
                students[index].address.country,
                students[index].address.province,
                students[index].address.city,
                students[index].address.district,
                students[index].score);
    }

    fclose(file);

    printf("%s에 저장 완료. (%d명)\n", fileName, studentCount);
}

/* 파일에서 학생 정보를 불러오기 */
void loadStudents(
    Student **students,
    int *studentCount,
    int *capacity
)
{
    char fileName[TEXT_LENGTH];
    FILE *file;
    int loadedCount;
    int index;

    readText("불러올 파일 이름: ", fileName);

    file = fopen(fileName, "r");

    if (file == NULL) {
        printf("ERROR : 파일을 열 수 없습니다.\n");
        return;
    }

    /* 파일의 첫 번째 값에서 학생 수 확인 */
    if (fscanf(file, "%d", &loadedCount) != 1 || loadedCount < 0) {
        printf("ERROR : 파일 형식이 잘못되었습니다.\n");
        fclose(file);
        return;
    }

    /* 저장 공간이 부족하면 배열 크기 확장 */
    if (loadedCount > *capacity) {
        Student *resizedStudents;

        resizedStudents = (Student *)realloc(
            *students,
            sizeof(Student) * loadedCount
        );

        if (resizedStudents == NULL) {
            printf("메모리 재할당 실패\n");
            fclose(file);
            return;
        }

        *students = resizedStudents;
        *capacity = loadedCount;
    }

    /* 파일의 학생 정보를 배열에 저장 */
    for (index = 0; index < loadedCount; index++) {
        Student *currentStudent;

        currentStudent = &(*students)[index];

        if (fscanf(file, "%d %29s %29s %29s %29s %29s %f",
                   &currentStudent->id,
                   currentStudent->name,
                   currentStudent->address.country,
                   currentStudent->address.province,
                   currentStudent->address.city,
                   currentStudent->address.district,
                   &currentStudent->score) != 7) {

            printf("ERROR : %d번째 학생 정보가 손상되었습니다.\n",
                   index + 1);

            *studentCount = index;
            fclose(file);
            return;
        }
    }

    *studentCount = loadedCount;

    fclose(file);

    printf("%s에서 %d명 불러옴.\n", fileName, loadedCount);
}