#include <stdio.h>

int main() {
    // Deklarimi i variablave
    int mosha;
    char iniciali;
    float gjatesia;
    double mesatarja;
    short vleraShort = 10;
    long vleraLong = 100000;

    // Marrja e input-it nga përdoruesi
    printf("Shkruaj moshen: ");
    scanf("%d", &mosha);

    printf("Shkruaj inicialin: ");
    scanf(" %c", &iniciali); // hapsira para %c shmang probleme

    printf("Shkruaj gjatesine (p.sh 1.75): ");
    scanf("%f", &gjatesia);

    printf("Shkruaj mesataren: ");
    scanf("%lf", &mesatarja);

    // Output-i i organizuar
    printf("\n--- Profili i Perdoruesit ---\n");
    printf("Mosha: %d\n", mosha);
    printf("Iniciali: %c\n", iniciali);
    printf("Gjatesia: %.2f m\n", gjatesia);
    printf("Mesatarja: %.2lf\n", mesatarja);
    printf("Vlera short: %hd\n", vleraShort);
    printf("Vlera long: %ld\n", vleraLong);

    return 0;
}