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
void deleteCourse(Course** head, int courseID);
Course* searchCourseByCode(Course* head, int courseID);
Course* searchCourseByName(Course* head, const char* courseName);
void displayAllCourses(Course* head);
void freeCourses(Course* head);

#endif // COURSE_H
