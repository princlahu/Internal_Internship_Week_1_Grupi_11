#include <stdio.h>

int main() {

    int rezultati;

    printf("Shkruaj rezultatin (0-100): ");
    scanf("%d", &rezultati);

    if (rezultati < 0 || rezultati > 100) {
        printf("Input nuk eshte valid\n");
    }
    else if (rezultati >= 90 && rezultati <= 100) {
        printf("Shkelqyeshem\n");
    }
    else if (rezultati >= 75 && rezultati < 90) {
        printf("Shume mire\n");
    }
    else if (rezultati >= 50 && rezultati < 75) {
        printf("Mire\n");
    }
    else {
        printf("Ne permiresim\n");
    }

    return 0;

}