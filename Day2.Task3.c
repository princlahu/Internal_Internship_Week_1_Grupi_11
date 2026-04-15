#include <stdio.h>

int main() {
    int day;

    // Input nga përdoruesi
    printf("Enter a number (1-7): ");
    scanf("%d", &day);

    // Switch për ditët e javës
    switch(day) {
        case 1:
            printf("Monday - Dite pune\n");
            break;
        case 2:
            printf("Tuesday - Dite pune\n");
            break;
        case 3:
            printf("Wednesday - Dite pune\n");
            break;
        case 4:
            printf("Thursday - Dite pune\n");
            break;
        case 5:
            printf("Friday - Dite pune\n");
            break;
        case 6:
            printf("Saturday - Fundjave\n");
            break;
        case 7:
            printf("Sunday - Fundjave\n");
            break;
        default:
            printf("Invalid input! Please enter a number from 1 to 7.\n");
    }

    return 0;
}