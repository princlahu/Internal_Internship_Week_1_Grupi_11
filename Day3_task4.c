#include <stdio.h>

int main() {
    int num;
    double value;

    // Input
    printf("Enter an integer: ");
    scanf("%d", &num);

    printf("Enter a decimal number: ");
    scanf("%lf", &value);

    // Pointer-at
    int *pNum = &num;
    double *pValue = &value;

    // Printim fillestar
    printf("\n--- Initial Values ---\n");
    printf("num = %d\n", num);
    printf("value = %.2lf\n", value);

    printf("\nAddresses:\n");
    printf("&num = %p\n", &num);
    printf("&value = %p\n", &value);

    printf("\nValues via pointers:\n");
    printf("*pNum = %d\n", *pNum);
    printf("*pValue = %.2lf\n", *pValue);

    // Ruajmë vlerat para ndryshimit
    int oldNum = num;

    // Ndryshimi përmes pointer-it
    *pNum = *pNum + 10;

    printf("\n--- After Change ---\n");
    printf("num (after) = %d\n", num);

    // Kontroll me if/else
    if (num > oldNum) {
        printf("Value increased.\n");
    } else if (num < oldNum) {
        printf("Value decreased.\n");
    } else {
        printf("Value remained the same.\n");
    }

    // Kontroll shtesë intervali
    if (num >= 0 && num <= 50) {
        printf("Value is in range 0-50.\n");
    } else {
        printf("Value is outside range 0-50.\n");
    }

    return 0;
}