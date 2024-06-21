#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deleteCourse.h"

// Function to delete a course
void deleteCourse(Course** head, int courseID) {
    Course* temp = *head, *prev = NULL;
    
    // If head node itself holds the courseID to be deleted
    if (temp != NULL && temp->courseID == courseID) {
        *head = temp->next; // Changed head
        free(temp); // Free old head
        return;
    }
    
    // Search for the courseID to be deleted, keep track of the previous node
    while (temp != NULL && temp->courseID != courseID) {
        prev = temp;
        temp = temp->next;
    }
    
    // If courseID was not present in list
    if (temp == NULL) return;
    
    // Unlink the node from linked list
    prev->next = temp->next;
    
    free(temp); // Free memory
}
