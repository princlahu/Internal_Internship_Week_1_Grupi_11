#include <stdio.h>

int main() {
    int mosha, opsioni;
    char iniciali;
    double pike;

    // Marrja e inputeve
    printf("Shkruaj moshen: ");
    scanf("%d", &mosha);

    printf("Shkruaj inicialin: ");
    scanf(" %c", &iniciali); // hapësira para %c është me rëndësi

    printf("Shkruaj pikat paraprake: ");
    scanf("%lf", &pike);

    printf("Zgjedh punëtorinë (1, 2 ose 3): ");
    scanf("%d", &opsioni);

    // Kontrolli i moshes (p.sh. 15 - 25)
    if (mosha >= 15 && mosha <= 25) {
        printf("\nMosha OK per pjesemarrje.\n");
    } else {
        printf("\nMosha JASHTE kufirit per pjesemarrje.\n");
    }

    // Klasifikimi sipas pikëve
    if (pike < 50) {
        printf("Statusi: Nevojitet me shume ushtrim.\n");
    } else if (pike >= 50 && pike < 80) {
        printf("Statusi: Gati per vazhdim.\n");
    } else {
        printf("Statusi: Gati per sfide.\n");
    }

    // Switch per punëtorinë
    printf("Punetoria e zgjedhur: ");
    switch (opsioni) {
        case 1:
            printf("Programim bazik\n");
            break;
        case 2:
            printf("Algoritme\n");
            break;
        case 3:
            printf("Struktura te dhenash\n");
            break;
        default:
            printf("Opsion jo valid\n");
    }

    // Output final (permbledhje)
    printf("\n--- PERMBLEDHJE ---\n");
    printf("Mosha: %d\n", mosha);
    printf("Iniciali: %c\n", iniciali);
    printf("Piket: %.2lf\n", pike);
    printf("Opsioni: %d\n", opsioni);

    return 0;
}