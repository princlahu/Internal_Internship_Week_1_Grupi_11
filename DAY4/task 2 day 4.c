#include <stdio.h>
#include <string.h>

#define MAX 5

// ENUM për statusin
typedef enum {
    FILLUAR = 1,
    NE_PROGRES,
    PERFUNDUAR
} Status;

// Struktura
struct Regjistrim {
    char emri[50];
    int progresi;
    Status statusi;
};

// Me e kthy enum në tekst
const char* statusToString(Status s) {
    switch (s) {
        case FILLUAR: return "Filluar";
        case NE_PROGRES: return "Ne progres";
        case PERFUNDUAR: return "Perfunduaar";
        default: return "I panjohur";
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
        printf("0. Dil\n");
        printf("Zgjedh: ");

        if (scanf("%d", &zgjedhja) != 1) {
            printf("Input i pavlefshem!\n");
            while(getchar() != '\n'); // pastrim buffer
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

                printf("Shkruaj progresin (0-100): ");
                scanf("%d", &lista[count].progresi);

                // VALIDIM progresi
                if (lista[count].progresi < 0 || lista[count].progresi > 100) {
                    printf("Progresi duhet 0-100!\n");
                    break;
                }

                int zgjedhStatus;
                printf("\nZgjedh statusin:\n");
                printf("1. Filluar\n");
                printf("2. Ne progres\n");
                printf("3. Perfunduaar\n");
                printf("Zgjedh: ");

                if (scanf("%d", &zgjedhStatus) != 1) {
                    printf("Input gabim!\n");
                    while(getchar() != '\n');
                    break;
                }

                // SWITCH për status (kërkesa)
                switch (zgjedhStatus) {
                    case 1:
                        lista[count].statusi = FILLUAR;
                        break;
                    case 2:
                        lista[count].statusi = NE_PROGRES;
                        break;
                    case 3:
                        lista[count].statusi = PERFUNDUAR;
                        break;
                    default:
                        printf("Status i pavlefshem!\n");
                        break;
                }

                // vetëm nëse status valid rritet count
                if (zgjedhStatus >= 1 && zgjedhStatus <= 3) {
                    count++;
                    printf("Regjistrimi u shtu!\n");
                }

                break;

            case 2:
                if (count == 0) {
                    printf("Ska regjistrime.\n");
                } else {
                    printf("\n--- Lista ---\n");
                    for (int i = 0; i < count; i++) {
                        printf("%d. Emri: %s | Progresi: %d%% | Status: %s\n",
                               i + 1,
                               lista[i].emri,
                               lista[i].progresi,
                               statusToString(lista[i].statusi));
                    }
                }
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