
#include <stdio.h>
#include "addCourse.h"
#include "deleteCourse.h"
#include "displayAllCourses.h"
#include "searchCourseByCode.h"
#include "searchCourseByName.h"
#include "freeCourses.h"
#include "addStudent.h"
#include "deleteStudent.h"
#include "displayallstudents.h"
#include "searchstudent.h"

// Function prototypes
void manageCourses();
void manageStudents();
void displayMainMenu();

int main() {
    int choice;

    while (1) {
        displayMainMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                manageCourses();
                break;
            case 2:
                manageStudents();
                break;
            case 3:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}

void displayMainMenu() {
    printf("\n");
    printf("1. Manage Courses\n");
    printf("2. Manage Students\n");
    printf("3. Exit\n");
}

void manageCourses() {
    // Implement course management options here
    printf("Course management selected.\n");
}

void manageStudents() {
    // Implement student management options here
    printf("Student management selected.\n");
}
