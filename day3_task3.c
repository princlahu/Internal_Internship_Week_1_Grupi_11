#include <stdio.h>

int main() {
    int start, end;
    int sumDiv3 = 0, countDiv3 = 0;
    int sumDiv5 = 0, countDiv5 = 0;

    // Input
    printf("Enter start of interval: ");
    scanf("%d", &start);

    printf("Enter end of interval: ");
    scanf("%d", &end);

    // Kontrolli i intervalit
    if (start > end) {
        printf("Invalid interval!\n");
        return 0;
    }

    // Loop për analizë
    for (int i = start; i <= end; i++) {

        // Numrat që pjesëtohen me 3
        if (i % 3 == 0) {
            sumDiv3 += i;
            countDiv3++;
        }
        // Numrat që pjesëtohen me 5 por JO me 3
        else if (i % 5 == 0) {
            sumDiv5 += i;
            countDiv5++;
        }
    }

    // Output
    printf("\n--- Results ---\n");
    printf("Interval: %d to %d\n", start, end);

    printf("Divisible by 3 -> Count: %d, Sum: %d\n", countDiv3, sumDiv3);
    printf("Divisible by 5 (not 3) -> Count: %d, Sum: %d\n", countDiv5, sumDiv5);

    // Krahasimi i shumave
    if (sumDiv3 > sumDiv5) {
        printf("Sum of numbers divisible by 3 is greater.\n");
    } else if (sumDiv5 > sumDiv3) {
        printf("Sum of numbers divisible by 5 (not 3) is greater.\n");
    } else {
        printf("Both sums are equal.\n");
    }

    return 0;
}