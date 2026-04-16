#include <stdio.h>

int main() {
    int a;
    double b;

    int *pA;
    double *pB;

    // Input
    printf("Shkruaj nje numer int: ");
    scanf("%d", &a);

    printf("Shkruaj nje numer double: ");
    scanf("%lf", &b);

    // Lidh pointer-at me adresat
    pA = &a;
    pB = &b;

    // Shfaq vlerat dhe adresat
    printf("\n--- PARA NDRYSHIMIT ---\n");
    printf("a = %d | Adresa: %p | Pointer value: %d\n", a, &a, *pA);
    printf("b = %.2lf | Adresa: %p | Pointer value: %.2lf\n", b, &b, *pB);

    // Ruaj vlerat e vjetra
    int oldA = a;

    // Ndryshim permes pointer-it
    *pA = *pA + 10;   // rrit vleren e a me 10
    *pB = *pB * 2;    // dyfishon vleren e b

    // Pas ndryshimit
    printf("\n--- PAS NDRYSHIMIT ---\n");
    printf("a = %d\n", a);
    printf("b = %.2lf\n", b);

    // Kontroll me if/else
    printf("\n--- ANALIZA ---\n");

    if (a > oldA) {
        printf("Vlera e a eshte rritur.\n");
    } else if (a < oldA) {
        printf("Vlera e a eshte zvogeluar.\n");
    } else {
        printf("Vlera e a ka mbetur e njejte.\n");
    }

    // Interval per b
    if (b >= 0 && b <= 100) {
        printf("b eshte brenda intervalit 0-100.\n");
    } else {
        printf("b eshte jashte intervalit 0-100.\n");
    }

    return 0;
}