#include <stdio.h>

float computeAverage(float scores[]) {
    return (scores[0] + scores[1] + scores[2]) / 3;
}

char getLetterGrade(float average) {
    if (average >= 90)
        return 'A';
    else if (average >= 80)
        return 'B';
    else if (average >= 70)
        return 'C';
    else if (average >= 60)
        return 'D';
    else
        return 'F';
}

int main() {

    char continueChoice;
    int studentCount = 0;

    do {

        char studentName[50];
        int studentID;
        float scores[3];
        float average;
        char letterGrade;

        const char *examNames[3] = {
            "Prelim",
            "Midterm",
            "Finals"
        };

        studentCount++;

        printf("\n=== Student #%d ===\n", studentCount);

        getchar();

        printf("Enter student name: ");
        fgets(studentName, sizeof(studentName), stdin);

        printf("Enter student ID: ");
        scanf("%d", &studentID);

        for (int i = 0; i < 3; i++) {

            int valid = 0;

            while (!valid) {

                printf("Enter %s score: ",
                       examNames[i]);

                scanf("%f", &scores[i]);

                if (scores[i] >= 0 &&
                    scores[i] <= 100)
                    valid = 1;
                else
                    printf("Invalid score.\n");
            }
        }

        average = computeAverage(scores);
        letterGrade = getLetterGrade(average);

        printf("\nAverage: %.2f\n", average);
        printf("Letter Grade: %c\n", letterGrade);

        if (average >= 75)
            printf("Remarks: PASSED\n");
        else
            printf("Remarks: FAILED\n");

        printf("\nProcess another student? (y/n): ");
        scanf(" %c", &continueChoice);

    } while (continueChoice == 'y' ||
             continueChoice == 'Y');

    printf("\nTotal Students Processed: %d\n",
           studentCount);

    return 0;
}