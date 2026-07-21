#include <stdio.h>

/* 시간을 저장하는 구조체 */
typedef struct {
    int hour;
    int minute;
    int second;
} Time;

/* 날짜 안에 Time 구조체를 포함한 중첩 구조체 */
typedef struct {
    int year;
    int month;
    int day;
    Time time;
} DateTime;

int is_leap_year(int year);
int days_in_month(int year, int month);
int valid_datetime(DateTime value);
long long datetime_to_seconds(DateTime value);

int main()
{
    DateTime first;
    DateTime second;

    long long first_seconds;
    long long second_seconds;
    long long difference;

    long long result_hour;
    int result_minute;
    int result_second;

    printf("입력: \n");

    /*
    첫 번째 날짜와 시간을 입력받는다.
    6개의 정수를 모두 입력받지 못하면 잘못된 입력으로 처리한다.
    */
    if (scanf("%d %d %d %d %d %d", &first.year, &first.month, &first.day, &first.time.hour, &first.time.minute, &first.time.second) != 6) {
        printf("오류: 날짜와 시간을 정수로 입력해야 합니다.\n");
        return 1;
    }

    /*
    두 번째 날짜와 시간을 입력받는다.
    입력 형식은 연도, 월, 일, 시, 분, 초 순서이다.
    */
    if (scanf("%d %d %d %d %d %d", &second.year, &second.month, &second.day, &second.time.hour, &second.time.minute, &second.time.second) != 6) {
        printf("오류: 날짜와 시간을 정수로 입력해야 합니다.\n");
        return 1;
    }

    /*
    월별 날짜 수와 윤년을 확인하여 실제로 존재하는 날짜인지 검사한다.
    시간은 0~23시, 분과 초는 0~59 범위인지 확인한다.
    */
    if (valid_datetime(first) == 0 ||
        valid_datetime(second) == 0) {
        printf("오류: 올바르지 않은 날짜 또는 시간입니다.\n");
        return 1;
    }

    /*
    날짜와 시간을 기준 시점부터 흐른 전체 초로 변환한다.
    같은 단위로 바꾸면 날짜가 여러 달 또는 여러 해 차이나도
    단순한 뺄셈으로 정확한 차이를 구할 수 있다.
    */
    first_seconds = datetime_to_seconds(first);
    second_seconds = datetime_to_seconds(second);

    difference = second_seconds - first_seconds;

    /* 입력 순서와 관계없이 항상 양수인 시간 차이를 계산 */
    if (difference < 0) {
        difference = -difference;
    }

    /*
    전체 초를 시, 분, 초로 다시 분리한다.
    시간은 24시간이 넘어갈 수 있으므로 날짜로 바꾸지 않고 그대로 출력한다.
    */
    result_hour = difference / 3600;
    result_minute = (int)((difference % 3600) / 60);
    result_second = (int)(difference % 60);

    printf("출력: %lld시 %d분 %d초\n",
           result_hour,
           result_minute,
           result_second);

    return 0;
}

/*
연도가 윤년인지 확인한다.
4의 배수는 윤년이지만 100의 배수는 제외하고
400의 배수는 다시 윤년으로 처리한다.
*/
int is_leap_year(int year)
{
    if (year % 400 == 0) {
        return 1;
    }

    if (year % 100 == 0) {
        return 0;
    }

    if (year % 4 == 0) {
        return 1;
    }

    return 0;
}

/*
입력받은 연도와 월에 해당하는 날짜 수를 반환한다.
2월은 윤년 여부에 따라 28일 또는 29일이 된다.
*/
int days_in_month(int year, int month)
{
    int day_count[12] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    if (month == 2 && is_leap_year(year) == 1) {
        return 29;
    }

    return day_count[month - 1];
}

/*
입력된 날짜와 시간이 실제로 가능한 값인지 검사한다.
모든 조건을 만족하면 1, 잘못된 값이 있으면 0을 반환한다.
*/
int valid_datetime(DateTime value)
{
    int max_day;

    if (value.year < 1) {
        return 0;
    }

    if (value.month < 1 || value.month > 12) {
        return 0;
    }

    max_day = days_in_month(value.year, value.month);

    if (value.day < 1 || value.day > max_day) {
        return 0;
    }

    if (value.time.hour < 0 || value.time.hour > 23) {
        return 0;
    }

    if (value.time.minute < 0 || value.time.minute > 59) {
        return 0;
    }

    if (value.time.second < 0 || value.time.second > 59) {
        return 0;
    }

    return 1;
}

/*
입력된 날짜와 시간을 1년 1월 1일 0시 0분 0초부터
지나간 전체 초로 변환한다.
*/
long long datetime_to_seconds(DateTime value)
{
    long long total_days;
    long long previous_years;

    previous_years = value.year - 1;

    /*
    이전 연도들의 기본 날짜 수에 윤년으로 추가된 날짜를 더한다.
    연도를 하나씩 반복하지 않고 계산식으로 처리한다.
    */
    total_days = previous_years * 365;
    total_days += previous_years / 4;
    total_days -= previous_years / 100;
    total_days += previous_years / 400;

    /* 현재 연도에서 입력한 월 이전까지의 날짜 수를 더한다 */
    for (int month = 1; month < value.month; month++) {
        total_days += days_in_month(value.year, month);
    }

    /*
    현재 날짜는 아직 전부 지나지 않았으므로 day가 아닌 day - 1을 더한다.
    예를 들어 1월 1일은 해당 연도에서 지난 날짜가 0일이다.
    */
    total_days += value.day - 1;

    return total_days * 86400LL
           + value.time.hour * 3600LL
           + value.time.minute * 60LL
           + value.time.second;
}