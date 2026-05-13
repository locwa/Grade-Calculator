#include <stdio.h>

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
    char studentName[50];
    int studentID;
    float prelim, midterm, finals, average;
    char letterGrade;

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
    letterGrade = getLetterGrade(average);

    printf("\n=== GRADE REPORT ===\n");
    printf("Name: %s", studentName);
    printf("Student ID: %d\n", studentID);
    printf("Average: %.2f\n", average);
    printf("Letter Grade: %c\n", letterGrade);

    if (average >= 75)
        printf("Remarks: PASSED\n");
    else
        printf("Remarks: FAILED\n");

    return 0;
}