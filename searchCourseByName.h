#ifndef SEARCH_COURSE_BY_NAME_H
#define SEARCH_COURSE_BY_NAME_H

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
Course* searchCourseByName(Course* head, const char* courseName);
void printCourses(Course* head);
void freeCourses(Course* head);

#endif // SEARCH_COURSE_BY_NAME_H
