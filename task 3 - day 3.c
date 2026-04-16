#include <stdio.h>

int main() {
    int start, end;
    int i;
    int countDiv3 = 0, sumDiv3 = 0;
    int countDiv5Not3 = 0, sumDiv5Not3 = 0;

    printf("Jep fillimin e intervalit: ");
    scanf("%d", &start);

    printf("Jep fundin e intervalit: ");
    scanf("%d", &end);

    if (start > end) {
        printf("Input i pavlefshem. Fillimi i intervalit duhet te jete me i vogel ose i barabarte me fundin.\n");
        return 1;
    }

    for (i = start; i <= end; i++) {
        if (i % 3 == 0) {
            countDiv3++;
            sumDiv3 += i;
        }
        else if (i % 5 == 0 && i % 3 != 0) {
            countDiv5Not3++;
            sumDiv5Not3 += i;
        }
    }

    printf("\nRezultatet:\n");
    printf("Intervali: %d deri %d\n", start, end);
    printf("Numrat qe pjesetohen me 3: %d\n", countDiv3);
    printf("Shuma e tyre: %d\n", sumDiv3);
    printf("Numrat qe pjesetohen me 5 por jo me 3: %d\n", countDiv5Not3);
    printf("Shuma e tyre: %d\n", sumDiv5Not3);

    if (sumDiv3 > sumDiv5Not3) {
        printf("Shuma e numrave qe pjesetohen me 3 eshte me e madhe.\n");
    }
    else if (sumDiv5Not3 > sumDiv3) {
        printf("Shuma e numrave qe pjesetohen me 5 por jo me 3 eshte me e madhe.\n");
    }
    else {
        printf("Te dy shumat jane te barabarta.\n");
    }

    return 0;
}