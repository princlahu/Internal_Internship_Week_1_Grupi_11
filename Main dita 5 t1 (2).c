#include <stdio.h>
#include <string.h>

#define MAX 5

// ENUM për status
enum Status {
    IN_PROGRESS,
    COMPLETED
};

// STRUKTURA e studentit
struct Student {
    int id;
    char name[50];
    float progress;
    enum Status status;
};

// FUNKSION për shtim (me pointer)
void addStudent(struct Student *s) {
    printf("ID: ");
    scanf("%d", &s->id);

    printf("Name: ");
    scanf("%s", s->name);

    printf("Progress (0-100): ");
    scanf("%f", &s->progress);

    if (s->progress >= 50) {
        s->status = COMPLETED;
    } else {
        s->status = IN_PROGRESS;
    }
}

// SHFAQ STUDENTËT
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

        if (students[i].status == COMPLETED) {
            printf("Status: Completed\n");
        } else {
            printf("Status: In Progress\n");
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

        switch (choice) {

            case 1:
                if (count < MAX) {
                    addStudent(&students[count]); // pointer
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

            default:
                printf("Zgjedhje e pavlefshme!\n");
        }

    } while (choice != 0);

    return 0;
}