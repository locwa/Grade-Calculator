#include <stdio.h>

int main() {
    char studentName[50];
    int studentID;
    float prelim, midterm, finals, average;

    printf("=== STUDENT GRADE CALCULATOR ===\n");

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

    average = (prelim + midterm + finals) / 3;

    printf("\n=== GRADE REPORT ===\n");
    printf("Name: %s", studentName);
    printf("Student ID: %d\n", studentID);
    printf("Average: %.2f\n", average);

    if (average >= 75)
        printf("Remarks: PASSED\n");
    else
        printf("Remarks: FAILED\n");

    return 0;
}