#include <stdio.h>

int main() {
    int start, end;

    int count3 = 0, sum3 = 0;
    int count5 = 0, sum5 = 0;

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

    // Loop
    for (int i = start; i <= end; i++) {

        // Numrat qe pjesetohen me 3
        if (i % 3 == 0) {
            count3++;
            sum3 += i;
        }
        // Numrat qe pjesetohen me 5 POR jo me 3
        else if (i % 5 == 0) {
            count5++;
            sum5 += i;
        }
    }

    // Output
    printf("\n--- REZULTATI ---\n");
    printf("Intervali: %d - %d\n", start, end);

    printf("Te pjestueshem me 3 -> Nr: %d | Shuma: %d\n", count3, sum3);
    printf("Te pjestueshem me 5 (jo me 3) -> Nr: %d | Shuma: %d\n", count5, sum5);

    // Krahasimi i shumave
    if (sum3 > sum5) {
        printf("Shuma e numrave qe pjesetohen me 3 eshte me e madhe.\n");
    } else if (sum5 > sum3) {
        printf("Shuma e numrave qe pjesetohen me 5 eshte me e madhe.\n");
    } else {
        printf("Shumat jane te barabarta.\n");
    }

    return 0;
}