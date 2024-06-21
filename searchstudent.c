#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a student
typedef struct Student {
    int id;
    char name[100];
    int age;
} Student;

// Define the structure for a list of students
typedef struct StudentList {
    Student* students;
    int count;
    int capacity;
} StudentList

// Function to search for a student by ID
Student* searchStudentByID(StudentList* list, int id) {
    for (int i = 0; i < list->count; i++) {
        if (list->students[i].id == id) {
            return &list->students[i];
        }



// Add some students to the list
    list.students[0] = (Student){1, "Alice", 20};
    list.students[1] = (Student){2, "Bob", 21};
    list.students[2] = (Student){3, "Charlie", 22};
