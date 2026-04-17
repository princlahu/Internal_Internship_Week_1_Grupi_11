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

    // Validimi
    if(start > end) {
        printf("Interval jo valid!\n");
        return 0;
    }

    // Loop
    for(int i = start; i <= end; i++) {

        // Numrat qe pjestohet me 3
        if(i % 3 == 0) {
            count3++;
            sum3 += i;
        }
        // Numrat qe pjestohet me 5 POR jo me 3
        else if(i % 5 == 0 && i % 3 != 0) {
            count5++;
            sum5 += i;
        }
    }

    // Output
    printf("\nIntervali: [%d - %d]\n", start, end);

    printf("\nPjestues me 3:\n");
    printf("Numerimi: %d\n", count3);
    printf("Shuma: %d\n", sum3);

    printf("\nPjestues me 5 (jo me 3):\n");
    printf("Numerimi: %d\n", count5);
    printf("Shuma: %d\n", sum5);

    // Krahasimi
    if(sum3 > sum5) {
        printf("\nShuma e numrave qe pjestohen me 3 eshte me e madhe.\n");
    } else if(sum5 > sum3) {
        printf("\nShuma e numrave qe pjestohen me 5 eshte me e madhe.\n");
    } else {
        printf("\nShumat jane te barabarta.\n");
    }

    return 0;
}