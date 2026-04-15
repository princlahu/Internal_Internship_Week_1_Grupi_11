#include <stdio.h>

int main() {
    int age, workshopOption;
    char initial;
    double points;

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your initial: ");
    scanf(" %c", &initial);

    printf("Enter your preliminary points: ");
    scanf("%lf", &points);

    printf("Choose workshop (1, 2 or 3): ");
    scanf("%d", &workshopOption);

    printf("\n--- Workshop Registration Summary ---\n");
    printf("Age: %d\n", age);
    printf("Initial: %c\n", initial);
    printf("Preliminary Points: %.2lf\n", points);

    if (age >= 15 && age <= 25) {
        printf("Participation: Allowed\n");
    } else {
        printf("Participation: Not allowed\n");
    }

    if (points < 50) {
        printf("Level: Needs more practice\n");
    } else if (points < 80) {
        printf("Level: Ready to continue\n");
    } else {
        printf("Level: Ready for challenge\n");
    }

    switch (workshopOption) {
        case 1:
            printf("Workshop: Programming Basics\n");
            break;
        case 2:
            printf("Workshop: Web Development\n");
            break;
        case 3:
            printf("Workshop: Database Fundamentals\n");
            break;
        default:
            printf("Workshop: Invalid option\n");
    }

    return 0;
}