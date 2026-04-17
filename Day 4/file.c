#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STUDENTS 5
#define NAME_LENGTH 50

typedef enum {
    NOT_STARTED = 1,
    IN_PROGRESS = 2,
    COMPLETED = 3
} Status;

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int progress;
    Status status;
} StudentRecord;

void clearInputBuffer(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
    }
}

const char* statusToText(Status status) {
    switch (status) {
        case NOT_STARTED:
            return "Not Started";
        case IN_PROGRESS:
            return "In Progress";
        case COMPLETED:
            return "Completed";
        default:
            return "Unknown";
    }
}

void printSingleRecord(StudentRecord record) {
    printf("ID: %d\n", record.id);
    printf("Emri: %s\n", record.name);
    printf("Progresi: %d\n", record.progress);
    printf("Statusi: %s\n", statusToText(record.status));
}

int containsIgnoreCase(const char text[], const char search[]) {
    int i, j;

    if (strlen(search) == 0) {
        return 0;
    }

    for (i = 0; text[i] != '\0'; i++) {
        j = 0;

        while (search[j] != '\0' &&
               text[i + j] != '\0' &&
               tolower((unsigned char)text[i + j]) == tolower((unsigned char)search[j])) {
            j++;
        }

        if (search[j] == '\0') {
            return 1;
        }
    }

    return 0;
}

void showRecordEvaluation(StudentRecord record) {
    printf("Vleresimi: ");

    if (record.progress < 50 && record.status != COMPLETED) {
        printf("Paralajmerim - progres i ulet dhe regjistrimi nuk eshte perfunduar.\n");
    } else if (record.progress >= 50 && record.progress < 80 && record.status == IN_PROGRESS) {
        printf("Rekomandim - progres i pranueshem, por duhet vazhduar puna.\n");
    } else if (record.progress >= 80 && record.status == COMPLETED) {
        printf("Shume mire - progres i larte dhe regjistrimi eshte perfunduar.\n");
    } else if (record.progress >= 80 && record.status != COMPLETED) {
        printf("Rekomandim - rezultat i mire, por statusi ende nuk eshte completed.\n");
    } else {
        printf("Gjendje normale - vazhdo monitorimin e progresit.\n");
    }
}

int readStatus(Status *status) {
    int choice;

    printf("Zgjidh statusin:\n");
    printf("1. Not Started\n");
    printf("2. In Progress\n");
    printf("3. Completed\n");
    printf("Zgjedhja: ");

    if (scanf("%d", &choice) != 1) {
        clearInputBuffer();
        printf("Input i pavlefshem per statusin.\n");
        return 0;
    }

    switch (choice) {
        case NOT_STARTED:
        case IN_PROGRESS:
        case COMPLETED:
            *status = (Status)choice;
            return 1;
        default:
            printf("Status i pavlefshem. Provo perseri.\n");
            return 0;
    }
}

int addStudentRecord(StudentRecord records[], int *count) {
    StudentRecord newRecord;

    if (*count >= MAX_STUDENTS) {
        printf("Nuk mund te shtohen me regjistrime. U arrit maksimumi prej %d.\n", MAX_STUDENTS);
        return 0;
    }

    printf("\nShto regjistrim te ri\n");

    printf("ID: ");
    if (scanf("%d", &newRecord.id) != 1) {
        clearInputBuffer();
        printf("ID i pavlefshem.\n");
        return 0;
    }

    clearInputBuffer();

    printf("Emri: ");
    if (fgets(newRecord.name, NAME_LENGTH, stdin) == NULL) {
        printf("Gabim gjate leximit te emrit.\n");
        return 0;
    }

    newRecord.name[strcspn(newRecord.name, "\n")] = '\0';

    if (strlen(newRecord.name) == 0) {
        printf("Emri nuk mund te jete bosh.\n");
        return 0;
    }

    printf("Progresi ose rezultati (0 - 100): ");
    if (scanf("%d", &newRecord.progress) != 1) {
        clearInputBuffer();
        printf("Vlere e pavlefshme per progresin.\n");
        return 0;
    }

    if (newRecord.progress < 0 || newRecord.progress > 100) {
        printf("Progresi duhet te jete nga 0 deri ne 100.\n");
        return 0;
    }

    if (!readStatus(&newRecord.status)) {
        return 0;
    }

    records[*count] = newRecord;
    (*count)++;

    printf("Regjistrimi u shtua me sukses.\n");
    return 1;
}

void showAllRecords(StudentRecord records[], int count) {
    int i;

    if (count == 0) {
        printf("\nNuk ka regjistrime te ruajtura.\n");
        return;
    }

    printf("\nLista e regjistrimeve:\n");
    printf("--------------------------------------------------\n");

    for (i = 0; i < count; i++) {
        printf("Regjistrimi %d\n", i + 1);
        printSingleRecord(records[i]);
        printf("--------------------------------------------------\n");
    }
}

