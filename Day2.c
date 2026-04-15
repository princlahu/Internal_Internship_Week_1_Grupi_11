#include <stdio.h>

int main() {
    // Deklarimi i variablave
    int age;
    char initial;
    float height;
    double average;
    short year = 2026;
    long population = 1800000;

    // Input nga përdoruesi
    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your initial: ");
    scanf(" %c", &initial); // hapësira para %c është e rëndësishme

    printf("Enter your height (in meters): ");
    scanf("%f", &height);

    printf("Enter your average grade: ");
    scanf("%lf", &average);

    // Output
    printf("\n--- User Profile ---\n");
    printf("Age: %d\n", age);
    printf("Initial: %c\n", initial);
    printf("Height: %.2f m\n", height);
    printf("Average Grade: %.2lf\n", average);
    printf("Year: %hd\n", year);       // short
    printf("Population: %ld\n", population); // long

    return 0;
}