#include <stdio.h>

int main() {
    int n, choice;

    // Marrim input nga useri
    printf("Shkruaj nje numer (1 - 12): ");
    scanf("%d", &n);

    // Validimi i input-it
    if(n < 1 || n > 12) {
        printf("Input jo valid! Duhet me qene prej 1 deri 12.\n");
        return 0;
    }

    // Zgjedhja e pattern-it
    printf("Zgjedh pattern:\n");
    printf("1 - Me yje (*)\n");
    printf("2 - Me numra\n");
    printf("Zgjedh: ");
    scanf("%d", &choice);

    if(choice == 1) {
        // Pattern me yje
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= i; j++) {
                printf("* ");
            }
            printf("\n");
        }
    }
    else if(choice == 2) {
        // Pattern me numra
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= i; j++) {
                printf("%d ", j);
            }
            printf("\n");
        }
    }
    else {
        printf("Zgjedhje jo valide!\n");
    }

    return 0;
}