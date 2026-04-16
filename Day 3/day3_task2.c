#include <stdio.h>

int main() {
    int start, end;
    int evenCount = 0, oddCount = 0;
    int evenSum = 0, oddSum = 0;

    // Input
    printf("Shkruaj fillimin e intervalit: ");
    scanf("%d", &start);

    printf("Shkruaj fundin e intervalit: ");
    scanf("%d", &end);

    // Kontroll validiteti
    if (start > end) {
        printf("Interval i pavlefshem!\n");
        return 0;
    }

    // Loop per analizim
    for (int i = start; i <= end; i++) {
        if (i % 2 == 0) {
            evenCount++;
            evenSum += i;
        } else {
            oddCount++;
            oddSum += i;
        }
    }

    int totalNumbers = evenCount + oddCount;

    // Output
    printf("\n--- REZULTATI ---\n");
    printf("Intervali: %d - %d\n", start, end);
    printf("Total numra: %d\n", totalNumbers);

    printf("Numra çift: %d | Shuma: %d\n", evenCount, evenSum);
    printf("Numra tek: %d | Shuma: %d\n", oddCount, oddSum);

    // Kush ka me shume
    if (evenCount > oddCount) {
        printf("Ka me shume numra çift.\n");
    } else if (oddCount > evenCount) {
        printf("Ka me shume numra tek.\n");
    } else {
        printf("Ka numer te barabarte çift dhe tek.\n");
    }

    return 0;
}