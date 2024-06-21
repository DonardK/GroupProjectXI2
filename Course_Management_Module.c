#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "addCourse.h"
#include "deleteCourse.h"
#include "searchCourseByCode.h"
#include "displayAllCourses.h"
#include "searchCourseByName.h"

int main() {
    Course* head = NULL; // Initialize the head of the list to NULL

    // Add some courses
    addCourse(&head, 101, "Mathematics", 3);
    addCourse(&head, 102, "Physics", 4);
    addCourse(&head, 103, "Chemistry", 3);

    // Display all courses
    printf("All courses:\n");
    displayAllCourses(head);

    // Search for a course by code
    int searchCode = 102;
    Course* foundCourseByCode = searchCourseByCode(head, searchCode);
    if (foundCourseByCode != NULL) {
        printf("Course found by code %d: %s, Credits: %d\n", foundCourseByCode->courseID, foundCourseByCode->courseName, foundCourseByCode->credits);
    } else {
        printf("Course with code %d not found\n", searchCode);
    }

    // Search for a course by name
    const char* searchName = "Physics";
    Course* foundCourseByName = searchCourseByName(head, searchName);
    if (foundCourseByName != NULL) {
        printf("Course found by name '%s': ID: %d, Credits: %d\n", foundCourseByName->courseName, foundCourseByName->courseID, foundCourseByName->credits);
    } else {
        printf("Course with name '%s' not found\n", searchName);
    }

    // Delete a course
    int deleteCode = 102;
    deleteCourse(&head, deleteCode);
    printf("Course with code %d deleted.\n", deleteCode);

    // Display all courses after deletion
    printf("All courses after deletion:\n");
    displayAllCourses(head);

    // Free the allocated memory
    freeCourses(head);

    return 0;
}
