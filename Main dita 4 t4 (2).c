#include <stdio.h>
#include <string.h>

struct Task {
    char emri[50];
    int status; // 0 = jo perfunduar, 1 = perfunduar
};

// FUNKSIONI ME POINTER (KËRKESA 4)
void perfundoTask(struct Task *t) {
    t->status = 1;
    printf("Task u shenua si i perfunduar!\n");
}

// Shfaq te gjitha taskat
void shfaqTaskat(struct Task tasks[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d. %s - %s\n", i + 1, tasks[i].emri,
               tasks[i].status == 1 ? "Perfundoar" : "Jo perfundoar");
    }
}

int main() {
    struct Task tasks[3] = {
        {"Mesimi C", 0},
        {"Projekti IT", 0},
        {"Detyrat e matematikes", 0}
    };

    int zgjedhja;
    int index;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Shfaq taskat\n");
        printf("2. Perfundo nje task\n");
        printf("0. Dil\n");
        printf("Zgjedhja: ");
        scanf("%d", &zgjedhja);

        switch(zgjedhja) {
            case 1:
                shfaqTaskat(tasks, 3);
                break;

            case 2:
                shfaqTaskat(tasks, 3);
                printf("Zgjedh task (1-3): ");
                scanf("%d", &index);

                if(index >= 1 && index <= 3) {
                    // DËRGOJMË ADRESËN (pointer)
                    perfundoTask(&tasks[index - 1]);
                } else {
                    printf("Zgjedhje e gabuar!\n");
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