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

void printDivider(void) {
    printf("--------------------------------------------------\n");
}

void printSectionTitle(const char title[]) {
    printf("\n");
    printDivider();
    printf("%s\n", title);
    printDivider();
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

int readIntInRange(const char prompt[], int min, int max, int *value) {
    printf("%s", prompt);

    if (scanf("%d", value) != 1) {
        clearInputBuffer();
        printf("Input i pavlefshem. Duhet numer.\n");
        return 0;
    }

    if (*value < min || *value > max) {
        printf("Vlera duhet te jete nga %d deri ne %d.\n", min, max);
        return 0;
    }

    return 1;
}

int readLine(const char prompt[], char text[], int size) {
    printf("%s", prompt);

    if (fgets(text, size, stdin) == NULL) {
        printf("Gabim gjate leximit te tekstit.\n");
        return 0;
    }

    text[strcspn(text, "\n")] = '\0';

    if (strlen(text) == 0) {
        printf("Teksti nuk mund te jete bosh.\n");
        return 0;
    }

    return 1;
}

int readStatus(Status *status) {
    int choice;

    printf("Zgjidh statusin:\n");
    printf("1. Not Started\n");
    printf("2. In Progress\n");
    printf("3. Completed\n");

    if (!readIntInRange("Zgjedhja: ", 1, 3, &choice)) {
        printf("Status i pavlefshem.\n");
        return 0;
    }

    *status = (Status)choice;
    return 1;
}

void printSingleRecord(StudentRecord record) {
    printf("ID: %d\n", record.id);
    printf("Emri: %s\n", record.name);
    printf("Progresi: %d\n", record.progress);
    printf("Statusi: %s\n", statusToText(record.status));
}

void printRecordWithIndex(StudentRecord record, int index) {
    printf("Regjistrimi %d\n", index + 1);
    printSingleRecord(record);
    printDivider();
}

int containsIgnoreCase(const char text[], const char search[]) {
    int i;
    int j;

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

int idExists(StudentRecord records[], int count, int id, StudentRecord *ignoreRecord) {
    int i;

    for (i = 0; i < count; i++) {
        if (&records[i] != ignoreRecord && records[i].id == id) {
            return 1;
        }
    }

    return 0;
}

StudentRecord* findRecordById(StudentRecord records[], int count, int id) {
    int i;

    for (i = 0; i < count; i++) {
        if (records[i].id == id) {
            return &records[i];
        }
    }

    return NULL;
}

int findRecordIndexById(StudentRecord records[], int count, int id) {
    int i;

    for (i = 0; i < count; i++) {
        if (records[i].id == id) {
            return i;
        }
    }

    return -1;
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

int addStudentRecord(StudentRecord records[], int *count) {
    StudentRecord newRecord;

    if (*count >= MAX_STUDENTS) {
        printf("Nuk mund te shtohen me regjistrime. U arrit maksimumi prej %d.\n", MAX_STUDENTS);
        return 0;
    }

    printSectionTitle("Shto Regjistrim Te Ri");

    if (!readIntInRange("ID: ", 1, 99999, &newRecord.id)) {
        return 0;
    }

    if (idExists(records, *count, newRecord.id, NULL)) {
        printf("Ky ID ekziston tashme.\n");
        return 0;
    }

    clearInputBuffer();

    if (!readLine("Emri: ", newRecord.name, NAME_LENGTH)) {
        return 0;
    }

    if (!readIntInRange("Progresi ose rezultati (0 - 100): ", 0, 100, &newRecord.progress)) {
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

void updateRecordByPointer(StudentRecord *record, StudentRecord records[], int count) {
    int newId;
    int newProgress;
    Status newStatus;
    char newName[NAME_LENGTH];

    printSectionTitle("Perditeso Regjistrim");
    printf("Gjendja aktuale:\n");
    printSingleRecord(*record);
    printDivider();

    if (!readIntInRange("ID i ri: ", 1, 99999, &newId)) {
        return;
    }

    if (idExists(records, count, newId, record)) {
        printf("Ekziston nje regjistrim tjeter me kete ID.\n");
        return;
    }

    clearInputBuffer();

    if (!readLine("Emri i ri: ", newName, NAME_LENGTH)) {
        return;
    }

    if (!readIntInRange("Progresi i ri (0 - 100): ", 0, 100, &newProgress)) {
        return;
    }

    if (!readStatus(&newStatus)) {
        return;
    }

    record->id = newId;
    strcpy(record->name, newName);
    record->progress = newProgress;
    record->status = newStatus;

    printf("Regjistrimi u perditesua me sukses.\n");
    printf("Gjendja e re:\n");
    printSingleRecord(*record);
}

void updateRecord(StudentRecord records[], int count) {
    int id;
    StudentRecord *record;

    if (count == 0) {
        printf("\nNuk ka regjistrime per perditesim.\n");
        return;
    }

    printSectionTitle("Perditeso Regjistrim Sipas ID-se");

    if (!readIntInRange("Vendos ID-ne: ", 1, 99999, &id)) {
        return;
    }

    record = findRecordById(records, count, id);

    if (record == NULL) {
        printf("Nuk u gjet regjistrim me kete ID.\n");
        return;
    }

    updateRecordByPointer(record, records, count);
}

void deleteRecord(StudentRecord records[], int *count) {
    int id;
    int index;
    int i;

    if (*count == 0) {
        printf("\nNuk ka regjistrime per fshirje.\n");
        return;
    }

    printSectionTitle("Fshi Regjistrim Sipas ID-se");

    if (!readIntInRange("Vendos ID-ne: ", 1, 99999, &id)) {
        return;
    }

    index = findRecordIndexById(records, *count, id);

    if (index == -1) {
        printf("Nuk u gjet regjistrim me kete ID.\n");
        return;
    }

    printf("Do te fshihet:\n");
    printSingleRecord(records[index]);
    printDivider();

    for (i = index; i < *count - 1; i++) {
        records[i] = records[i + 1];
    }

    (*count)--;
    printf("Regjistrimi u fshi me sukses.\n");
    printf("Numri aktual i regjistrimeve: %d\n", *count);
}

void showAllRecords(StudentRecord records[], int count) {
    int i;

    if (count == 0) {
        printf("\nNuk ka regjistrime te ruajtura.\n");
        return;
    }

    printSectionTitle("Lista E Regjistrimeve");

    for (i = 0; i < count; i++) {
        printRecordWithIndex(records[i], i);
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
        }

        if (records[i].progress < lowestProgress) {
            lowestProgress = records[i].progress;
        }
    }

    averageProgress = (double)sumProgress / count;

    printSectionTitle("Raport Analitik");
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

void showRanking(StudentRecord records[], int count) {
    StudentRecord sortedRecords[MAX_STUDENTS];
    StudentRecord temp;
    int i;
    int j;

    if (count == 0) {
        printf("\nNuk ka regjistrime per renditje.\n");
        return;
    }

    for (i = 0; i < count; i++) {
        sortedRecords[i] = records[i];
    }

    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - 1 - i; j++) {
            if (sortedRecords[j].progress < sortedRecords[j + 1].progress) {
                temp = sortedRecords[j];
                sortedRecords[j] = sortedRecords[j + 1];
                sortedRecords[j + 1] = temp;
            }
        }
    }

    printSectionTitle("Renditja Sipas Progresit");

    for (i = 0; i < count; i++) {
        printf("Rangu %d\n", i + 1);
        printSingleRecord(sortedRecords[i]);
        printDivider();
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

    printSectionTitle("Kerkim I Regjistrimeve");
    printf("1. Kerko sipas ID-se\n");
    printf("2. Kerko sipas emrit\n");

    if (!readIntInRange("Zgjedhja: ", 1, 2, &choice)) {
        printf("Zgjedhje e pavlefshme per kerkim.\n");
        return;
    }

    if (choice == 1) {
        if (!readIntInRange("Vendos ID-ne: ", 1, 99999, &searchId)) {
            return;
        }

        printDivider();

        for (i = 0; i < count; i++) {
            if (records[i].id == searchId) {
                printSingleRecord(records[i]);
                showRecordEvaluation(records[i]);
                printDivider();
                found = 1;
            }
        }
    } else {
        clearInputBuffer();

        if (!readLine("Vendos emrin ose nje pjese te emrit: ", searchName, NAME_LENGTH)) {
            return;
        }

        printDivider();

        for (i = 0; i < count; i++) {
            if (containsIgnoreCase(records[i].name, searchName)) {
                printSingleRecord(records[i]);
                showRecordEvaluation(records[i]);
                printDivider();
                found = 1;
            }
        }
    }

    if (!found) {
        printf("Nuk u gjet asnje regjistrim qe perputhet me kerkimin.\n");
    }
}

void showMenu(void) {
    printSectionTitle("Student Progress Tracker");
    printf("1. Shto regjistrim\n");
    printf("2. Shfaq te gjitha regjistrimet\n");
    printf("3. Shfaq raportin\n");
    printf("4. Perditeso regjistrim\n");
    printf("5. Fshi regjistrim\n");
    printf("6. Kerko regjistrim\n");
    printf("7. Rendit sipas progresit\n");
    printf("8. Dil\n");
}

int main(void) {
    StudentRecord records[MAX_STUDENTS];
    int count = 0;
    int choice;
    int running = 1;

    while (running) {
        showMenu();

        if (!readIntInRange("Zgjedhja juaj: ", 1, 8, &choice)) {
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
                updateRecord(records, count);
                break;
            case 5:
                deleteRecord(records, &count);
                break;
            case 6:
                searchRecords(records, count);
                break;
            case 7:
                showRanking(records, count);
                break;
            case 8:
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
