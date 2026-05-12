/*
 * ============================================================
 *  STUDENT RECORD MANAGEMENT SYSTEM
 *  Programming Language: C
 *
 *  Features:
 *  - Add Student Records
 *  - View All Students
 *  - Search Student by ID
 *  - Display Class Statistics
 *
 *  Concepts Demonstrated:
 *  - Data Types
 *  - Operators
 *  - Control Structures
 *  - Functions/Subprograms
 *  - Arrays
 *  - Structures
 *  - Boolean Values
 *  - Input Validation
 * ============================================================
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/* ===================== CONSTANTS ====================== */
#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 60
#define NUM_EXAMS 3
#define PASSING_GRADE 75.0f

/* ===================== STRUCTURE ====================== */
typedef struct {
    int studentID;
    char studentName[MAX_NAME_LENGTH];

    float prelim;
    float midterm;
    float finals;

    float average;
    char letterGrade;

    bool isPassing;
} Student;

/* ================= FUNCTION PROTOTYPES ================= */

void showMenu();
void addStudent(Student students[], int *count);
void displayStudents(Student students[], int count);
void searchStudent(Student students[], int count);
void showStatistics(Student students[], int count);

float getValidatedScore(const char examName[]);
float computeAverage(float scores[], int size);
char getLetterGrade(float average);

/* ===================== MAIN FUNCTION ===================== */

int main()
{
    // Store student records in an array.
    Student students[MAX_STUDENTS];

    // Count of students currently stored.
    int studentCount = 0;
    int choice;

    do {
        showMenu();

        printf("Enter choice: ");

        // Validate menu selection is an integer.
        while (scanf("%d", &choice) != 1) {
            printf("Invalid input. Enter a number: ");

            while (getchar() != '\n');
        }

        // Clear any remaining characters from the input buffer.
        while (getchar() != '\n');

        switch (choice) {

            case 1:
                addStudent(students, &studentCount);
                break;

            case 2:
                displayStudents(students, studentCount);
                break;

            case 3:
                searchStudent(students, studentCount);
                break;

            case 4:
                showStatistics(students, studentCount);
                break;

            case 5:
                printf("\nExiting program...\n");
                break;

            default:
                printf("\nInvalid choice.\n");
        }

    } while (choice != 5);

    return 0;
}

/* ===================== MENU FUNCTION ===================== */

// Display the main menu options for the user.
void showMenu()
{
    printf("\n");
    printf("====================================================\n");
    printf("         STUDENT RECORD MANAGEMENT SYSTEM\n");
    printf("====================================================\n");

    printf("[1] Add Student\n");
    printf("[2] View All Students\n");
    printf("[3] Search Student by ID\n");
    printf("[4] Show Statistics\n");
    printf("[5] Exit\n");

    printf("====================================================\n");
}

/* ===================== ADD STUDENT ===================== */

// Collect student details, validate input, compute grades, and save the record.

void addStudent(Student students[], int *count)
{
    if (*count >= MAX_STUDENTS) {
        printf("\nStudent limit reached.\n");
        return;
    }

    Student newStudent;

    printf("\n===== ADD STUDENT =====\n");

    /* Student Name */
    printf("Enter student name: ");
    fgets(newStudent.studentName, MAX_NAME_LENGTH, stdin);

    int length = strlen(newStudent.studentName);

    if (length > 0 &&
        newStudent.studentName[length - 1] == '\n') {

        newStudent.studentName[length - 1] = '\0';
    }

    /* Student ID */
    printf("Enter student ID: ");

    while (scanf("%d", &newStudent.studentID) != 1) {
        printf("Invalid input. Enter a valid ID: ");
        while (getchar() != '\n');
    }

    // Flush newline after the ID input.
    while (getchar() != '\n');

    /* Scores */
    newStudent.prelim = getValidatedScore("Prelim");
    newStudent.midterm = getValidatedScore("Midterm");
    newStudent.finals = getValidatedScore("Finals");

    /* Array of scores used for average computation. */
    float scores[NUM_EXAMS] = {
        newStudent.prelim,
        newStudent.midterm,
        newStudent.finals
    };

    /* Compute average score from the exam results. */
    newStudent.average =
        computeAverage(scores, NUM_EXAMS);

    /* Determine letter grade based on average. */
    newStudent.letterGrade =
        getLetterGrade(newStudent.average);

    /* Determine pass/fail using passing grade threshold. */
    newStudent.isPassing =
        (newStudent.average >= PASSING_GRADE)
        && (newStudent.letterGrade != 'F');

    /* Store student */
    students[*count] = newStudent;

    (*count)++;

    printf("\nStudent successfully added.\n");
}

