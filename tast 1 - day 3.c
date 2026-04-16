#include <stdio.h>

int main() {
    int size, choice;
    int i, j;

    printf("Jep madhesine e pattern-it (1-12): ");
    scanf("%d", &size);

    if (size < 1 || size > 12) {
        printf("Input invalid. Ju lutem jepni nje numer nga 1 deri ne 12.\n");
        return 1;
    }

    printf("Zgjidh pattern-in:\n");
    printf("1. Me yje\n");
    printf("2. Me numra\n");
    printf("Zgjedhja juaj: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nPattern me yje:\n");
        for (i = 1; i <= size; i++) {
            for (j = 1; j <= i; j++) {
                printf("*");
            }
            printf("\n");
        }
    }
    else if (choice == 2) {
        printf("\nPattern me numra:\n");
        for (i = 1; i <= size; i++) {
            for (j = 1; j <= i; j++) {
                printf("%d", j);
            }
            printf("\n");
        }
    }
    else {
        printf("Zgjedhje e pavlefshme.\n");
    }

    return 0;
}