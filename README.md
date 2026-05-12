# Grade Calculator Programs

This repository contains two C programs for calculating student grades:

## Programs

### 1. `grade_calculator.c`
A simple console-based program that computes a student's final grade from three exam scores (prelim, midterm, finals). It determines the letter grade and pass/fail status, then displays a formatted report.

**Features:**
- Input validation for scores (0-100)
- Computes average and letter grade
- Displays detailed grade report
- Processes multiple students in a loop
- Shows total students processed

### 2. `grade_calc_BetterVersion.c`
A student record management system that allows adding, viewing, searching, and displaying statistics for multiple students.

**Features:**
- Add student records with ID, name, and exam scores
- View all student records
- Search student by ID
- Display class statistics (average, highest/lowest, pass/fail counts)
- Input validation
- Stores up to 100 students

## Requirements
- C compiler (e.g., GCC)
- Standard C libraries: `<stdio.h>`, `<string.h>`, `<stdbool.h>`

## Compilation
Compile each program separately using a C compiler:

```bash
gcc grade_calculator.c -o grade_calculator
gcc grade_calc_BetterVersion.c -o grade_calc_BetterVersion
```

## Running
Execute the compiled programs:

```bash
./grade_calculator
./grade_calc_BetterVersion
```

Follow the on-screen prompts to input data.

## Usage Examples

### grade_calculator.c
- Enter student name and ID
- Input prelim, midterm, and finals scores
- View the grade report
- Choose to process another student

### grade_calc_BetterVersion.c
- Select menu options (1-5)
- Add students with details
- View all records or search by ID
- See class statistics

## Concepts Demonstrated
- Data types (int, float, char, arrays, structs)
- Control structures (loops, conditionals)
- Functions and modularity
- Input validation
- Boolean logic
- Arrays and structures
- Pointers (in BetterVersion)

## Technical Details

### Data Types Used
- **int**: For student IDs, counters, and loop indices
- **float**: For exam scores and averages
- **char**: For letter grades and single characters
- **bool**: For pass/fail status (in grade_calc_BetterVersion.c)
- **char arrays**: For student names (strings)

### Structures
- **Student** (in grade_calc_BetterVersion.c): A struct containing:
  - `int studentID`
  - `char studentName[MAX_NAME_LENGTH]`
  - `float prelim, midterm, finals`
  - `float average`
  - `char letterGrade`
  - `bool isPassing`

### Constants
- `MAX_STUDENTS`: 100 (limit for student records)
- `MAX_NAME_LENGTH`: 60 (max characters for names)
- `NUM_EXAMS`: 3 (number of exams)
- `PASSING_GRADE`: 75.0f (threshold for passing)

### Control Structures
- Loops: for, while, do-while
- Conditionals: if-else, switch-case
- Input validation loops

### Operators
- Arithmetic: +, -, *, /
- Relational: >, <, >=, <=, ==
- Logical: &&, ||, !
- Assignment: =, +=, ++

### Functions
- Modular design with separate functions for menu, adding students, displaying, etc.
- Function prototypes declared at the top
This code is for educational purposes.