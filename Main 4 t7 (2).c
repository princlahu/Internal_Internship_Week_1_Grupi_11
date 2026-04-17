#include <stdio.h>
#include <string.h>

struct Task {
    char emri[50];
    int status; // 0 = jo perfunduar, 1 = perfunduar
};

// POINTER (Kërkesa 4)
void perfundoTask(struct Task *t) {
    t->status = 1;
}

// Shfaq taskat
void shfaqTaskat(struct Task tasks[], int n) {
    printf("\n--- LISTA E TASKAVE ---\n");
    for(int i = 0; i < n; i++) {
        printf("%d. %-25s [%s]\n", i + 1, tasks[i].emri,
               tasks[i].status ? "Perfundoar" : "Jo perfundoar");
    }
}

// RENDITJE (Kërkesa 6)
void renditTaskat(struct Task tasks[], int n) {
    struct Task temp;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(tasks[j].status > tasks[i].status) {
                temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }
    printf("Taskat u renditen!\n");
}

// 🔧 NDRYSHIM (EDIT)
void ndryshoTask(struct Task *t) {
    printf("Shkruaj emrin e ri: ");
    scanf(" %[^\n]", t->emri);

    printf("Shkruaj statusin e ri (0/1): ");
    scanf("%d", &t->status);

    printf("Task u perditesua!\n");
}

// ❌ FSHIRJE (DELETE)
void fshiTask(struct Task tasks[], int *n, int index) {
    for(int i = index; i < *n - 1; i++) {
        tasks[i] = tasks[i + 1]; // zhvendos elementet
    }
    (*n)--; // zvogelo numrin total
    printf("Task u fshi!\n");
}

int main() {
    struct Task tasks[10] = {
        {"Mesimi C", 0},
        {"Projekti IT", 1},
        {"Matematike", 0}
    };

    int n = 3; // numri real i taskave
    int zgjedhja, index;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Shfaq taskat\n");
        printf("2. Perfundo task\n");
        printf("3. Rendit taskat\n");
        printf("4. Ndrysho task\n");
        printf("5. Fshi task\n");
        printf("0. Dil\n");
        printf("Zgjedhja: ");
        scanf("%d", &zgjedhja);

        switch(zgjedhja) {

            case 1:
                shfaqTaskat(tasks, n);
                break;

            case 2:
                shfaqTaskat(tasks, n);
                printf("Zgjedh task: ");
                scanf("%d", &index);

                if(index >= 1 && index <= n) {
                    perfundoTask(&tasks[index - 1]);
                } else {
                    printf("Gabim!\n");
                }
                break;

            case 3:
                renditTaskat(tasks, n);
                shfaqTaskat(tasks, n);
                break;

            case 4:
                shfaqTaskat(tasks, n);
                printf("Zgjedh task: ");
                scanf("%d", &index);

                if(index >= 1 && index <= n) {
                    ndryshoTask(&tasks[index - 1]);
                } else {
                    printf("Gabim!\n");
                }
                break;

            case 5:
                shfaqTaskat(tasks, n);
                printf("Zgjedh task: ");
                scanf("%d", &index);

                if(index >= 1 && index <= n) {
                    fshiTask(tasks, &n, index - 1);
                } else {
                    printf("Gabim!\n");
                }
                break;

            case 0:
                printf("Programi u mbyll.\n");
                break;

            default:
                printf("Zgjedhje e pavlefshme!\n");
        }

    } while(zgjedhja != 0);

    return 0;
}