#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for storing course information
typedef struct Course {
    int courseID;
    char courseName[100];
    int credits;
    struct Course* next;
} Course;

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

// Function to search for a course by its name
Course* searchCourseByName(Course* head, const char* courseName) {
    Course* current = head;
    while (current != NULL) {
        if (strcmp(current->courseName, courseName) == 0) {
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

int main() {
    Course* head = NULL; // Initialize the head of the list to NULL
    
    // Add some courses
    addCourse(&head, 101, "Mathematics", 3);
    addCourse(&head, 102, "Physics", 4);
    addCourse(&head, 103, "Chemistry", 3);
    
    // Print the courses to verify they are added
    printCourses(head);
    
    // Search for a course by its code
    int searchCode = 102;
    Course* foundCourse = searchCourseByCode(head, searchCode);
    if (foundCourse != NULL) {
        printf("Course found by code %d: %s, Credits: %d\n", foundCourse->courseID, foundCourse->courseName, foundCourse->credits);
    } else {
        printf("Course with code %d not found\n", searchCode);
    }
    
    // Search for a course by its name
    const char* searchName = "Chemistry";
    foundCourse = searchCourseByName(head, searchName);
    if (foundCourse != NULL) {
        printf("Course found by name '%s': ID: %d, Credits: %d\n", foundCourse->courseName, foundCourse->courseID, foundCourse->credits);
    } else {
        printf("Course with name '%s' not found\n", searchName);
    }
    
    // Free the allocated memory
    freeCourses(head);
    
    return 0;
}
