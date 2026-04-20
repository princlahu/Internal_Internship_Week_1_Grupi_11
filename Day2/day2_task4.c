#include <stdio.h>

int main() {
    int age, option;
    char initial;
    double points;

    // Input
    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your initial: ");
    scanf(" %c", &initial);

    printf("Enter your points: ");
    scanf("%lf", &points);

    printf("Choose workshop (1, 2 or 3): ");
    scanf("%d", &option);

    // Kontrolli i moshes
    if (age < 15 || age > 25) {
        printf("\nYou are NOT eligible for this workshop.\n");
    } else {
        printf("\nYou are eligible for this workshop.\n");
    }

    // Klasifikimi sipas pikëve
    printf("\n--- Evaluation ---\n");
    if (points < 50) {
        printf("Needs more practice\n");
    } else if (points < 80) {
        printf("Ready to continue\n");
    } else {
        printf("Ready for challenge\n");
    }

    // Zgjedhja me switch
    printf("\n--- Workshop Selected ---\n");
    switch(option) {
        case 1:
            printf("Programming Basics\n");
            break;
        case 2:
            printf("Web Development\n");
            break;
        case 3:
            printf("Data Science\n");
            break;
        default:
            printf("Invalid workshop option\n");
    }

    // Përmbledhja finale
    printf("\n--- Summary ---\n");
    printf("Age: %d\n", age);
    printf("Initial: %c\n", initial);
    printf("Points: %.2lf\n", points);
    printf("Workshop Option: %d\n", option);

    return 0;
}