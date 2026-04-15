#include <stdio.h>

int main() {
    int rezultati;

    // Marrja e input-it
    printf("Shkruaj rezultatin (0 - 100): ");
    scanf("%d", &rezultati);

    // Kontrolli i validitetit
    if (rezultati < 0 || rezultati > 100) {
        printf("Input i pavlefshem! Ju lutem vendosni nje vlere nga 0 deri ne 100.\n");
    }
    // Klasifikimi i rezultatit
    else if (rezultati >= 90) {
        printf("Vleresimi: Shkelqyeshem\n");
    }
    else if (rezultati >= 75) {
        printf("Vleresimi: Shume mire\n");
    }
    else if (rezultati >= 60) {
        printf("Vleresimi: Mire\n");
    }
    else {
        printf("Vleresimi: Ne permiresim\n");
    }

    return 0;
}