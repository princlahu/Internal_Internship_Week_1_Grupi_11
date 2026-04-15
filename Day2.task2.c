#include <stdio.h>

int main() {
    int score;

    // Marrim input
    printf("Enter your score (0-100): ");
    scanf("%d", &score);

    // Kontrolli i validitetit
    if (score < 0 || score > 100) {
        printf("Invalid input! Score must be between 0 and 100.\n");
    }
    // Klasifikimi
    else if (score >= 90) {
        printf("Shkelqyeshem\n");
    }
    else if (score >= 75) {
        printf("Shume mire\n");
    }
    else if (score >= 50) {
        printf("Mire\n");
    }
    else {
        printf("Ne permiresim\n");
    }

    return 0;
}