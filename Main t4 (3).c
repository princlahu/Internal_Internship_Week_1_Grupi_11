#include <stdio.h>

int main() {
    int a;
    float b;

    // Pointera
    int *pa;
    float *pb;

    // Input
    printf("Shkruani nje numer integer: ");
    scanf("%d", &a);

    printf("Shkruani nje numer float: ");
    scanf("%f", &b);

    // Caktimi i adresave
    pa = &a;
    pb = &b;

    printf("\n--- Vlerat fillestare ---\n");
    printf("Vlera e a: %d\n", a);
    printf("Adresa e a: %p\n", &a);
    printf("Vlera e a permes pointerit: %d\n", *pa);

    printf("\nVlera e b: %.2f\n", b);
    printf("Adresa e b: %p\n", &b);
    printf("Vlera e b permes pointerit: %.2f\n", *pb);

    // Ruajmë vlerën e vjetër
    int oldA = a;

    // Ndryshimi përmes pointer-it
    *pa = *pa + 10;

    printf("\n--- Pas ndryshimit ---\n");
    printf("Vlera e vjeter e a: %d\n", oldA);
    printf("Vlera e re e a: %d\n", a);

    // Kontroll me if/else
    printf("\n--- Analiza ---\n");

    if (a > oldA) {
        printf("Vlera eshte rritur.\n");
    } else if (a < oldA) {
        printf("Vlera eshte zvogëluar.\n");
    } else {
        printf("Vlera ka mbetur e njejte.\n");
    }

    // Kontroll intervali
    if (a >= 0 && a <= 50) {
        printf("Vlera eshte ne intervalin 0 - 50.\n");
    } else {
        printf("Vlera eshte jashte intervalit 0 - 50.\n");
    }

    return 0;
}