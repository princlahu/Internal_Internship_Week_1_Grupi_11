#include <stdio.h>

int main() {

    int mosha = 16;
    char iniciali = 'R';
    float gjatesia = 1.68;
    double mesatarja = 4.5;
    short nr_i_vogel = 10;
    long nr_i_madh = 100000;

    printf("\n===== PROFILI I PERDORUESIT =====\n");
    printf("Mosha: %d\n", mosha);
    printf("Iniciali: %c\n", iniciali);
    printf("Gjatesia: %.2f m\n", gjatesia);
    printf("Mesatarja: %.2lf\n", mesatarja);
    printf("Numer i tipit short: %d\n", nr_i_vogel);
    printf("Numer i tipit long: %ld\n", nr_i_madh);

    return 0;
}
