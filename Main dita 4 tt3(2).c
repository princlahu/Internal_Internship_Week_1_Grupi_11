void showReport(struct Student students[], int count) {

    if (count == 0) {
        printf("Nuk ka te dhena per raport.\n");
        return;
    }

    int completed = 0;
    float sum = 0;
    float max = students[0].progress;
    float min = students[0].progress;

    for (int i = 0; i < count; i++) {

        sum += students[i].progress;

        if (students[i].status == COMPLETED) {
            completed++;
        }

        if (students[i].progress > max) {
            max = students[i].progress;
        }

        if (students[i].progress < min) {
            min = students[i].progress;
        }
    }

    float avg = sum / count;

    printf("\n--- REPORT ---\n");
    printf("Total Students: %d\n", count);
    printf("Completed: %d\n", completed);
    printf("Average Progress: %.2f\n", avg);
    printf("Max Progress: %.2f\n", max);
    printf("Min Progress: %.2f\n", min);

    // ANALIZA me if/else
    if (avg >= 75) {
        printf("Performance: Shume e mire\n");
    } else if (avg >= 50) {
        printf("Performance: Mesatare\n");
    } else {
        printf("Performance: E ulet\n");
    }
}