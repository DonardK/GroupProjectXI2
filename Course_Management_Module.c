#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "course.h"
#include "addCourse.h"
#include "deleteCourse.h"
#include "searchCourseByCode.h"
#include "displayAllCourses.h"
#include "searchCourseByName.h"
#include "freeCourses.h"

void displayMenu()
{
    printf("\nCourse Management System\n");
    printf("1. Add Course\n");
    printf("2. Delete Course\n");
    printf("3. Search Course by Code\n");
    printf("4. Search Course by Name\n");
    printf("5. Display All Courses\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

void handleMenuChoice(int choice, Course** head)
{
    char courseID[20], courseName[100];
    int credits;
    Course* result;

    switch (choice)
    {
    case 1:
        printf("Enter Course ID: ");
        scanf("%s", courseID);
        while (getchar() != '\n'); // Clear the newline character from the buffer
        printf("Enter Course Name: ");
        fgets(courseName, sizeof(courseName), stdin);
        courseName[strcspn(courseName, "\n")] = '\0'; // Remove the newline character from the input

        printf("Enter Credits: ");
        scanf("%d", &credits);

        addCourse(head, courseID, courseName, credits);
        break;

    case 2:
        printf("Enter Course ID to delete: ");
        scanf("%s", courseID);
        deleteCourse(head, courseID);
        break;
    case 3:
        printf("Enter Course ID to search: ");
        scanf("%s", courseID);
        result = searchCourseByCode(*head, courseID);
        if (result != NULL)
        {
            printf("Course found: ID: %s, Name: %s, Credits: %d\n", result->courseID, result->courseName, result->credits);
        }
        else
        {
            printf("Course not found.\n");
        }
        break;
    case 4:
        printf("Enter Course Name to search: ");
        scanf("%s", courseName);
        result = searchCourseByName(*head, courseName);
        if (result != NULL)
        {
            printf("Course found: ID: %s, Name: %s, Credits: %d\n", result->courseID, result->courseName, result->credits);
        }
        else
        {
            printf("Course not found.\n");
        }
        break;
    case 5:
        displayAllCourses(*head);
        break;
    case 6:
        freeCourses(*head);
        exit(0);
        break;
    default:
        printf("Invalid choice. Please try again.\n");
    }
}

int main()
{
    Course* head = NULL;
    int choice;

    while (1)
    {
        displayMenu();
        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear the invalid input from the buffer
            continue;
        }
        handleMenuChoice(choice, &head);
    }

    return 0;
}
