#include <stdio.h>
#include <string.h>

#define MAX_RECORDS 5
#define NAME_LENGTH 50

typedef struct
{
    int id;
    char name[NAME_LENGTH];
    int progress;
    char status[20];
} StudentRecord;

void clearInputBuffer()
{
    while (getchar() != '\n');
}

void showMenu()
{
    printf("\n===== Task 1 - Student Progress Tracker =====\n");
    printf("1. Add record\n");
    printf("2. Show all records\n");
    printf("3. Exit\n");
    printf("Choose: ");
}

int main()
{
    StudentRecord records[MAX_RECORDS];
    int count = 0;
    int choice;

    do
    {
        showMenu();
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice)
        {
            case 1:
                if (count >= MAX_RECORDS)
                {
                    printf("Maximum number of records reached.\n");
                }
                else
                {
                    printf("Enter ID: ");
                    scanf("%d", &records[count].id);
                    clearInputBuffer();

                    printf("Enter Name: ");
                    fgets(records[count].name, NAME_LENGTH, stdin);
                    records[count].name[strcspn(records[count].name, "\n")] = '\0';

                    printf("Enter Progress (0-100): ");
                    scanf("%d", &records[count].progress);
                    clearInputBuffer();

                    printf("Enter Status: ");
                    fgets(records[count].status, 20, stdin);
                    records[count].status[strcspn(records[count].status, "\n")] = '\0';

                    count++;
                    printf("Record added successfully.\n");
                }
                break;

            case 2:
                if (count == 0)
                {
                    printf("No records available.\n");
                }
                else
                {
                    printf("\nAll Saved Records:\n");
                    for (int i = 0; i < count; i++)
                    {
                        printf("\nRecord %d\n", i + 1);
                        printf("ID: %d\n", records[i].id);
                        printf("Name: %s\n", records[i].name);
                        printf("Progress: %d\n", records[i].progress);
                        printf("Status: %s\n", records[i].status);
                    }
                }
                break;

            case 3:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 3);

    return 0;
}