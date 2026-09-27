#include <stdio.h>

int main() {
    int theory, pract, att, depart, passed;

    printf("Enter your department\n");
    printf("1: Computer Science\n");
    printf("2: Electrical Engineering\n");
    printf("3: Business Administration\n");
    printf("4: Mathematics\n");
    scanf("%d", &depart);

    printf("Enter your theory marks\n");
    scanf("%d", &theory);

    printf("Enter your practical marks\n");
    scanf("%d", &pract);

    printf("Enter your attendance percentage\n");
    scanf("%d", &att);

    switch (depart) {
        case 1:
            printf("\nDepartment: Computer Science\n");
            printf("Passing Requirements: Theory 50, Practical 40, Attendance 75%%\n");
            passed = (theory >= 50 && pract >= 40 && att >= 75);
            break;
        case 2:
            printf("\nDepartment: Electrical Engineering\n");
            printf("Passing Requirements: Theory 55, Practical 45, Attendance 75%%\n");
            passed = (theory >= 55 && pract >= 45 && att >= 75);
            break;
        case 3:
            printf("\nDepartment: Business Administration\n");
            printf("Passing Requirements: Theory 50, Practical 35, Attendance 80%%\n");
            passed = (theory >= 50 && pract >= 35 && att >= 80);
            break;
        case 4:
            printf("\nDepartment: Mathematics\n");
            printf("Passing Requirements: Theory 60, Practical 40, Attendance 75%%\n");
            passed = (theory >= 60 && pract >= 40 && att >= 75);
            break;
        default:
            printf("Invalid department\n");
            return 0;
    }

    printf("\nFinal Report\n-------------------------\n");
    printf("Theory Marks: %d\n", theory);
    printf("Practical Marks: %d\n", pract);
    printf("Attendance: %d%%\n", att);

    printf("Distinction: %s\n",
           (theory >= 85 && pract >= 80 && att >= 90)
           ? "Eligible" : "Not Eligible");

    if (theory % 3 == 0)
        printf("Seat Category: A\n");
    else if (theory % 3 == 1)
        printf("Seat Category: B\n");
    else
        printf("Seat Category: C\n");

    printf("Final Result: %s\n", passed ? "Passed" : "Failed");

    return 0;
}
