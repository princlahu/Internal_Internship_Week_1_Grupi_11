#include <stdio.h>
#include <string.h>

struct Task {
    char emri[50];
    int status; // 0 = jo perfunduar, 1 = perfunduar
};

// KËRKESA 4 - POINTER
void perfundoTask(struct Task *t) {
    t->status = 1;
    printf("Task u shenua si i perfunduar!\n");
}

// Shfaq taskat
void shfaqTaskat(struct Task tasks[], int n) {
    printf("\n--- LISTA E TASKAVE ---\n");
    for(int i = 0; i < n; i++) {
        printf("%d. %-25s [%s]\n", i + 1, tasks[i].emri,
               tasks[i].status ? "Perfundoar" : "Jo perfundoar");
    }
}

// KËRKESA 6 - RENDITJE (ranking)
void renditTaskat(struct Task tasks[], int n) {
    struct Task temp;

    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            // Taskat e perfunduara (1) dalin para atyre jo (0)
            if(tasks[j].status > tasks[i].status) {
                temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }

    printf("\nTaskat u renditen sipas statusit!\n");
}

int main() {
    struct Task tasks[5] = {
        {"Mesimi C", 0},
        {"Projekti IT", 1},
        {"Detyrat e matematikes", 0},
        {"Leximi", 1},
        {"Ushtrime", 0}
    };

    int zgjedhja, index;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Shfaq taskat\n");
        printf("2. Perfundo nje task\n");
        printf("3. Rendit taskat (ranking)\n");
        printf("0. Dil\n");
        printf("Zgjedhja: ");
        scanf("%d", &zgjedhja);

        switch(zgjedhja) {
            case 1:
                shfaqTaskat(tasks, 5);
                break;

            case 2:
                shfaqTaskat(tasks, 5);
                printf("Zgjedh task (1-5): ");
                scanf("%d", &index);

                if(index >= 1 && index <= 5) {
                    perfundoTask(&tasks[index - 1]); // POINTER
                } else {
                    printf("Zgjedhje e gabuar!\n");
                }
                break;

            case 3:
                renditTaskat(tasks, 5);
                shfaqTaskat(tasks, 5);
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