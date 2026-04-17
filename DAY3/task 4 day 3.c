#include <stdio.h>

int main() {
    int a;
    float b;

    // pointers
    int *pA;
    float *pB;

    // input
    printf("Shkruaj nje vlere int: ");
    scanf("%d", &a);

    printf("Shkruaj nje vlere float: ");
    scanf("%f", &b);

    // lidhja me pointer
    pA = &a;
    pB = &b;

    // para ndryshimit
    printf("\n--- PARA NDRYSHIMIT ---\n");
    printf("a = %d\n", a);
    printf("Adresa e a = %p\n", &a);
    printf("Vlera e a permes pointer = %d\n", *pA);

    printf("\nb = %.2f\n", b);
    printf("Adresa e b = %p\n", &b);
    printf("Vlera e b permes pointer = %.2f\n", *pB);

    // ruaj vleren e vjeter
    int oldA = a;

    // ndryshim permes pointer
    *pA = *pA + 5;

    printf("\n--- PAS NDRYSHIMIT ---\n");
    printf("a = %d\n", a);
    printf("Vlera e re permes pointer = %d\n", *pA);

    // kontroll me if/else
    printf("\n--- KONTROLLI ---\n");

    if (a > oldA) {
        printf("Vlera eshte rritur\n");
    } else if (a < oldA) {
        printf("Vlera eshte zvogeluar\n");
    } else {
        printf("Vlera ka mbetur e njejte\n");
    }

    // interval kontroll
    if (a >= 0 && a <= 10) {
        printf("Vlera eshte ne intervalin [0,10]\n");
    } else {
        printf("Vlera eshte jashte intervalit [0,10]\n");
    }

    return 0;
}