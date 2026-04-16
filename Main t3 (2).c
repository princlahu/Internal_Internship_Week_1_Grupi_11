#include <stdio.h>

int main() {
    int start, end;

    int count3 = 0, sum3 = 0;
    int count5 = 0, sum5 = 0;

    // Input
    printf("Shkruani fillimin e intervalit: ");
    scanf("%d", &start);

    printf("Shkruani fundin e intervalit: ");
    scanf("%d", &end);

    // Validimi
    if (start > end) {
        printf("Interval i pavlefshem!\n");
        return 0;
    }

    // Loop
    for (int i = start; i <= end; i++) {
        if (i % 3 == 0) {
            count3++;
            sum3 += i;
        }
        else if (i % 5 == 0 && i % 3 != 0) {
            count5++;
            sum5 += i;
        }
    }

    // Output
    printf("\nIntervali: [%d - %d]\n", start, end);

    printf("Numrat qe pjestohen me 3: %d | Shuma: %d\n", count3, sum3);
    printf("Numrat qe pjestohen me 5 (jo me 3): %d | Shuma: %d\n", count5, sum5);

    // Krahasimi
    if (sum3 > sum5) {
        printf("Shuma e numrave qe pjestohen me 3 eshte me e madhe.\n");
    } else if (sum5 > sum3) {
        printf("Shuma e numrave qe pjestohen me 5 eshte me e madhe.\n");
    } else {
        printf("Shumat jane te barabarta.\n");
    }

    return 0;
}