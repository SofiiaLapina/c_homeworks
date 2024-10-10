#include <stdio.h>

int isLeapYear(int year) {
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
        return 1;  
    } else {
        return 0;  
    }
}

int DaysInMonth(int month, int year) {
    if (month == 2) { 
        if (isLeapYear(year)) {
            return 29; 
        } else {
            return 28;
        }
    }

    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        return 31;
    }
    
    return 30;  
}

int FirstD(int month, int year) {
    if (month < 3) {  
        month += 12;
        year--;
    }
    int LastTwo = year % 100; 
    int FirstTwo = year / 100; 
    int day = (1 + (13 * (month + 1)) / 5 + LastTwo + (LastTwo / 4) + (FirstTwo / 4) - 2 * FirstTwo) % 7;
    return (day + 5) % 7;  
}

void Calendar(int month, int year) {
    int StartDay = FirstD(month, year);  
    int days = DaysInMonth(month, year);  

    printf(" M  T  W  T  F  S  S\n"); 

   
    for (int i = 0; i < StartDay; i++) {
        printf("   ");
    }


    for (int day = 1; day <= days; day++) {
        printf("%2d ", day);
        if ((day + StartDay) % 7 == 0) {  
            printf("\n");
        }
    }
    printf("\n");
}

int main() {
    int month, year;

    printf("Month (1-12): ");
    scanf("%d", &month);
    if (month < 1 || month > 12) {
        printf("Invalid month!\n");
        return 1;
    }

    printf("Year: ");
    scanf("%d", &year);
    if (year < 1) {
        printf("Invalid year!\n");
        return 1;
    }

    Calendar(month, year);
    return 0;
}
