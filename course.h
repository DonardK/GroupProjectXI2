#ifndef COURSE_H
#define COURSE_H

// Define the structure for storing course information
typedef struct Course {
    int courseID;
    char courseName[100];
    int credits;
    struct Course* next;
} Course;

// Common function declarations
void addCourse(Course** head, int courseID, const char* courseName, int credits);
void printCourses(Course* head);
void freeCourses(Course* head);  // Add this line

#endif // COURSE_H
