#include <stdlib.h>
#include "course.h"

void freeCourses(Course* head) {
    Course* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
