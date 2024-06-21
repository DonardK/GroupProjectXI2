#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "addCourse.h"
#include "deleteCourse.h"
#include "searchCourseByCode.h"
#include "displayAllCourses.h"
#include "searchCourseByName.h"

#include "course.h"
//after all the functions are added in course_management.h then you cant uncomment the row above this comment

void displayMenu() {
    printf("\nCourse Management System\n");
    printf("1. Add Course\n");
    printf("2. Delete Course\n");
    printf("3. Search Course by Code\n");
    printf("4. Search Course by Name\n");
    printf("5. Display All Courses\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    Course* head = NULL;
    int choice, courseID, credits;
    char courseName[100];
    Course* result;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Course ID: ");
                scanf("%d", &courseID);
                printf("Enter Course Name: ");
                scanf("%s", courseName);
                printf("Enter Credits: ");
                scanf("%d", &credits);
                addCourse(&head, courseID, courseName, credits);
                break;
            case 2:
                printf("Enter Course ID to delete: ");
                scanf("%d", &courseID);
                deleteCourse(&head, courseID);
                break;
            case 3:
                printf("Enter Course ID to search: ");
                scanf("%d", &courseID);
                result = searchCourseByCode(head, courseID);
                if (result != NULL) {
                    printf("Course found: ID: %d, Name: %s, Credits: %d\n", result->courseID, result->courseName, result->credits);
                } else {
                    printf("Course not found.\n");
                }
                break;
            case 4:
                printf("Enter Course Name to search: ");
                scanf("%s", courseName);
                result = searchCourseByName(head, courseName);
                if (result != NULL) {
                    printf("Course found: ID: %d, Name: %s, Credits: %d\n", result->courseID, result->courseName, result->credits);
                } else {
                    printf("Course not found.\n");
                }
                break;
            case 5:
                displayAllCourses(head);
                break;
            case 6:
                freeCourses(head);
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
