#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "searchCourseByCode.h"

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

// Function to search for a course by its code
Course* searchCourseByCode(Course* head, int courseID) {
    Course* current = head;
    while (current != NULL) {
        if (current->courseID == courseID) {
            return current;
        }
        current = current->next;
    }
    return NULL; // Course not found
}

// Function to print the list of courses (for testing purposes)
void printCourses(Course* head) {
    Course* current = head;
    while (current != NULL) {
        printf("Course ID: %d, Name: %s, Credits: %d\n", current->courseID, current->courseName, current->credits);
        current = current->next;
    }
}

// Function to free the memory of the list (to avoid memory leaks)
void freeCourses(Course* head) {
    Course* current = head;
    Course* nextCourse;
    while (current != NULL) {
        nextCourse = current->next;
        free(current);
        current = nextCourse;
    }
}
