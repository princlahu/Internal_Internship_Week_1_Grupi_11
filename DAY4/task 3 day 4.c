#include <stdio.h>
#include <string.h>

#define MAX 5

typedef enum {
    FILLUAR = 1,
    NE_PROGRES,
    PERFUNDUAR
} Status;

struct Regjistrim {
    char emri[50];
    int progresi;
    Status statusi;
};

const char* statusToString(Status s) {
    switch (s) {
        case FILLUAR: return "Filluar";
        case NE_PROGRES: return "Ne progres";
        case PERFUNDUAR: return "Perfunduaar";
        default: return "I panjohur";
    }
}

// FUNKSION për raport
void raport(struct Regjistrim lista[], int count) {

    if (count == 0) {
        printf("\n--- RAPORT ---\n");
        printf("Nuk ka asnje regjistrim.\n");
        return;
    }

    int total = count;
    int perfunduar = 0;
    int shuma = 0;
    int max = lista[0].progresi;
    int min = lista[0].progresi;

    for (int i = 0; i < count; i++) {

        shuma += lista[i].progresi;

        if (lista[i].statusi == PERFUNDUAR) {
            perfunduar++;
        }

        if (lista[i].progresi > max) {
            max = lista[i].progresi;
        }

        if (lista[i].progresi < min) {
            min = lista[i].progresi;
        }
    }

    float mesatarja = (float)shuma / total;

    printf("\n--- RAPORT ---\n");
    printf("Total regjistrime: %d\n", total);
    printf("Te perfunduara: %d\n", perfunduar);
    printf("Mesatarja e progresit: %.2f%%\n", mesatarja);
    printf("Max progresi: %d%%\n", max);
    printf("Min progresi: %d%%\n", min);

    // KLASIFIKIM me if/else
    if (mesatarja >= 80) {
        printf("Gjendja: Shume mire 🔥\n");
    } else if (mesatarja >= 50) {
        printf("Gjendja: Mesatare 👍\n");
    } else {
        printf("Gjendja: Ka nevoje per permiresim ⚠️\n");
    }
}

int main() {

    struct Regjistrim lista[MAX];
    int count = 0;
    int zgjedhja;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Shto regjistrim\n");
        printf("2. Shfaq regjistrimet\n");
        printf("3. Raport analitik\n");
        printf("0. Dil\n");
        printf("Zgjedh: ");

        if (scanf("%d", &zgjedhja) != 1) {
            printf("Input i pavlefshem!\n");
            while(getchar() != '\n');
            continue;
        }

        switch (zgjedhja) {

            case 1:
                if (count >= MAX) {
                    printf("Ke arrit maksimumin!\n");
                    break;
                }

                printf("Shkruaj emrin: ");
                scanf(" %[^\n]", lista[count].emri);

                printf("Progresi (0-100): ");
                scanf("%d", &lista[count].progresi);

                if (lista[count].progresi < 0 || lista[count].progresi > 100) {
                    printf("Progres i pavlefshem!\n");
                    break;
                }

                int s;
                printf("Status:\n1.Filluar\n2.Ne progres\n3.Perfunduaar\nZgjedh: ");
                scanf("%d", &s);

                switch (s) {
                    case 1: lista[count].statusi = FILLUAR; break;
                    case 2: lista[count].statusi = NE_PROGRES; break;
                    case 3: lista[count].statusi = PERFUNDUAR; break;
                    default:
                        printf("Status gabim!\n");
                        break;
                }

                if (s >= 1 && s <= 3) {
                    count++;
                    printf("U shtu!\n");
                }

                break;

            case 2:
                if (count == 0) {
                    printf("Ska regjistrime.\n");
                } else {
                    for (int i = 0; i < count; i++) {
                        printf("%d. %s | %d%% | %s\n",
                               i + 1,
                               lista[i].emri,
                               lista[i].progresi,
                               statusToString(lista[i].statusi));
                    }
                }
                break;

            case 3:
                raport(lista, count);
                break;

            case 0:
                printf("Programi u mbyll.\n");
                break;

            default:
                printf("Zgjedhje e pavlefshme!\n");
        }

    } while (zgjedhja != 0);

    return 0;
}