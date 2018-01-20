#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main() {

    int total_days = day_of_year(1992, 2, 6);
    printf("There are %i days in %i/%i/%i\n", total_days, 6, 2, 1992);

    int month, day;
    month_day(1992, total_days, &month, &day);
    printf("%i months in %i days in %i\n", month, total_days, 1992);

    return 0;
}

int day_of_year(int year, int month, int day) {

	if (year < 1752 || month < 1 || month > 12 || day < 1) {
		return -1;
    }

    int i, leap;

    leap = year % 4 == 0 && (year / 100 != 0 || year % 400  == 0);

    if (day > daytab[leap][month]) {
		return -1;
    }
    for (i = 1; i < month; i++) {
        day += daytab[leap][i];
    }
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday) {
    if (year < 1752 || yearday < 1) {
        return;
    }
    int i, leap;

    leap = year % 4 == 0 && (year / 100 != 0 || year % 400  == 0);
    if ((leap && yearday > 366) || (!leap && yearday > 365)) {
        return;
    }
    for (i = 1; yearday > daytab[leap][i]; i++) {
        yearday -= daytab[leap][i];
    }
    *pmonth = i;
    *pday = yearday;
}
