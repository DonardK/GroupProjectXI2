#include <stdio.h>
#include <stdlib.h>
#include "deleteCourse.h"

void deleteCourse(Course** head, int courseID) {
    Course* temp = *head;
    Course* prev = NULL;

    if (temp != NULL && temp->courseID == courseID) {
        *head = temp->next;
        free(temp);
        printf("Course deleted successfully\n");
        return;
    }

    while (temp != NULL && temp->courseID != courseID) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Course with ID %d not found\n", courseID);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Course deleted successfully\n");
}
