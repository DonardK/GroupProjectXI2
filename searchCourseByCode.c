#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure to store course information
typedef struct Course {
    char courseName[50];
    char courseID[10]; // Changed courseID to string
    struct Course* next;
} Course;

// Function to add course details
Course* addCourse(Course* head, const char* courseName, const char* courseID) {
    // Allocate memory for the new course
    Course* newCourse = (Course*)malloc(sizeof(Course));
    if (newCourse == NULL) {
        printf("Memory allocation failed\n");
        return head;
    }

    // Set the course details
    strcpy(newCourse->courseName, courseName);
    strcpy(newCourse->courseID, courseID);
    newCourse->next = head; // Insert at the beginning of the list

    return newCourse;
}

// Function to search for a course by its code (ID)
Course* searchCourseByCode(Course* head, const char* courseID) {
    Course* current = head;
    while (current != NULL) {
        if (strcmp(current->courseID, courseID) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL; // Return NULL if course is not found
}

// Function to clear input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
