#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int age;
    int marks;
};

void inputDetails(struct Student students[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Age: ");
        scanf("%d", &students[i].age);
        printf("Marks: ");
        scanf("%d", &students[i].marks);
    }
}

void displayDetails(struct Student students[], int n) {
    printf("\nStudent Details:\n");
    for (int i = 0; i < n; i++) {
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age); // Corrected this line
        printf("Marks: %d\n\n", students[i].marks);
    }
}

void sortStudents(struct Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].marks < students[j + 1].marks) {
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

struct Student findTopStudent(struct Student students[], int n) {
    struct Student topStudent = students[0];
    for (int i = 1; i < n; i++) {
        if (students[i].marks > topStudent.marks) {
            topStudent = students[i];
        }
    }
    return topStudent;
}

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student students[n];

    inputDetails(students, n);
    displayDetails(students, n);

    sortStudents(students, n);

    printf("\nStudents sorted by marks (descending order):\n");
    displayDetails(students, n);

    struct Student topStudent = findTopStudent(students, n);
    printf("\nTop Student:\n");
    printf("Name: %s\n", topStudent.name);
    printf("Age: %d\n", topStudent.age);
    printf("Marks: %d\n", topStudent.marks);

    return 0;
}