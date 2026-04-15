#include <stdio.h>

int main() {
    int result;

    printf("Enter your result (0-100): ");
    scanf("%d", &result);

    if (result < 0 || result > 100) {
        printf("Invalid input. Please enter a value between 0 and 100.\n");
    }
    else if (result >= 90) {
        printf("Evaluation: Excellent\n");
    }
    else if (result >= 75) {
        printf("Evaluation: Very Good\n");
    }
    else if (result >= 50) {
        printf("Evaluation: Good\n");
    }
    else {
        printf("Evaluation: Needs Improvement\n");
    }

    return 0;
}