#include <stdio.h>

int main() {
    // Deklarimi i variablave
    int mosha;
    char iniciali;
    float gjatesia;
    double mesatarja;
    short vleraShort = 12;
    long vleraLong = 123456;

    // Marrja e input-it nga përdoruesi
    printf("Shkruaj moshen: ");
    scanf("%d", &mosha);

    printf("Shkruaj inicialin: ");
    scanf(" %c", &iniciali); // hapsira para %c eshte e rendesishme

    printf("Shkruaj gjatesine (ne metra): ");
    scanf("%f", &gjatesia);

    printf("Shkruaj mesataren: ");
    scanf("%lf", &mesatarja);

    // Shfaqja e te dhenave
    printf("\n----- PROFILI I PERDORUESIT -----\n");
    printf("Mosha: %d\n", mosha);
    printf("Iniciali: %c\n", iniciali);
    printf("Gjatesia: %.2f m\n", gjatesia);
    printf("Mesatarja: %.2lf\n", mesatarja);
    printf("Vlera (short): %d\n", vleraShort);
    printf("Vlera (long): %ld\n", vleraLong);

    return 0;
}