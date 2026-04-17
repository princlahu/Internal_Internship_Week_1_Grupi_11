#include <stdio.h>

// Enum me 4 nivele
enum Level {BEGINNER = 1, INTERMEDIATE, ADVANCED, EXPERT};

int main() {
    int choice;
    int validCount = 0, invalidCount = 0;

    printf("Choose level:\n");
    printf("1 - Beginner\n");
    printf("2 - Intermediate\n");
    printf("3 - Advanced\n");
    printf("4 - Expert\n");

    // Loop për 3 testime
    for (int i = 1; i <= 3; i++) {
        printf("\nEnter choice for user %d: ", i);
        scanf("%d", &choice);

        switch (choice) {
            case BEGINNER:
                printf("You are a beginner. Start with basics.\n");
                validCount++;
                break;

            case INTERMEDIATE:
                printf("You are intermediate. Practice more.\n");
                validCount++;
                break;

            case ADVANCED:
                printf("You are advanced. Take challenges.\n");
                validCount++;
                break;

            case EXPERT:
                printf("You are expert. Lead others.\n");
                validCount++;
                break;

            default:
                printf("Invalid choice!\n");
                invalidCount++;
        }
    }

    // Statistikat
    printf("\n--- Statistics ---\n");
    printf("Valid inputs: %d\n", validCount);
    printf("Invalid inputs: %d\n", invalidCount);

    return 0;
}