/* ===================== DISPLAY STUDENTS ===================== */

// Print all stored student records with their scores and grades.
void displayStudents(Student students[], int count)
{
    if (count == 0) {
        printf("\nNo student records found.\n");
        return;
    }

    printf("\n================ STUDENT RECORDS ================\n");

    for (int i = 0; i < count; i++) {

        printf("\nStudent #%d\n", i + 1);

        printf("-------------------------------------------------\n");

        printf("Name         : %s\n",
               students[i].studentName);

        printf("Student ID   : %d\n",
               students[i].studentID);

        printf("Prelim       : %.2f\n",
               students[i].prelim);

        printf("Midterm      : %.2f\n",
               students[i].midterm);

        printf("Finals       : %.2f\n",
               students[i].finals);

        printf("Average      : %.2f\n",
               students[i].average);

        printf("Letter Grade : %c\n",
               students[i].letterGrade);

        printf("Remarks      : %s\n",
               students[i].isPassing
               ? "PASSED"
               : "FAILED");
    }
}

/* ===================== SEARCH STUDENT ===================== */

// Find a student record by student ID and display the result.
void searchStudent(Student students[], int count)
{
    if (count == 0) {
        printf("\nNo student records available.\n");
        return;
    }

    int searchID;
    bool found = false;

    printf("\nEnter student ID to search: ");

    while (scanf("%d", &searchID) != 1) {

        printf("Invalid input. Enter valid ID: ");

        while (getchar() != '\n');
    }

    while (getchar() != '\n');

    for (int i = 0; i < count; i++) {

        if (students[i].studentID == searchID) {

            found = true;

            printf("\n===== STUDENT FOUND =====\n");

            printf("Name         : %s\n",
                   students[i].studentName);

            printf("Student ID   : %d\n",
                   students[i].studentID);

            printf("Average      : %.2f\n",
                   students[i].average);

            printf("Letter Grade : %c\n",
                   students[i].letterGrade);

            printf("Remarks      : %s\n",
                   students[i].isPassing
                   ? "PASSED"
                   : "FAILED");

            break;
        }
    }

    if (!found) {
        printf("\nStudent not found.\n");
    }
}

/* ===================== SHOW STATISTICS ===================== */

// Calculate and display class statistics for all stored students.
void showStatistics(Student students[], int count)
{
    if (count == 0) {
        printf("\nNo student records available.\n");
        return;
    }

    float highest = students[0].average;
    float lowest = students[0].average;

    float totalAverage = 0.0f;

    int passed = 0;
    int failed = 0;

    for (int i = 0; i < count; i++) {

        totalAverage += students[i].average;

        if (students[i].average > highest) {
            highest = students[i].average;
        }

        if (students[i].average < lowest) {
            lowest = students[i].average;
        }

        if (students[i].isPassing) {
            passed++;
        } else {
            failed++;
        }
    }

    float classAverage = totalAverage / count;

    printf("\n============= CLASS STATISTICS =============\n");

    printf("Total Students : %d\n", count);

    printf("Class Average  : %.2f\n",
           classAverage);

    printf("Highest Grade  : %.2f\n",
           highest);

    printf("Lowest Grade   : %.2f\n",
           lowest);

    printf("Passed         : %d\n",
           passed);

    printf("Failed         : %d\n",
           failed);

    if (count % 2 == 0) {
        printf("Student count is EVEN.\n");
    } else {
        printf("Student count is ODD.\n");
    }
}

/* ===================== VALIDATED SCORE ===================== */

// Read and validate a numeric exam score between 0 and 100.
float getValidatedScore(const char examName[])
{
    float score;

    while (1) {
        printf("Enter %s score: ", examName);

        if (scanf("%f", &score) != 1) {
            printf("Invalid input.\n");
            while (getchar() != '\n');
            continue;
        }

        // Clear the input line after reading the score.
        while (getchar() != '\n');

        if (score >= 0.0f && score <= 100.0f) {
            return score;
        }

        printf("Score must be between 0 and 100.\n");
    }
}

/* ===================== COMPUTE AVERAGE ===================== */

// Sum the exam scores and return the average.
float computeAverage(float scores[], int size)
{
    float total = 0.0f;

    for (int i = 0; i < size; i++) {
        total += scores[i];
    }

    return total / size;
}

/* ===================== LETTER GRADE ===================== */

// Convert the numeric average into a standard letter grade.
char getLetterGrade(float average)
{
    if (average >= 90.0f) {
        return 'A';
    }
    else if (average >= 80.0f) {
        return 'B';
    }
    else if (average >= 70.0f) {
        return 'C';
    }
    else if (average >= 60.0f) {
        return 'D';
    }
    else {
        return 'F';
    }
}