void showReport(StudentRecord records[], int count) {
    int i;
    int completedCount = 0;
    int sumProgress = 0;
    int highestProgress;
    int lowestProgress;
    double averageProgress;

    if (count == 0) {
        printf("\nNuk ka regjistrime per raport.\n");
        return;
    }

    highestProgress = records[0].progress;
    lowestProgress = records[0].progress;

    for (i = 0; i < count; i++) {
        sumProgress += records[i].progress;

        if (records[i].status == COMPLETED) {
            completedCount++;
        }

        if (records[i].progress > highestProgress) {
            highestProgress = records[i].progress;
        } else if (records[i].progress < lowestProgress) {
            lowestProgress = records[i].progress;
        }
    }

    averageProgress = (double)sumProgress / count;

    printf("\n===== Raport Analitik =====\n");
    printf("Numri total i regjistrimeve: %d\n", count);
    printf("Numri i rasteve te perfunduara: %d\n", completedCount);
    printf("Mesatarja e progresit: %.2f\n", averageProgress);
    printf("Progresi me i larte: %d\n", highestProgress);
    printf("Progresi me i ulet: %d\n", lowestProgress);

    if (averageProgress >= 80) {
        printf("Klasifikimi: Progres i pergjithshem shume i mire.\n");
    } else if (averageProgress >= 50) {
        printf("Klasifikimi: Progres i pergjithshem mesatar.\n");
    } else {
        printf("Klasifikimi: Progres i ulet dhe ka nevoje per permiresim.\n");
    }

    if (completedCount == count) {
        printf("Statusi i grupit: Te gjitha regjistrimet jane te perfunduara.\n");
    } else if (completedCount > 0) {
        printf("Statusi i grupit: Disa regjistrime jane perfunduar.\n");
    } else {
        printf("Statusi i grupit: Asnje regjistrim nuk eshte perfunduar ende.\n");
    }
}

void searchRecords(StudentRecord records[], int count) {
    int choice;
    int i;
    int found = 0;
    int searchId;
    char searchName[NAME_LENGTH];

    if (count == 0) {
        printf("\nNuk ka regjistrime per kerkim.\n");
        return;
    }

    printf("\nKerkim i regjistrimeve\n");
    printf("1. Kerko sipas ID-se\n");
    printf("2. Kerko sipas emrit\n");
    printf("Zgjedhja: ");

    if (scanf("%d", &choice) != 1) {
        clearInputBuffer();
        printf("Zgjedhje e pavlefshme per kerkim.\n");
        return;
    }

    switch (choice) {
        case 1:
            printf("Vendos ID-ne: ");
            if (scanf("%d", &searchId) != 1) {
                clearInputBuffer();
                printf("ID e pavlefshme.\n");
                return;
            }

            printf("\nRezultatet e kerkimit:\n");
            printf("--------------------------------------------------\n");

            for (i = 0; i < count; i++) {
                if (records[i].id == searchId) {
                    printSingleRecord(records[i]);
                    showRecordEvaluation(records[i]);
                    printf("--------------------------------------------------\n");
                    found = 1;
                }
            }
            break;

        case 2:
            clearInputBuffer();
            printf("Vendos emrin ose nje pjese te emrit: ");
            if (fgets(searchName, NAME_LENGTH, stdin) == NULL) {
                printf("Gabim gjate leximit te emrit.\n");
                return;
            }

            searchName[strcspn(searchName, "\n")] = '\0';

            if (strlen(searchName) == 0) {
                printf("Teksti i kerkimit nuk mund te jete bosh.\n");
                return;
            }

            printf("\nRezultatet e kerkimit:\n");
            printf("--------------------------------------------------\n");

            for (i = 0; i < count; i++) {
                if (containsIgnoreCase(records[i].name, searchName)) {
                    printSingleRecord(records[i]);
                    showRecordEvaluation(records[i]);
                    printf("--------------------------------------------------\n");
                    found = 1;
                }
            }
            break;

        default:
            printf("Opsion i pavlefshem ne kerkim.\n");
            return;
    }

    if (!found) {
        printf("Nuk u gjet asnje regjistrim qe perputhet me kerkimin.\n");
    }
}

void showMenu(void) {
    printf("\n===== Student Progress Tracker =====\n");
    printf("1. Shto regjistrim\n");
    printf("2. Shfaq te gjitha regjistrimet\n");
    printf("3. Shfaq raportin\n");
    printf("4. Kerko regjistrim\n");
    printf("5. Dil\n");
    printf("Zgjedhja juaj: ");
}

int main(void) {
    StudentRecord records[MAX_STUDENTS];
    int count = 0;
    int choice;
    int running = 1;

    while (running) {
        showMenu();

        if (scanf("%d", &choice) != 1) {
            clearInputBuffer();
            printf("Zgjedhje e pavlefshme. Ju lutem vendosni numer.\n");
            continue;
        }

        switch (choice) {
            case 1:
                addStudentRecord(records, &count);
                break;
            case 2:
                showAllRecords(records, count);
                break;
            case 3:
                showReport(records, count);
                break;
            case 4:
                searchRecords(records, count);
                break;
            case 5:
                running = 0;
                printf("Programi u mbyll.\n");
                break;
            default:
                printf("Opsion i pavlefshem ne menu. Provo perseri.\n");
                break;
        }
    }

    return 0;
}
