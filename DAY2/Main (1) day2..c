#include <stdio.h>

int main() {
    int mosha;
    char iniciali;
    double piket;
    int opsioni;

    // Input
    printf("Shkruaj moshen: ");
    scanf("%d", &mosha);

    printf("Shkruaj inicialin: ");
    scanf(" %c", &iniciali);

    printf("Shkruaj piket paraprake: ");
    scanf("%lf", &piket);

    printf("Zgjedh punetorine (1, 2 ose 3): ");
    scanf("%d", &opsioni);

    // Kontrolli i moshes
    if (mosha >= 15 && mosha <= 30) {
        printf("Mosha eshte brenda kufirit per pjesemarrje.\n");
    } else {
        printf("Mosha JASHTE kufirit per pjesemarrje.\n");
    }

    // Klasifikimi sipas pikëve
    if (piket < 50) {
        printf("Statusi: Nevojitet me shume ushtrim.\n");
    } else if (piket >= 50 && piket < 80) {
        printf("Statusi: Gati per vazhdim.\n");
    } else {
        printf("Statusi: Gati per sfide.\n");
    }

    // Zgjedhja e punetorise
    printf("Punetoria e zgjedhur: ");
    switch (opsioni) {
        case 1:
            printf("Programim bazik\n");
            break;
        case 2:
            printf("Struktura te dhenave\n");
            break;
        case 3:
            printf("Algoritme\n");
            break;
        default:
            printf("Opsion i pavlefshem\n");
    }

    // Output final (permbledhje)
    printf("\n--- PERMBLEDHJE ---\n");
    printf("Iniciali: %c\n", iniciali);
    printf("Mosha: %d\n", mosha);
    printf("Piket: %.2lf\n", piket);
    printf("Opsioni: %d\n", opsioni);

    return 0;
}