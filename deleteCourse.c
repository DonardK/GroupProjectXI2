#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deleteCourse.h"

void deleteCourse(Course** head, const char* courseID) {
    Course* temp = *head;
    Course* prev = NULL;

    if (temp != NULL && strcmp(temp->courseID, courseID) == 0) {
        *head = temp->next;
        free(temp);
        printf("Course deleted successfully\n");
        return;
    }

    while (temp != NULL && strcmp(temp->courseID, courseID) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Course with ID %s not found\n", courseID);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Course deleted successfully\n");
}
