#include <stdio.h>

// Enum për nivelin e nxënësit
enum Niveli {
    FILLOR = 1,
    MESATAR,
    AVANCUAR,
    EKSPERT
};

int main() {
    int zgjedhja;
    int valid = 0, invalid = 0;

    // 3 testime me for loop
    for (int i = 1; i <= 3; i++) {
        printf("\nZgjedhja %d:\n", i);
        printf("1 - Fillor\n");
        printf("2 - Mesatar\n");
        printf("3 - Avancuar\n");
        printf("4 - Ekspert\n");
        printf("Zgjidh nje numer: ");
        scanf("%d", &zgjedhja);

        enum Niveli niveli = zgjedhja;

        switch (niveli) {
            case FILLOR:
                printf("Je ne nivelin fillor. Vazhdo te mesosh bazat.\n");
                valid++;
                break;

            case MESATAR:
                printf("Je ne nivel mesatar. Ke perparim te mire.\n");
                valid++;
                break;

            case AVANCUAR:
                printf("Je ne nivel te avancuar. Shume mire!\n");
                valid++;
                break;

            case EKSPERT:
                printf("Je ekspert. Shkelqyeshem!\n");
                valid++;
                break;

            default:
                printf("Zgjedhje e pavlefshme!\n");
                invalid++;
        }
    }

    // Statistikat
    printf("\n--- Statistikat ---\n");
    printf("Zgjedhje valide: %d\n", valid);
    printf("Zgjedhje te pavlefshme: %d\n", invalid);

    return 0;
}