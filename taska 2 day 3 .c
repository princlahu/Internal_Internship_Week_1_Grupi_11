#include <stdio.h>

int main() {
    int start, end;
    int countEven = 0, countOdd = 0;
    int sumEven = 0, sumOdd = 0;

    // Input
    printf("Shkruaj vleren fillestare: ");
    scanf("%d", &start);

    printf("Shkruaj vleren perfundimtare: ");
    scanf("%d", &end);

    // Validimi
    if(start > end) {
        printf("Interval jo valid! Fillimi duhet me qene me i vogel ose i barabarte me fundin.\n");
        return 0;
    }

    // Loop ne interval
    for(int i = start; i <= end; i++) {
        if(i % 2 == 0) {
            countEven++;
            sumEven += i;
        } else {
            countOdd++;
            sumOdd += i;
        }
    }

    int total = countEven + countOdd;

    // Output
    printf("\nIntervali: [%d - %d]\n", start, end);
    printf("Totali i numrave: %d\n", total);

    printf("\nNumra çift: %d\n", countEven);
    printf("Shuma e tyre: %d\n", sumEven);

    printf("\nNumra tek: %d\n", countOdd);
    printf("Shuma e tyre: %d\n", sumOdd);

    // Kush ka ma shumë
    if(countEven > countOdd) {
        printf("\nKa me shume numra çift.\n");
    } else if(countOdd > countEven) {
        printf("\nKa me shume numra tek.\n");
    } else {
        printf("\nNumrat çift dhe tek jane te barabarte.\n");
    }

    return 0;
}