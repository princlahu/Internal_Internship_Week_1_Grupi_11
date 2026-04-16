#include <stdio.h>

int main() {
    int n, choice;

    // Input për madhësinë
    printf("Shkruaj nje numer (1-12): ");
    scanf("%d", &n);

    // Kontroll validiteti
    if (n < 1 || n > 12) {
        printf("Input i pavlefshem!\n");
        return 0;
    }

    // Zgjedhja e pattern-it
    printf("Zgjidh pattern:\n");
    printf("1 - Yje (*)\n");
    printf("2 - Numra\n");
    scanf("%d", &choice);

    printf("\n--- REZULTATI ---\n");

    // Pattern me yje
    if (choice == 1) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                printf("* ");
            }
            printf("\n");
        }
    }
    // Pattern me numra
    else if (choice == 2) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                printf("%d ", j);
            }
            printf("\n");
        }
    }
    // Input i gabuar për zgjedhje
    else {
        printf("Zgjedhje e pavlefshme!\n");
    }

    return 0;
}