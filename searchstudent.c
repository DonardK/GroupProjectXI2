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
} StudentList;

// Function to search for a student by ID
Student* searchStudentByID(StudentList* list, int id) {
    for (int i = 0; i < list->count; i++) {
        if (list->students[i].id == id) {
            return &list->students[i];
        }
    }
    return NULL; // Return NULL if the student is not found
}

// Function to search for a student by name
Student* searchStudentByName(StudentList* list, const char* name) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->students[i].name, name) == 0) {
            return &list->students[i];
        }
    }
    return NULL; // Return NULL if the student is not found
}

// Test the search functions
int main() {
    StudentList list;
    list.students = (Student*)malloc(3 * sizeof(Student));
    list.count = 3;
    list.capacity = 3;

    // Add some students to the list
    list.students[0] = (Student){1, "Alice", 20};
    list.students[1] = (Student){2, "Bob", 21};
    list.students[2] = (Student){3, "Charlie", 22};

    // Search for a student by ID
    int searchID = 2;
    Student* studentByID = searchStudentByID(&list, searchID);
    if (studentByID != NULL) {
        printf("Found student by ID %d: %s, %d years old\n", studentByID->id, studentByID->name, studentByID->age);
    } else {
        printf("Student with ID %d not found\n", searchID);
    }

    // Search for a student by name
    const char* searchName = "Charlie";
    Student* studentByName = searchStudentByName(&list, searchName);
    if (studentByName != NULL) {
        printf("Found student by name %s: %d, %d years old\n", studentByName->name, studentByName->id, studentByName->age);
    } else {
        printf("Student with name %s not found\n", searchName);
    }

    // Free the allocated memory for the students array
    free(list.students);

    return 0;
}
