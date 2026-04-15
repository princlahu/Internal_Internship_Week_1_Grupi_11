#include <stdio.h>

int main() {
    int mosha;
    char iniciali;
    double piket;
    int opsioni;

    // Input
    printf("Shkruani moshen: ");
    scanf("%d", &mosha);

    printf("Shkruani inicialin: ");
    scanf(" %c", &iniciali); // hapësira para %c është e rëndësishme

    printf("Shkruani piket paraprake: ");
    scanf("%lf", &piket);

    printf("Zgjidhni punëtorinë (1, 2 ose 3): ");
    scanf("%d", &opsioni);

    // Kontrolli i moshes
    if (mosha < 14 || mosha > 20) {
        printf("\nNuk jeni brenda moshes se lejuar per pjesemarrje.\n");
    } else {
        printf("\nMosha eshte e pershtatshme per pjesemarrje.\n");
    }

    // Klasifikimi sipas pikëve
    char* rezultati;

    if (piket < 50) {
        rezultati = "Nevojitet me shume ushtrim";
    } else if (piket >= 50 && piket < 80) {
        rezultati = "Gati per vazhdim";
    } else {
        rezultati = "Gati per sfide";
    }

    // Zgjedhja e punëtorisë me switch
    char* punetoria;

    switch (opsioni) {
        case 1:
            punetoria = "Programim bazik";
            break;
        case 2:
            punetoria = "Web development";
            break;
        case 3:
            punetoria = "Cyber security";
            break;
        default:
            punetoria = "Opsion i pavlefshem";
    }

    // Output final
    printf("\n----- PERMBLEDHJE -----\n");
    printf("Mosha: %d\n", mosha);
    printf("Iniciali: %c\n", iniciali);
    printf("Piket: %.2lf\n", piket);
    printf("Punetoria: %s\n", punetoria);
    printf("Rezultati: %s\n", rezultati);

    return 0;
}