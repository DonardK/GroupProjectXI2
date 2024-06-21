#include <stdlib.h>
#include "course.h"

// Function to free the memory allocated for the courses
void freeCourses(Course* head) {
    Course* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
