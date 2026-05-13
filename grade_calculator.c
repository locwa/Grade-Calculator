#include <stdio.h>

float computeAverage(float prelim, float midterm, float finals) {
    return (prelim + midterm + finals) / 3;
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

void displayResult(char name[], int id,
                   float average, char letterGrade) {

    printf("\n=== GRADE REPORT ===\n");
    printf("Name: %s", name);
    printf("Student ID: %d\n", id);
    printf("Average: %.2f\n", average);
    printf("Letter Grade: %c\n", letterGrade);

    if (average >= 75)
        printf("Remarks: PASSED\n");
    else
        printf("Remarks: FAILED\n");
}

int main() {
    char studentName[50];
    int studentID;
    float prelim, midterm, finals, average;
    char letterGrade;

    printf("Enter student name: ");
    fgets(studentName, sizeof(studentName), stdin);

    printf("Enter student ID: ");
    scanf("%d", &studentID);

    printf("Enter Prelim score: ");
    scanf("%f", &prelim);

    printf("Enter Midterm score: ");
    scanf("%f", &midterm);

    printf("Enter Finals score: ");
    scanf("%f", &finals);

    average = computeAverage(prelim, midterm, finals);
    letterGrade = getLetterGrade(average);

    displayResult(studentName, studentID,
                  average, letterGrade);

    return 0;
}