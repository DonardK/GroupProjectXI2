#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "searchCourseByName.h"

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
