#ifndef ADD_COURSE_H
#define ADD_COURSE_H

#include "course.h"

// Define the structure for storing course information
typedef struct Course {
    int courseID;
    char courseName[100];
    int credits;
    struct Course* next;
} Course;

// Function declarations
void addCourse(Course** head, int courseID, const char* courseName, int credits);
void printCourses(Course* head);
void freeCourses(Course* head);

#endif // COURSE_MANAGEMENT_H
