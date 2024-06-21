#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "addCourse.h"

// Function to add a course
void addCourse(Course** head, int courseID, const char* courseName, int credits) {
    // Allocate memory for the new course
    Course* newCourse = (Course*)malloc(sizeof(Course));
    if (newCourse == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    
    // Initialize the new course
    newCourse->courseID = courseID;
    strncpy(newCourse->courseName, courseName, sizeof(newCourse->courseName) - 1);
    newCourse->courseName[sizeof(newCourse->courseName) - 1] = '\0';
    newCourse->credits = credits;
    newCourse->next = *head;
    
    // Insert the new course at the beginning of the list
    *head = newCourse;
    
    printf("Course added successfully\n");
}
