#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "addCourse.h"

// Function to add a course
void addCourse(Course** head, const char* courseID, const char* courseName, int credits) {
    Course* newCourse = (Course*)malloc(sizeof(Course));
    if (newCourse == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    strncpy(newCourse->courseID, courseID, sizeof(newCourse->courseID) - 1);
    newCourse->courseID[sizeof(newCourse->courseID) - 1] = '\0';
    strncpy(newCourse->courseName, courseName, sizeof(newCourse->courseName) - 1);
    newCourse->courseName[sizeof(newCourse->courseName) - 1] = '\0';
    newCourse->credits = credits;
    newCourse->next = *head;
    *head = newCourse;
    printf("Course added successfully with ID: %s\n", newCourse->courseID);
}
