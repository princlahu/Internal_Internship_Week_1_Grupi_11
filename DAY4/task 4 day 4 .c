#include <stdio.h>
#include <string.h>

#define MAX 5

// ENUM
typedef enum {
    FILLUAR = 1,
    NE_PROGRES,
    PERFUNDUAR
} Status;

// STRUCT
struct Regjistrim {
    char emri[50];
    int progresi;
    Status statusi;
};

// kthen statusin ne tekst
const char* statusToString(Status s) {
    switch (s) {
        case FILLUAR: return "Filluar";
        case NE_PROGRES: return "Ne progres";
        case PERFUNDUAR: return "Perfunduaar";
        default: return "I panjohur";
    }
}

// RAPORT ANALITIK
void raport(struct Regjistrim lista[], int count) {

    if (count == 0) {
        printf("\nSka regjistrime.\n");
        return;
    }

    int total = count;
    int perfunduar = 0;
    int shuma = 0;
    int max = lista[0].progresi;
    int min = lista[0].progresi;

    for (int i = 0; i < count; i++) {

        shuma += lista[i].progresi;

        if (lista[i].statusi == PERFUNDUAR)
            perfunduar++;

        if (lista[i].progresi > max)
            max = lista[i].progresi;

        if (lista[i].progresi < min)
            min = lista[i].progresi;
    }

    float mesatarja = (float)shuma / total;

    printf("\n--- RAPORT ---\n");
    printf("Total: %d\n", total);
    printf("Te perfunduara: %d\n", perfunduar);
    printf("Mesatarja: %.2f%%\n", mesatarja);
    printf("Max: %d%%\n", max);
    printf("Min: %d%%\n", min);

    if (mesatarja >= 80)
        printf("Gjendja: Shume mire 🔥\n");
    else if (mesatarja >= 50)
        printf("Gjendja: Mesatare 👍\n");
    else
        printf("Gjendja: Do permiresim ⚠️\n");
}

// KERKIM
void kerko(struct Regjistrim lista[], int count) {

    if (count == 0) {
        printf("Ska regjistrime.\n");
        return;
    }

    char emri[50];
    int found = 0;

    printf("Shkruaj emrin: ");
    scanf(" %[^\n]", emri);

    for (int i = 0; i < count; i++) {

        if (strstr(lista[i].emri, emri) != NULL) {

            found = 1;

            printf("\n%s | %d%% | %s\n",
                   lista[i].emri,
                   lista[i].progresi,
                   statusToString(lista[i].statusi));

            if (lista[i].progresi < 50 && lista[i].statusi != PERFUNDUAR)
                printf("⚠️ Pak progres!\n");
            else if (lista[i].progresi >= 80 && lista[i].statusi == PERFUNDUAR)
                printf("✅ Shume mire!\n");
            else if (lista[i].progresi >= 50)
                printf("👍 OK\n");
        }
    }

    if (!found)
        printf("S’u gjet asgje.\n");
}

int main() {

    struct Regjistrim lista[MAX];
    int count = 0;
    int zgjedhja;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Shto\n");
        printf("2. Shfaq\n");
        printf("3. Raport\n");
        printf("4. Kerko\n");
        printf("0. Dil\n");
        printf("Zgjedh: ");

        scanf("%d", &zgjedhja);

        switch (zgjedhja) {

            case 1:
                if (count >= MAX) {
                    printf("Plot!\n");
                    break;
                }

                printf("Emri: ");
                scanf(" %[^\n]", lista[count].emri);

                printf("Progresi (0-100): ");
                scanf("%d", &lista[count].progresi);

                if (lista[count].progresi < 0 || lista[count].progresi > 100) {
                    printf("Gabim progresi!\n");
                    break;
                }

                int s;
                printf("Status (1.Filluar 2.Ne progres 3.Perfunduar): ");
                scanf("%d", &s);

                if (s == 1) lista[count].statusi = FILLUAR;
                else if (s == 2) lista[count].statusi = NE_PROGRES;
                else if (s == 3) lista[count].statusi = PERFUNDUAR;
                else {
                    printf("Status gabim!\n");
                    break;
                }

                count++;
                printf("U shtu!\n");
                break;

            case 2:
                if (count == 0)
                    printf("Ska regjistrime.\n");
                else {
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

            case 4:
                kerko(lista, count);
                break;

            case 0:
                printf("Bye 👋\n");
                break;

            default:
                printf("Zgjedhje gabim!\n");
        }

    } while (zgjedhja != 0);

    return 0;
}