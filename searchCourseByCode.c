#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "searchCourseByCode.h"

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
