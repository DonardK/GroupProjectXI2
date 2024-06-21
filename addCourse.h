#ifndef COURSE_MANAGEMENT_H
#define COURSE_MANAGEMENT_H

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
