#include <stdio.h>
#include <string.h>

#define MAX_RECORDS 5
#define NAME_LENGTH 50

typedef enum
{
    NOT_STARTED = 1,
    IN_PROGRESS,
    COMPLETED
} Status;

typedef struct
{
    int id;
    char name[NAME_LENGTH];
    int progress;
    Status status;
} StudentRecord;

void clearInputBuffer()
{
    while (getchar() != '\n');
}

void getStatusText(Status status, char text[])
{
    switch (status)
    {
        case NOT_STARTED:
            strcpy(text, "Not Started");
            break;
        case IN_PROGRESS:
            strcpy(text, "In Progress");
            break;
        case COMPLETED:
            strcpy(text, "Completed");
            break;
        default:
            strcpy(text, "Unknown");
    }
}

void showMenu()
{
    printf("\n===== Task 2 - Student Progress Tracker =====\n");
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
    int statusChoice;
    char statusText[20];

    do
    {
        showMenu();

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid menu input.\n");
            clearInputBuffer();
            continue;
        }
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

                    printf("Choose Status:\n");
                    printf("1. Not Started\n");
                    printf("2. In Progress\n");
                    printf("3. Completed\n");
                    printf("Enter choice: ");

                    if (scanf("%d", &statusChoice) != 1)
                    {
                        printf("Invalid status input.\n");
                        clearInputBuffer();
                        break;
                    }
                    clearInputBuffer();

                    switch (statusChoice)
                    {
                        case 1:
                            records[count].status = NOT_STARTED;
                            break;
                        case 2:
                            records[count].status = IN_PROGRESS;
                            break;
                        case 3:
                            records[count].status = COMPLETED;
                            break;
                        default:
                            printf("Invalid status choice.\n");
                            break;
                    }

                    if (statusChoice >= 1 && statusChoice <= 3)
                    {
                        count++;
                        printf("Record added successfully.\n");
                    }
                }
                break;

            case 2:
                if (count == 0)
                {
                    printf("No records available.\n");
                }
                else
                {
                    for (int i = 0; i < count; i++)
                    {
                        getStatusText(records[i].status, statusText);
                        printf("\nRecord %d\n", i + 1);
                        printf("ID: %d\n", records[i].id);
                        printf("Name: %s\n", records[i].name);
                        printf("Progress: %d\n", records[i].progress);
                        printf("Status: %s\n", statusText);
                    }
                }
                break;

            case 3:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid menu choice.\n");
        }

    } while (choice != 3);

    return 0;
}
