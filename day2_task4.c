#include <stdio.h>

int main() {
    int age, option;
    char initial;
    double points;

    // Input
    printf("Shkruaj moshen: ");
    scanf("%d", &age);

    printf("Shkruaj inicialin: ");
    scanf(" %c", &initial);

    printf("Shkruaj piket paraprake: ");
    scanf("%lf", &points);

    printf("Zgjidh punetorine (1-3): ");
    scanf("%d", &option);

    // Kontroll moshe
    if (age < 10 || age > 60) {
        printf("\nNuk je ne moshen e lejuar per pjesemarrje.\n");
    } else {
        printf("\nMosha eshte valide per pjesemarrje.\n");
    }

    // Klasifikimi sipas pikeve
    if (points < 50) {
        printf("Statusi: Nevojitet me shume ushtrim\n");
    } 
    else if (points < 80) {
        printf("Statusi: Gati per vazhdim\n");
    } 
    else {
        printf("Statusi: Gati per sfide\n");
    }

    // Zgjedhja e punetorise
    printf("Punetoria e zgjedhur: ");
    switch(option) {
        case 1:
            printf("Programim Bazik\n");
            break;
        case 2:
            printf("Web Development\n");
            break;
        case 3:
            printf("Cyber Security\n");
            break;
        default:
            printf("Opsion i pavlefshem\n");
    }

    // Output final
    printf("\n--- PERMBLEDHJE ---\n");
    printf("Mosha: %d\n", age);
    printf("Iniciali: %c\n", initial);
    printf("Piket: %.2lf\n", points);
    printf("Opsioni: %d\n", option);

    return 0;
}