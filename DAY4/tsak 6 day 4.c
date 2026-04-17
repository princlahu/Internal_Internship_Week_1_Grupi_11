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

// STATUS TEXT
const char* statusToString(Status s) {
    switch (s) {
        case FILLUAR: return "Filluar";
        case NE_PROGRES: return "Ne progres";
        case PERFUNDUAR: return "Perfunduaar";
        default: return "I panjohur";
    }
}

// SHTO
void shto(struct Regjistrim lista[], int *count) {

    if (*count >= MAX) {
        printf("Kapaciteti u mbush!\n");
        return;
    }

    printf("Emri: ");
    scanf(" %[^\n]", lista[*count].emri);

    printf("Progresi (0-100): ");
    scanf("%d", &lista[*count].progresi);

    if (lista[*count].progresi < 0 || lista[*count].progresi > 100) {
        printf("Progres i pavlefshem!\n");
        return;
    }

    int s;
    printf("Status (1.Filluar 2.Ne progres 3.Perfunduar): ");
    scanf("%d", &s);

    if (s == 1) lista[*count].statusi = FILLUAR;
    else if (s == 2) lista[*count].statusi = NE_PROGRES;
    else if (s == 3) lista[*count].statusi = PERFUNDUAR;
    else {
        printf("Status gabim!\n");
        return;
    }

    (*count)++;
    printf("U shtu!\n");
}

// SHFAQ
void shfaq(struct Regjistrim lista[], int count) {

    if (count == 0) {
        printf("Ska regjistrime.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("%d. %s | %d%% | %s\n",
               i + 1,
               lista[i].emri,
               lista[i].progresi,
               statusToString(lista[i].statusi));
    }
}

// RAPORT
void raport(struct Regjistrim lista[], int count) {

    if (count == 0) {
        printf("Ska te dhena.\n");
        return;
    }

    int total = count;
    int perf = 0;
    int shuma = 0;
    int max = lista[0].progresi;
    int min = lista[0].progresi;

    for (int i = 0; i < count; i++) {

        shuma += lista[i].progresi;

        if (lista[i].statusi == PERFUNDUAR)
            perf++;

        if (lista[i].progresi > max)
            max = lista[i].progresi;

        if (lista[i].progresi < min)
            min = lista[i].progresi;
    }

    float mesatarja = (float)shuma / total;

    printf("\n--- RAPORT ---\n");
    printf("Total: %d\n", total);
    printf("Perfunduara: %d\n", perf);
    printf("Mesatarja: %.2f%%\n", mesatarja);
    printf("Max: %d%%\n", max);
    printf("Min: %d%%\n", min);
}

// POINTER UPDATE
void perditeso(struct Regjistrim *r) {

    int ri;

    printf("Progresi aktual: %d%%\n", r->progresi);
    printf("Ri progresi: ");
    scanf("%d", &ri);

    if (ri < 0 || ri > 100) {
        printf("Gabim!\n");
        return;
    }

    r->progresi = ri;

    if (r->progresi == 100)
        r->statusi = PERFUNDUAR;
    else if (r->progresi >= 50)
        r->statusi = NE_PROGRES;
    else
        r->statusi = FILLUAR;

    printf("U perditesua!\n");
}

// KERKO
void kerko(struct Regjistrim lista[], int count) {

    char emri[50];
    int found = 0;

    if (count == 0) {
        printf("Ska regjistrime.\n");
        return;
    }

    printf("Kerko: ");
    scanf(" %[^\n]", emri);

    for (int i = 0; i < count; i++) {

        if (strstr(lista[i].emri, emri)) {

            found = 1;

            printf("%s | %d%% | %s\n",
                   lista[i].emri,
                   lista[i].progresi,
                   statusToString(lista[i].statusi));
        }
    }

    if (!found)
        printf("Asgje nuk u gjet.\n");
}

// RANKIM (KËRKESA 6)
void rendit(struct Regjistrim lista[], int count) {

    if (count == 0) {
        printf("Ska regjistrime.\n");
        return;
    }

    struct Regjistrim temp[MAX];

    for (int i = 0; i < count; i++) {
        temp[i] = lista[i];
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {

            if (temp[j].progresi < temp[j + 1].progresi) {

                struct Regjistrim t = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = t;
            }
        }
    }

    printf("\n--- RANKIM ---\n");

    for (int i = 0; i < count; i++) {
        printf("%d. %s | %d%% | %s\n",
               i + 1,
               temp[i].emri,
               temp[i].progresi,
               statusToString(temp[i].statusi));
    }
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
        printf("5. Perditeso (pointer)\n");
        printf("6. Rankim\n");
        printf("0. Dil\n");
        printf("Zgjedh: ");

        scanf("%d", &zgjedhja);

        switch (zgjedhja) {

            case 1:
                shto(lista, &count);
                break;

            case 2:
                shfaq(lista, count);
                break;

            case 3:
                raport(lista, count);
                break;

            case 4:
                kerko(lista, count);
                break;

            case 5: {
                int id;
                printf("ID (1-%d): ", count);
                scanf("%d", &id);

                if (id < 1 || id > count) {
                    printf("Gabim!\n");
                    break;
                }

                perditeso(&lista[id - 1]);
                break;
            }

            case 6:
                rendit(lista, count);
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