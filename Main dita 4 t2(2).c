#include <stdio.h>
#include <string.h>

#define MAX 5

// ENUM
enum Status {
    IN_PROGRESS = 1,
    COMPLETED = 2
};

// STRUCT
struct Student {
    int id;
    char name[50];
    float progress;
    enum Status status;
};

// FUNKSION për zgjedhje të statusit me validim
enum Status chooseStatus() {
    int choice;

    do {
        printf("Zgjidh statusin:\n");
        printf("1. In Progress\n");
        printf("2. Completed\n");
        printf("Zgjedhja: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                return IN_PROGRESS;
            case 2:
                return COMPLETED;
            default:
                printf("Zgjedhje e pavlefshme! Provo perseri.\n");
        }

    } while (1);
}

// FUNKSION për shtim (pointer)
void addStudent(struct Student *s) {
    printf("ID: ");
    scanf("%d", &s->id);

    printf("Name: ");
    scanf("%s", s->name);

    // VALIDIM progress
    do {
        printf("Progress (0-100): ");
        scanf("%f", &s->progress);

        if (s->progress < 0 || s->progress > 100) {
            printf("Progress i pavlefshem! Provo perseri.\n");
        }

    } while (s->progress < 0 || s->progress > 100);

    // ZGJEDH STATUSIN
    s->status = chooseStatus();
}

// SHFAQ
void showStudents(struct Student students[], int count) {
    if (count == 0) {
        printf("Nuk ka te dhena.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("\nStudent %d\n", i + 1);
        printf("ID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("Progress: %.2f\n", students[i].progress);

        switch (students[i].status) {
            case IN_PROGRESS:
                printf("Status: In Progress\n");
                break;
            case COMPLETED:
                printf("Status: Completed\n");
                break;
        }
    }
}

int main() {
    struct Student students[MAX];
    int count = 0;
    int choice;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Add Student\n");
        printf("2. Show Students\n");
        printf("0. Exit\n");
        printf("Zgjedhja: ");
        scanf("%d", &choice);

        // VALIDIM MENU
        if (choice < 0 || choice > 2) {
            printf("Zgjedhje e pavlefshme! Provo perseri.\n");
            continue;
        }

        switch (choice) {

            case 1:
                if (count < MAX) {
                    addStudent(&students[count]);
                    count++;
                    printf("Student added!\n");
                } else {
                    printf("Ke arritur limitin maksimal!\n");
                }
                break;

            case 2:
                showStudents(students, count);
                break;

            case 0:
                printf("Dalje...\n");
                break;
        }

    } while (choice != 0);

    return 0;
}