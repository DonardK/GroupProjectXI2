#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "searchCourseByCode.h"

Course* searchCourseByCode(Course* head, const char* courseID) {
    Course* current = head;
    while (current != NULL) {
        if (strcmp(current->courseID, courseID) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL; // Course not found
}
