/*
 * ============================================================
 *  Student Grade Calculator
 *  Programming Language: C
 *  Description: A console-based program that computes a
 *  student's final grade from three exam scores, determines
 *  their letter grade and remarks, and displays a summary.
 * ============================================================
 */

#include <stdio.h>
#include <string.h>   /* for strlen() */

/* ── Constants ─────────────────────────────────────────── */
#define MAX_NAME_LENGTH 60
#define PASSING_GRADE   75.0f
#define NUM_EXAMS       3

/* ── Function Prototypes ────────────────────────────────── */
float  computeAverage(float prelim, float midterm, float finals);
char   getLetterGrade(float average);
void   displayResult(char studentName[], int studentID,
                     float prelim, float midterm,
                     float finals, float average,
                     char letterGrade);

/* ===========================================================
 *  computeAverage
 *  Parameters : three float exam scores
 *  Returns    : float — the arithmetic mean of the three scores
 * =========================================================== */
float computeAverage(float prelim, float midterm, float finals)
{
    float total   = prelim + midterm + finals;   /* Arithmetic: addition    */
    float average = total / NUM_EXAMS;           /* Arithmetic: division    */
    return average;
}

/* ===========================================================
 *  getLetterGrade
 *  Parameters : float average score
 *  Returns    : char — letter grade (A / B / C / D / F)
 * =========================================================== */
char getLetterGrade(float average)
{
    /* Selection: if-else chain using relational operators */
    if (average >= 90.0f) {
        return 'A';
    } else if (average >= 80.0f) {
        return 'B';
    } else if (average >= 70.0f) {   /* Relational: >= */
        return 'C';
    } else if (average >= 60.0f) {
        return 'D';
    } else {
        return 'F';
    }
}

/* ===========================================================
 *  displayResult
 *  Parameters : student info, scores, average, letter grade
 *  Returns    : void
 *  Purpose    : prints the formatted grade report
 * =========================================================== */
void displayResult(char studentName[], int studentID,
                   float prelim, float midterm,
                   float finals, float average,
                   char letterGrade)
{
    /* Boolean / logical expression: pass if average >= passing
       AND letter grade is not 'F'                              */
    int isPassing = (average >= PASSING_GRADE) && (letterGrade != 'F');

    printf("\n");
    printf("  ================================================\n");
    printf("           STUDENT GRADE REPORT\n");
    printf("  ================================================\n");
    printf("  Name        : %s\n", studentName);
    printf("  Student ID  : %d\n", studentID);   /* Data type: int */
    printf("  ------------------------------------------------\n");
    printf("  Prelim      : %.2f\n", prelim);
    printf("  Midterm     : %.2f\n", midterm);
    printf("  Finals      : %.2f\n", finals);
    printf("  ------------------------------------------------\n");
    printf("  Average     : %.2f\n", average);   /* Data type: float */
    printf("  Letter Grade: %c\n",  letterGrade);/* Data type: char  */
    printf("  Remarks     : %s\n",
           isPassing ? "PASSED" : "FAILED");     /* Logical result   */
    printf("  ================================================\n");
    printf("\n");
}

/* ===========================================================
 *  main — entry point
 *  Collects data for multiple students using a loop,
 *  then calls the helper functions for computation and display.
 * =========================================================== */
int main(void)
{
    /* Data types: int, float, char, char array (string) */
    int   studentID;
    float prelim, midterm, finals, average;
    char  letterGrade;
    char  studentName[MAX_NAME_LENGTH];
    char  continueChoice;      /* char: user's yes/no answer */
    int   studentCount = 0;    /* Iteration counter */

    printf("\n  ================================================\n");
    printf("       STUDENT GRADE CALCULATOR  (C Language)\n");
    printf("  ================================================\n");

    /* Iteration: do-while loop — runs at least once, repeats
       as long as the user wants to enter another student.     */
    do {
        studentCount++;   /* Assignment + arithmetic: increment */

        printf("\n  --- Student #%d ---\n", studentCount);

        /* Input: student name (string) */
        printf("  Enter student name  : ");
        fgets(studentName, MAX_NAME_LENGTH, stdin);
        /* Strip trailing newline left by fgets */
        int nameLen = (int)strlen(studentName);
        if (nameLen > 0 && studentName[nameLen - 1] == '\n') {
            studentName[nameLen - 1] = '\0';
        }

        /* Input: student ID (integer) */
        printf("  Enter student ID    : ");
        scanf("%d", &studentID);

        /* Iteration: for loop — collects exactly NUM_EXAMS scores
           while validating each input is within 0–100.          */
        float scores[NUM_EXAMS];
        const char *examNames[NUM_EXAMS] = {"Prelim", "Midterm", "Finals"};

        for (int i = 0; i < NUM_EXAMS; i++) {
            float inputScore;
            int   validInput = 0;   /* Boolean flag (int acting as bool) */

            while (!validInput) {   /* While loop for input validation */
                printf("  Enter %s score  : ", examNames[i]);
                scanf("%f", &inputScore);

                /* Logical AND: score must be >= 0 AND <= 100 */
                if (inputScore >= 0.0f && inputScore <= 100.0f) {
                    validInput = 1;         /* Assignment */
                    scores[i] = inputScore; /* Assignment */
                } else {
                    printf("  [!] Score must be between 0 and 100. Try again.\n");
                }
            }
        }

        /* Assign individual named variables from the validated array */
        prelim  = scores[0];
        midterm = scores[1];
        finals  = scores[2];

        /* Call subprograms to compute and display */
        average     = computeAverage(prelim, midterm, finals);  /* returns float */
        letterGrade = getLetterGrade(average);                  /* returns char  */
        displayResult(studentName, studentID,
                      prelim, midterm, finals,
                      average, letterGrade);

        /* Ask user whether to enter another student */
        printf("  Process another student? (y/n): ");
        scanf(" %c", &continueChoice);   /* Space before %c skips whitespace */

        /* Clear the input buffer so fgets works on the next iteration */
        while (getchar() != '\n');

    /* Relational + logical: continue if 'y' or 'Y' */
    } while (continueChoice == 'y' || continueChoice == 'Y');

    /* Summary using arithmetic: modulo to check even/odd count */
    printf("\n  Total students processed : %d\n", studentCount);
    if (studentCount % 2 == 0) {
        printf("  (Even number of students recorded.)\n");
    } else {
        printf("  (Odd number of students recorded.)\n");
    }

    printf("\n  Thank you for using the Grade Calculator!\n\n");
    return 0;
}
