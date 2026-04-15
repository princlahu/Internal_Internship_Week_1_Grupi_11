#include <stdio.h>

int main() {
    int age;
    char initial;
    float height;
    double average;

    short luckyNumber = 7;
    long population = 1800000;

    printf("Shkruaj moshen: ");
    scanf("%d", &age);

    printf("Shkruaj inicialin: ");
    scanf(" %c", &initial);

    printf("Shkruaj gjatesine: ");
    scanf("%f", &height);

    printf("Shkruaj mesataren: ");
    scanf("%lf", &average);

    printf("\n--- PROFILI ---\n");
    printf("Mosha: %d\n", age);
    printf("Iniciali: %c\n", initial);
    printf("Gjatesia: %.2f\n", height);
    printf("Mesatarja: %.2lf\n", average);
    printf("Lucky number: %d\n", luckyNumber);
    printf("Population: %ld\n", population);

    return 0;
}