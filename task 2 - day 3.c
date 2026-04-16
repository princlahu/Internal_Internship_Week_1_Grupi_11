#include <stdio.h>

int main() {
    int start, end;
    int i;
    int evenCount = 0, oddCount = 0;
    int evenSum = 0, oddSum = 0;
    int totalValues;

    printf("Jep vleren fillestare te intervalit: ");
    scanf("%d", &start);

    printf("Jep vleren perfundimtare te intervalit: ");
    scanf("%d", &end);

    if (start > end) {
        printf("Interval i pavlefshem. Vlera fillestare duhet te jete me e vogel ose e barabarte me vleren perfundimtare.\n");
        return 1;
    }

    for (i = start; i <= end; i++) {
        if (i % 2 == 0) {
            evenCount++;
            evenSum += i;
        } else {
            oddCount++;
            oddSum += i;
        }
    }

    totalValues = end - start + 1;

    printf("\nRezultatet:\n");
    printf("Intervali: %d deri %d\n", start, end);
    printf("Totali i vlerave: %d\n", totalValues);
    printf("Numra cift: %d\n", evenCount);
    printf("Numra tek: %d\n", oddCount);
    printf("Shuma e numrave cift: %d\n", evenSum);
    printf("Shuma e numrave tek: %d\n", oddSum);

    if (evenCount > oddCount) {
        printf("Ka me shume numra cift ne interval.\n");
    } else if (oddCount > evenCount) {
        printf("Ka me shume numra tek ne interval.\n");
    } else {
        printf("Numri i vlerave cift dhe tek eshte i barabarte.\n");
    }

    return 0;
}