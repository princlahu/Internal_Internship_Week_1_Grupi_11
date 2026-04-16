#include <stdio.h>

int main() {
    int start, end;
    int evenCount = 0, oddCount = 0;
    int evenSum = 0, oddSum = 0;

    // Input
    printf("Shkruani vleren fillestare: ");
    scanf("%d", &start);

    printf("Shkruani vleren perfundimtare: ");
    scanf("%d", &end);

    // Validimi
    if (start > end) {
        printf("Interval i pavlefshem! Fillimi duhet te jete me i vogel ose i barabarte me fundin.\n");
        return 0;
    }

    // Loop
    for (int i = start; i <= end; i++) {
        if (i % 2 == 0) {
            evenCount++;
            evenSum += i;
        } else {
            oddCount++;
            oddSum += i;
        }
    }

    int totalNumbers = end - start + 1;

    // Output
    printf("\nIntervali: [%d - %d]\n", start, end);
    printf("Totali i numrave: %d\n", totalNumbers);

    printf("Numra çift: %d | Shuma: %d\n", evenCount, evenSum);
    printf("Numra tek: %d | Shuma: %d\n", oddCount, oddSum);

    if (evenCount > oddCount) {
        printf("Ka me shume numra çift.\n");
    } else if (oddCount > evenCount) {
        printf("Ka me shume numra tek.\n");
    } else {
        printf("Numri i numrave çift dhe tek eshte i barabarte.\n");
    }

    return 0;
}