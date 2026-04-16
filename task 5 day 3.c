#include <stdio.h>

// enum me 4 nivele
enum Niveli {
    FILLESTAR = 1,
    MESATAR,
    AVANCUAR,
    EKSPERT
};

int main() {
    int zgjedhja;

    int valide = 0;
    int pavlefshme = 0;

    // loop per 3 raste
    for (int i = 1; i <= 3; i++) {
        printf("\nRasti %d\n", i);
        printf("Zgjedh nivelin:\n");
        printf("1 - Fillestar\n");
        printf("2 - Mesatar\n");
        printf("3 - Avancuar\n");
        printf("4 - Ekspert\n");
        printf("Input: ");
        scanf("%d", &zgjedhja);

        // switch me enum
        switch (zgjedhja) {
            case FILLESTAR:
                printf("Ti je ne nivel fillestar\n");
                valide++;
                break;

            case MESATAR:
                printf("Ti je ne nivel mesatar\n");
                valide++;
                break;

            case AVANCUAR:
                printf("Ti je ne nivel avancuar\n");
                valide++;
                break;

            case EKSPERT:
                printf("Ti je ne nivel ekspert\n");
                valide++;
                break;

            default:
                printf("Input i pavlefshem!\n");
                pavlefshme++;
        }
    }

    // statistikat
    printf("\n--- STATISTIKA ---\n");
    printf("Zgjedhje valide: %d\n", valide);
    printf("Zgjedhje pavlefshme: %d\n", pavlefshme);

    return 0;
}