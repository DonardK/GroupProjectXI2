#include <stdio.h>
#include "displayAllCourses.h"

// Function to print the list of courses
void displayAllCourses(Course* head) {
    Course* current = head;
    while (current != NULL) {
        printf("Course ID: %d, Name: %s, Credits: %d\n", current->courseID, current->courseName, current->credits);
        current = current->next;
    }
}
