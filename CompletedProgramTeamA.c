#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
    int nextID; // Next available student ID
} StudentList;

// Function to initialize the StudentList
void initStudentList(StudentList* list, int capacity) {
    list->students = (Student*)malloc(capacity * sizeof(Student)); // Allocate memory for students
    list->count = 0;                                               // Initialize student count to 0
    list->capacity = capacity;                                     // Set the initial capacity
    list->nextID = 1;                                              // Start student IDs from 1
}

// Function to save all student details to a file
void saveStudentsToFile(const StudentList* list) {
    FILE* file = fopen("studentsvalue.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < list->count; i++) {
        fprintf(file, "%d,%s,%d\n", list->students[i].id, list->students[i].name, list->students[i].age);
    }

    fclose(file);
}

// Function to add a student to the list
void addStudent(StudentList* list, const char* name, int age) {
    // Check if we need to resize the array
    if (list->count == list->capacity) {
        list->capacity *= 2;
        list->students = (Student*)realloc(list->students, list->capacity * sizeof(Student)); // Reallocate memory
    }

    // Add the new student's details to the array
    list->students[list->count].id = list->nextID++; // Assign the next available ID and increment it
    strcpy(list->students[list->count].name, name); // Copy the name to the student's name field
    list->students[list->count].age = age;
    list->count++; // Increment the count of students

    // Save students to file
    saveStudentsToFile(list);
}

// Function to delete a student by ID
void deleteStudent(StudentList* list, int id) {
    int found = 0;
    for (int i = 0; i < list->count; i++) {
        if (list->students[i].id == id) {
            found = 1;
            // Shift the remaining students
            for (int j = i; j < list->count - 1; j++) {
                list->students[j] = list->students[j + 1];
            }
            list->count--;
            break;
        }
    }

    if (found) {
        // Reallocate memory to shrink the array if necessary
        if (list->count > 0) {
            list->students = (Student*)realloc(list->students, list->count * sizeof(Student));
        } else {
            free(list->students);
            list->students = NULL;
        }

        // Save students to file
        saveStudentsToFile(list);
    } else {
        printf("Student with ID %d not found.\n", id);
    }
}

// Function to display all student details
void displayAllStudents(const StudentList* list) {
    printf("Student List:\n");
    printf("ID\tName\t\tAge\n");
    printf("-----------------------------\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d\t%-15s\t%d\n", list->students[i].id, list->students[i].name, list->students[i].age);
    }
}

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

// Function to get a valid integer input
int getValidInt(const char* prompt) {
    char input[100];
    int value;

    while (1) {
        printf("%s", prompt);
        fgets(input, sizeof(input), stdin);

        // Check if input is a valid number
        int valid = 1;
        for (int i = 0; i < strlen(input) - 1; i++) { // Subtract 1 to ignore the newline character
            if (!isdigit(input[i])) {
                valid = 0;
                break;
            }
        }

        if (valid) {
            value = atoi(input);
            break;
        } else {
            printf("Invalid input. Please enter a valid number.\n");
        }
    }

    return value;
}

// Function to get a valid name input
void getValidName(char* name, const char* prompt) {
    char input[100];

    while (1) {
        printf("%s", prompt);
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0'; // Remove the newline character

        // Check if input contains only letters
        int valid = 1;
        for (int i = 0; i < strlen(input); i++) {
            if (!isalpha(input[i])) {
                valid = 0;
                break;
            }
        }

        if (valid) {
            strcpy(name, input);
            break;
        } else {
            printf("Invalid input. Please enter a name with letters only.\n");
        }
    }
}

// Main function to demonstrate the student list functionalities
int main() {
    StudentList list; // Declare a StudentList
    initStudentList(&list, 2); // Initialize the list with a capacity of 2

    int choice, age;
    char name[100];

    while (1) {
        // Display the menu
        printf("\nMenu:\n");
        printf("1. Add Student\n");
        printf("2. Delete Student\n");
        printf("3. Display All Students\n");
        printf("4. Search Student by ID\n");
        printf("5. Search Student by Name\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        choice = getValidInt("");

        switch (choice) {
            case 1: {
                // Get student details
                getValidName(name, "Enter student name: ");
                age = getValidInt("Enter student age: ");
                // Add student to the list
                addStudent(&list, name, age);
                break;
            }
            case 2: {
                // Get student ID to delete
                int idToDelete = getValidInt("Enter student ID to delete: ");
                // Delete student from the list
                deleteStudent(&list, idToDelete);
                break;
            }
            case 3:
                // Display all students
                displayAllStudents(&list);
                break;
            case 4: {
                // Get student ID to search
                int idToSearch = getValidInt("Enter student ID to search: ");
                Student* studentByID = searchStudentByID(&list, idToSearch);
                // Display search result
                if (studentByID != NULL) {
                    printf("Found student by ID %d: %s, %d years old\n", studentByID->id, studentByID->name, studentByID->age);
                } else {
                    printf("Student with ID %d not found\n", idToSearch);
                }
                break;
            }
            case 5: {
                // Get student name to search
                getValidName(name, "Enter student name to search: ");
                Student* studentByName = searchStudentByName(&list, name);
                // Display search result
                if (studentByName != NULL) {
                    printf("Found student by name %s: %d, %d years old\n", studentByName->name, studentByName->id, studentByName->age);
                } else {
                    printf("Student with name %s not found\n", name);
                }
                break;
            }
            case 6:
                // Free allocated memory and exit
                free(list.students);
                return 0;
            default:
                // Handle invalid menu choice
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0; // Return 0 to indicate successful execution
}