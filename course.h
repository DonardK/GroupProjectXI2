#ifndef COURSE_H
#define COURSE_H

// Define the structure for storing course information
typedef struct Course {
    char courseID[20]; // Change to string to accommodate IDs like "CS101"
    char courseName[100];
    int credits;
    struct Course* next;
} Course;

// Common function declarations
void addCourse(Course** head, const char* courseID, const char* courseName, int credits);
void deleteCourse(Course** head, const char* courseID);
Course* searchCourseByCode(Course* head, const char* courseID);
Course* searchCourseByName(Course* head, const char* courseName);
void displayAllCourses(Course* head);
void freeCourses(Course* head);

#endif // COURSE_H
