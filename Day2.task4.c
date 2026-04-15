#include <stdio.h>

int main() {
    int age, workshop;
    char initial;
    double points;

    // Input
    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your initial: ");
    scanf(" %c", &initial);

    printf("Enter your points: ");
    scanf("%lf", &points);

    printf("Choose workshop (1-3): ");
    scanf("%d", &workshop);

    // Kontrolli i moshes
    if (age < 14 || age > 25) {
        printf("\nYou are not eligible to participate.\n");
    } else {
        printf("\nYou are eligible to participate.\n");
    }

    // Klasifikimi sipas pikëve
    printf("\n--- Evaluation ---\n");
    if (points < 50) {
        printf("Status: Nevojitet me shume ushtrim\n");
    }
    else if (points < 80) {
        printf("Status: Gati per vazhdim\n");
    }
    else {
        printf("Status: Gati per sfide\n");
    }

    // Switch për workshop
    printf("\n--- Workshop Selected ---\n");
    switch (workshop) {
        case 1:
            printf("Workshop 1: Programming Basics\n");
            break;
        case 2:
            printf("Workshop 2: Web Development\n");
            break;
        case 3:
            printf("Workshop 3: Cyber Security\n");
            break;
        default:
            printf("Invalid workshop option!\n");
    }

    // Përmbledhje
    printf("\n--- Summary ---\n");
    printf("Age: %d\n", age);
    printf("Initial: %c\n", initial);
    printf("Points: %.2lf\n", points);
    printf("Workshop option: %d\n", workshop);

    return 0;
}